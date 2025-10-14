#pragma once
#include <vector>
#include <string>

using namespace std;

//build the graph first (in_matrix adj)
vector<vector<double>>build_tx_mat(int &numpages);

//build the google_matrix
vector<vector<double>>google_mat(vector<vector<double>> &M, double damping);

//build the pagerank matrix
vector<double> computePageRank(vector<vector<int>> &G, double tolerance, int iters);

//save results in csv