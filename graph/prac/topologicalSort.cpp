#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void topologicalSort(int node,unordered_map<int,list<int>>&graph, unordered_map<int,bool>&visited,stack<int>&ans){
    visited[node]=1;
    for(auto i:graph[node]){
        if(!visited[i]){
            topologicalSort(i,graph,visited,ans);
        }
    }
    ans.push(node);// stored in stack pop to get answer(reverse order)...
    
}
void khanAlgorithm(map<int,list<int>>&graph){
    vector<int>indegree(graph.size(),0);
    for(pair<int,list<int>> i:graph){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        ans.push_back(f);
        for(auto i:graph[f]){
            indegree[i]--;
            if(indegree[i]==0)q.push(i);
        }
    }
}


int main(){

}