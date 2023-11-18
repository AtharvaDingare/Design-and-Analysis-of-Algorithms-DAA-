#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    vector<int>distance(n+1, -1); //  -1 indicates that we have not visited that edge yet , otherwise it will be equal to the shortest distance yet required to visit it.
    int source = 1;
    distance[0] = 0;
    distance[source] = 0; // source = 0

    bool infinite = 0; // checks whether there is a negative cycle in the graph

    for(int i=1; i<=(m); i++){
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0], v = edges[j][1], wt = edges[j][2];
            if(distance[u] == -1){
                if(i == n){
                    infinite = true; break;
                }
                continue; // not visited u yet , so no point
            }
            else{
                int gotov = distance[u] + wt;
                if((gotov < distance[v]) || (distance[v] == -1)){
                    if(i == n){
                        infinite = true; break;
                    }
                    distance[v] = gotov;
                }
            }
        }
    }

    if(infinite) {
        cout<<"Negative cycle detected !"<<endl;
    }
    else{
        for(int i=1; i<=n; i++){
            cout<<"Distance of "<<i<<" from 1 is : "<<distance[i]<<endl;
        }
    }

    return 0;
}