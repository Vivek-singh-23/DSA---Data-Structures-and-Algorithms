 #include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int src){
    // create adjaceny list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }


    vector<int> distance(vertices, INT_MAX);

    set<pair<int, int>>st;

    distance[src] = 0;
    st.insert(make_pair(0, src));

    while(!st.empty()){
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour:adj[topNode]){
            if(nodeDistance + neighbour.second < distance[neighbour.first]){

                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));

                if(record != st.end()){
                    st.erase(record);
                }

                distance[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }

    }

    return distance;
}   


int main(){

}