#include<iostream>
using namespace std;
#include<unordered_map>
#include<set>
#include<list>


vector<int> Dijistra(int src,int n,unordered_map<int,list<pair<int,int>>>&adj){
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    set<pair<int,int>>st;
    st.insert({0,1});
    while(!st.empty()){
        auto r=*(st.begin());
        int n=r.second;
        int w=r.first;
        st.erase(st.begin());
        for(auto nei:adj[n]){
            if(w+nei.first<dist[nei.second]){
                auto rec=st.find(make_pair(nei.first,dist[nei.second]));
                if(rec!=st.end()){
                    st.erase(rec);
                }
                dist[nei.second]=w+nei.first;
                st.insert(make_pair(dist[nei.first],nei.second));
            }
        }
    }
    return dist;
}


void makeAdj_List(vector<vector<int>>v,unordered_map<int,list<pair<int,int>>>&adj){
    for(int i=0;i<v.size();i++){
        int u=v[i][0];
        int w=v[i][1];
        int t=v[i][2];
        adj[u].push_back({w,t});
        adj[t].push_back({w,u});
    }
}


int main(){

}