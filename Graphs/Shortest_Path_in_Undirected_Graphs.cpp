#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>>edges, int n, int m, int src, int target){
    // cerate adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i]. first;
        int v = edges[i]. second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<bool> visited;
    vector<int> parent;
    queue<int>q;

    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();


        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;  
            }
        }
    }


    int curr = target;
    vector<int>ans;
    ans.push_back(target);
    
    while(curr != src){
        curr = parent[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

int main(){

}