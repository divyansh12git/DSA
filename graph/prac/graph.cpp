#include<iostream>
#include <list>
#include <unordered_map>
using namespace std;


void dfs(unordered_map<int,list<int>>adj,int s,unordered_map<int,bool>&visited,vector<int>ans){
    ans.push_back(s);
    visited[s]=true;
    for(auto nei:adj[s]){
        if(!visited[nei]){
            dfs(adj,nei,visited,ans);
        }
    }
}



int main(){

}