#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &st,
    unordered_map<int, list<int>> &adjList) {

    visited[node] = true;

    for(int neigh : adjList[node]) {
        if(visited[neigh] == false) {
            topoSort(neigh, visited, st, adjList);
        }
    }

    st.push(node);
}

void revDFS(int node, vector<bool> &visited, unordered_map<int, list<int>> &transpose) {
    visited[node] = true;
    
    for(int neigh : transpose[node]) {
        if(visited[neigh] == false) {
            revDFS(neigh, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(vector<vector<int>> &edges, int n, int m) {
    // Create adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // Topoplogical Sort
    stack<int> st;
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; i++) {
        if(visited[i] == false) {
            topoSort(i, visited, st, adjList);
        }
    }

    // Transpose Graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<n; i++) {
        visited[i] = false;
        for(int neigh : adjList[i]) {
            transpose[neigh].push_back(i);
        }
    }

    // DFS call on topological sort
    int count = 0;
    while(!st.empty()) {
        int top = st.top();
        st.pop();

        if(visited[top] == false) {
            count++;
            revDFS(top, visited, transpose);
        }
    }

    return count;
}



