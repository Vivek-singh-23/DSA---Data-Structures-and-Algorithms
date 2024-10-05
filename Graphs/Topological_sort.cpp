// applicable only in Directed acyclic graph
#include<bits/stdc++.h>
using namespace std;


void topologicalSortUtil(int node, vector<bool> visited, stack<int> s, unordered_map<int, list<int>> adj){
    visited[node] = true;

    for(auto i:adj[node]){
        if(!visited[i]){
            topologicalSortUtil(i, visited, s, adj);
        }
    }

    s.push(node);
    return;
}

vector<int> topologicalSort(vector<vector<int>>&edges, int v, int e){
    // create adj list
    
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited;
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topologicalSortUtil(i, visited, s, adj);
        }
    }


    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

}

int main(){

}