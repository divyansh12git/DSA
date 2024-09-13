#include<bits/stdc++.h>
using namespace std;
void TopologicalSort(int s,vector<int>&vis,vector<int>graph[],stack<int>&st ){
    vis[s]=1;
    for(auto i:graph[s]){
        if(!vis[i]){
            TopologicalSort(i,vis,graph,st);
        }
    }
    st.push(s);
}

void revDFS(int s,vector<int>graph[],vector<int>&vis){
    vis[s]=1;
    for(auto i:graph[s]){
        if(!vis[i]){
            revDFS(i,graph,vis);
        }
    }
}
int KosaRajuAlgorithm(int v,vector<int>graph[]){
    stack<int>topo;
    vector<int>vis(v+1);
    //getting topological sort
    for(int i=0;i<v;i++){
        if(!vis[i]){
            TopologicalSort(i,vis,graph,topo);
        }
    }
    //reversing the graph
    vector<int>revGraph[v];
    for(int i=0;i<v;i++){
        for(auto j:graph[i]){
            revGraph[j].push_back(i);
        }
    }
    //dfs to get components
    vis.resize(v+1,0);
    int count=0;
    while(!topo.empty()){
        int f=topo.top();
        topo.pop();
        if(!vis[f]){
            count++;
            revDFS(f,revGraph,vis);
        }
    }
    return count;


}

int main(){

}