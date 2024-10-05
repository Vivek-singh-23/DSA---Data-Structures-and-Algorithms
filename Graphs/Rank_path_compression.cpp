// we can use concept of disjoint set to find wether two node belong to same component or graph
// disjoint set also can be used to detect cycles in a graph

#include<bits/stdc++.h>
using namespace std;


bool cmp(vector<int>&a, vector<int> &b){
    return a[2] < b[2];
}


void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;    
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);

}

void unionSet(int u, int v, vector<int> &parent, vector<int>& rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{

        // also can be used in this case only
        // parent[u] = v;
        // rank[v]++;
        parent[v] = u;
        rank[u]++;
    }
}

int minSpanningTree(vector<vector<int>> &edges, int n){
    
    // sorting edges vector based on weights
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v){
            minWeight += n;
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}

int main(){

}