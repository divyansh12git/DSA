#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

void convertToAdjacencyList(vector<pair<int,int>> graph,unordered_map<int,list<int>>& adj){
    for(auto i: graph){
        int u=i.first;
        int v=i.second;

        //insert to map
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void bfs(int s, vector<int>& ans,unordered_map<int,bool> vis,unordered_map<int,list<int>>&adj){
    queue<int> q;
    q.push(s);
    vis[s]=true;

    while(!q.empty()){
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto i:adj[front]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}
void dfs(int s,vector<int> &component, unordered_map<int,list<int>> adj,unordered_map<int,bool>vis){
    component.push_back(s);
    vis[s]=true;
    for(auto i:adj[s]){
        if(!vis[i]){
            dfs(i,component,adj,vis);
        }
    }

}


int main(){

unordered_map<int,list<int>> adj;

/* for(int i=0;i<vertex;i++){
    if(!visited[i]){
        bfs()
    }    
} */


};