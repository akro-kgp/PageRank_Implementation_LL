#include <bits/stdc++.h>
#include "C:\Users\arkak\OneDrive - iitkgp.ac.in\Desktop\PAGE_RANK\includes\matrixhelpers.h"
#include "C:\Users\arkak\OneDrive - iitkgp.ac.in\Desktop\PAGE_RANK\includes\pagerank.h"
using namespace std;


vector<vector<double>> build_tx_mat(int &numpages, int &links){
    vector<vector<double>> res;
    res.resize(numpages,vector<double>(numpages,0.0));
    for(int i=0;i<links;i++){
        int u,v;
        cin>>u>>v;
        res[v-1][u-1]=1.0;
    }
    return res;
}

vector<vector<double>> google_mat(vector<vector<double>> &M,double damping){
    vector<vector<double>> G;
    int rows=M.size();
    int cols=M[0].size();
    G.resize(rows,vector<double>(cols,0.0));

    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            G[i][j]=(damping*M[i][j])+((1-damping)/rows);
        }
    }
    return G;
}


vector<double> computePageRank(vector<vector<double>> &G, double tolerance, int iters){
    int rows=G.size();
    vector<double> guess;
    for(int i=0;i<rows;i++){
        guess.push_back(1.0/rows);
    }
    //now do power iterations
    for(int i=0;i<iters;i++){
        vector<double> temp;
        temp=matVec(G,guess);
        //do over-relaxation
        double sum=0;
        for(auto k:temp) sum+=k;
        for(auto &k:temp) k/=sum;  // iterative referencing
        if(L1_norm(guess,temp)<tolerance) break;
        guess=temp;
    }

    return guess;
}


