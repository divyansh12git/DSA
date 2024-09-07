#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

unordered_map<int,list<pair<int,int>>> createGraph(){
    unordered_map<int,list<pair<int,int>>>graph;
    graph[1].push_back({2,5});
    graph[1].push_back({4,10});
    graph[2].push_back({4,3});
    graph[2].push_back({3,4});
    graph[3].push_back({4,1});
   return graph;
}
vector<int> shortestpathinUndirectedGraph(int s,int e, unordered_map<int,list<int>>& graph){
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    visited[s]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto i:graph[f]){
            if(!visited[i]){
                parent[i]=f;
                q.push(i);
                visited[i]=1;
            }
        }
    }
    vector<int>ans;
    int curr=e;
    ans.push_back(curr);
    while(curr!=s){
        curr=parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void topologicalSort(int s,unordered_map<int,list<pair<int,int>>>&graph,stack<int>&st,unordered_map<int,bool>&visited){
    visited[s]=1;
    for(auto i:graph[s]){
        if(!visited[i.first]){
            topologicalSort(i.first,graph,st,visited);
        }
    }
    st.push(s);
}
vector<int> createShortestPath(int src,stack<int>st,unordered_map<int,list<pair<int,int>>>&graph,vector<int>&dist){
    dist[src]=0;
    while(!st.empty()){
        int t=st.top();
        st.pop();
        if(dist[t]!=1e9){
            for(auto i:graph[t]){
                if(dist[t]+i.second<dist[i.first]){
                    dist[i.first]=dist[t]+i.second;
                }
            }
        }
    }
}
vector<int>ShortestPathInDirectedAcyclicGraph(int src,int v,unordered_map<int,list<pair<int,int>>>&graph){
    stack<int>st;
    unordered_map<int,bool>visited;
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            topologicalSort(i,graph,st,visited);
        }
    }
    vector<int>dist(v+1,1e9);
    createShortestPath(src,st,graph,dist);
    for (int i = 0; i < v; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
    return dist;
}

int main(){
    unordered_map<int,list<pair<int,int>>>graph=createGraph();
    stack<int>st;
    unordered_map<int,bool>visited;
    topologicalSort(1,graph,st,visited);
    vector<int>ans;
    while(!st.empty()){
        int t=st.top();
        st.pop();
        ans.push_back(t);
    }
    vector<int>dis=ShortestPathInDirectedAcyclicGraph(1,4,graph);
    for(auto i:dis)cout<<i<<" ";cout<<endl;
}