 #include<iostream>
 using namespace std;
#include<bits/stdc++.h>

void topologicalSort(int node, unordered_map<int,list<int>> adj,unordered_map<int, bool> vis,stack<int>& ans){
    vis[node]=true;
    for(auto i:adj[node]){
        if(!vis[i]){
            topologicalSort(i,adj,vis,ans); 
        }
    }
    ans.push(node);
}


 int main(){

 }