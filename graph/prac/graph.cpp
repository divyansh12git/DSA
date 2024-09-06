#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void prepareAdjList(vector<vector<int>>vec,map<int,list<int>>&adj){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            if(vec[i][j]==1){
                int u=i;
                int v=j;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
}
void preparefrompair(vector<pair<int,int>>&v,map<int,list<int>>& adj){
    for(int i=0;i<v.size();i++){
        int u=v[i].first;
        int x=v[i].second;
        adj[u].push_back(x);
        adj[x].push_back(u);
    }
}

void bfs(int s,map<int,list<int>>&adj, vector<int>&ans, unordered_map<int,bool>visited){
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
void dfs(int node,map<int,list<int>>&adj,vector<int>&ans,map<int,bool>visited){
    ans.push_back(node);
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,adj,ans,visited);
        }
    }
}

int main(){
    
}