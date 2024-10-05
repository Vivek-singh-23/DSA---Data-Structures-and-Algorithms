// used to find minimum spanning tree

#include<bits/stdc++.h>
using namespace std;


vector<pair<pair<int, int>, int>>Prims(int n, int m, vector<pair<pair<int, int>, int>>g){
    // creating adj list

    unordered_map<int, list<pair<int, int>>>adj;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;

        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int>key(n+1); //leaving space for 0;
    vector<bool>mst(n+1);
    vector<int>parent(n+1);

    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    
    // assuming key node to be 1
    key[1] = 0;
    parent[1] = -1;


    for(int i=1; i<=n; i++){
        int mini = INT_MAX;
        int u;

        // find minimum value

        // can be optimized using priority queue
        for(int j=1; j<=n; j++){
            if(mst[j] == false && key[j] < mini){
                u = j;
                mini = key[j]; 
            }
        }

        // mark mini as true
        mst[u] = true;

        // check for adjacent nodes
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }

        
   }

   vector<pair<pair<int, int>, int>> ans;
        for(int i=2; i<=n; i++){
            ans.push_back({{parent[i], i}, key[i]});
        }
    
   return ans;   
    
}

int main(){

}

