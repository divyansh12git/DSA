#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void kahnAlgorithm(int node,int v,unordered_map<int, list<int>>adj,vector<int> &ans){
    int indegree[v];
    //finding indegree of every node
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        //atoring in ans
        ans.push_back(fr);
        for(auto nei:adj[fr]){
            indegree[nei]--;
            if(indegree[nei]==0){
                q.push(nei);
            }
            
        }
    }
}



int main(){

}