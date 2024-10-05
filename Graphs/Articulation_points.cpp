#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, 
             vector<int> &low, vector<bool> &visited, vector<int> adj[], vector<int> &ans) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        
        int child = 0;
        
        for (auto neigh : adj[node]) {
            if (neigh == parent) {
                continue;
            }
            
            if (!visited[neigh]) {
                dfs(neigh, node, timer, disc, low, visited, adj, ans);
                low[node] = min(low[node], low[neigh]);
                
                if (low[neigh] >= disc[node] && parent != -1) {
                    if (find(ans.begin(), ans.end(), node) == ans.end()) {
                        ans.push_back(node);
                    }
                }
                
                child++;
            } else {
                low[node] = min(low[node], disc[neigh]);
            }
        }
        
        if (parent == -1 && child > 1) {
            if (find(ans.begin(), ans.end(), node) == ans.end()) {
                ans.push_back(node);
            }
        } 
    }
  
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        int timer = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> visited(V, false);
        vector<int> ans;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, timer, disc, low, visited, adj, ans);
            }
        }
        
        if (ans.empty()) {
            return {-1};
        }
        
        sort(ans.begin(), ans.end()); // Optional: To return articulation points in sorted order
        return ans;
    }
};
