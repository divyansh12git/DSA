#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

bool cycleDetectioninUndirectedGraphusingBFS(int node,unordered_map<int,list<int>>&graph,unordered_map<int,int>parent, unordered_map<int,bool>&visited){
    queue<int>q;
    parent[node]=-1;
    visited[node]=1;
    q.push(node);
    while(!q.empty()){
        int f=q.front();
        
        q.pop();
        for(auto i:graph[f]){
            if(visited[i] && parent[f]!=i){
                return true;
            }
            if(!visited[i]){
                q.push(i);
                parent[i]=f;visited[i]=1;
            }
        }
    }
}
bool cycleDetectioninUndirectedGraphusingDFS(int node, unordered_map<int,list<int>>& graph, unordered_map<int,bool>&visited,int p){
    visited[node]=1;
    for(auto i:graph[node]){
        if(!visited[i]){
            bool a=cycleDetectioninUndirectedGraphusingDFS(i,graph,visited,node);
            if(a)return true;
        }else if (i!=p){
            return false;
        }
        
    }
    return false;
}

bool cycleDetectioninDirectedGraphusingDFS(int node,unordered_map<int,list<int>>&graph, unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsVisited ){
    visited[node]=1;
    dfsVisited[node]=1;
    for(auto i:graph[node]){
        if(!visited[i]){
            if(cycleDetectioninDirectedGraphusingDFS(i,graph,visited,dfsVisited))return true;
        }
        else if(dfsVisited[i]){
            return false;
        }
    }
    dfsVisited[node]=0;
    return 0;
}
int main(){
    
}

