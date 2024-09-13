#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int n,int m,int dest,int src,vector<vector<int>>&edges){
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]!=1e9 && dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
            }
        }
    }
    int f=0;
    for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]!=1e9 && dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
                f=1;
            }
    }
    if(f)return -1;
    return dist[dest];
}

int main(){

}