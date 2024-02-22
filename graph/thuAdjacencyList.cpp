#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
        unordered_map<int,list<int>> adj;
        void insertEdge(int u,int v, int direction){
            adj[u].push_back(v);
            //1 for directed
            if(!direction){
                adj[v].push_back(u);
            }
        }
        void printGraph(){
            for(auto i:adj){
                cout<<i.first<<"-->";
                for(auto j:i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};


int main(){
    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;
    int m,u,v;
    graph g;
    cout<<"enter the no. of edges"<<endl;
    cin>>m;

    for(int i=0;i<m;i++){
        cin>>u>>v;
        g.insertEdge(u,v,1);
    }
    g.printGraph();
}
