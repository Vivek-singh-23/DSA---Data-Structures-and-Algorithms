// directed graph
#include<bits/stdc++.h>
using namespace std;


bool isCyclePresent(int node, vector<bool> &visited, vector<bool> &dfsVisited, unordered_map<int, list<int>> &adjList){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto i:adjList[node]){
        if(!visited[i]){
            bool ans = isCyclePresent(i, visited, dfsVisited, adjList);
            if(ans){
                return true;
            }
        }else if(dfsVisited[i]){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}


bool detectCycle(int n, vector<pair<int, int>> edges){
    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    vector<bool> visited;
    vector<bool> dfsVisited;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool ans = isCyclePresent(i, visited, dfsVisited, adjList);
            if(ans){
                return true;
            }
        }
    }

    return false;
}

int main(){
    
}