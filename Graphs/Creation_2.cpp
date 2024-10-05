// creating a graph using template

#include<bits/stdc++.h>
using namespace std;


template <typename T>
class graph{
    public:
        unordered_map<T, list<T>> adj;

        void addEdge(T u,T v, bool direction){
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            adj[u].push_back(v);

            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adj){
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
    cout<<"Enter no of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter no of edges"<<endl;
    cin>>m;


    // can create any type of graph using template just need to define the type at time of declaration
    graph<int> g;
    // graph<char> g;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        // creating undirected graph
        g.addEdge(u, v, 0);

        g.printAdjList();
    }
}