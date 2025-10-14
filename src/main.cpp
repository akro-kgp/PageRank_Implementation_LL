#include <bits/stdc++.h>
#include "C:\Users\arkak\OneDrive - iitkgp.ac.in\Desktop\PAGE_RANK\includes\matrixhelpers.h"
#include "C:\Users\arkak\OneDrive - iitkgp.ac.in\Desktop\PAGE_RANK\includes\pagerank.h"
using namespace std;

int main() {
    int numpages, links;
    double damping = 0.85, tolerance = 1e-6;
    int iters = 100;

    cout << "Enter number of pages: ";
    cin >> numpages;

    cout << "Enter number of links: ";
    cin >> links;

    cout << "Enter " << links << " directed links as (from to):\n";
    vector<vector<double>> M = build_tx_mat(numpages, links);

    cout << "\nInitial adjacency (transition) matrix:\n";
    for (auto &row : M) {
        for (auto &x : row) cout << x << " ";
        cout << "\n";
    }

    // Normalize to build probability matrix
    build_prob_cum(M);

    cout << "\nColumn-normalized probability matrix:\n";
    for (auto &row : M) {
        for (auto &x : row) cout << fixed << setprecision(3) << x << " ";
        cout << "\n";
    }

    // Build Google matrix
    vector<vector<double>> G = google_mat(M, damping);

    cout << "\nGoogle matrix (with damping = " << damping << "):\n";
    for (auto &row : G) {
        for (auto &x : row) cout << fixed << setprecision(3) << x << " ";
        cout << "\n";
    }

    // Compute PageRank
    vector<double> ranks = computePageRank(G, tolerance, iters);

    cout << "\nFinal PageRank values after convergence:\n";
    for (int i = 0; i < ranks.size(); i++)
        cout << "Page " << i + 1 << ": " << fixed << setprecision(6) << ranks[i] << "\n";

    return 0;
}
