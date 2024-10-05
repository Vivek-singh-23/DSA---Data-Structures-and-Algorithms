#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        unordered_map<int, list<int>> adjList;
        void addEdges(int u, int v, bool direction){
            adjList[u].push_back(v);

            if(direction == 0){
                adjList[v].push_back(u);
            }
        }

        void print(){
            for(auto i:adjList){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};

int main(){
    int n;
    cout<<"Enter no of edges"<<endl;
    cin>>n;

    int m;
    cout<<"Enter no of vertices"<<endl;
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        g.addEdges(u, v, 0);
    }
}