#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int>rank,parent;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<parent.size();i++){
                parent[i]=i;
            }
        }
        int finduParent(int a){
            // for(auto i:parent)cout<<i<<" ";cout <<endl;
            if(parent[a]==a){
                return a;
            }
            return parent[a]=finduParent(parent[a]);
        }
        void unionByRank(int u,int v){
            int pu=this->finduParent(u);
            int pv=this->finduParent(v);
            if(rank[u]>rank[v]){
                parent[v]=pu;
            }
            else if(rank[v]>rank[u]){
                parent[u]=pv;
            }else{
                rank[u]++;
                parent[v]=pu;
            }
        }
};
void Prims(int v,unordered_map<int,list<pair<int,int>>>&graph){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(v,0);
    pq.push({0,0});
    int ans=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int w=it.first;
        int u=it.second;
        if(!vis[u]){
            ans+=w;
            vis[u]=1;
            for(auto i:graph[u]){
                if(!vis[i.first]){
                    pq.push({i.second,i.first});
                }
            }
        }
    }
}

int kruskal(int v,unordered_map<int,list<pair<int,int>>>&graph){
    vector<pair<int,pair<int,int>>>vec;
    for(auto i:graph){
        for(auto j:i.second){
            vec.push_back({j.second,{i.first,j.first}});
        }
    }
    sort(vec.begin(),vec.end());
    DisjointSet *ds=new DisjointSet(v);
    int mstwt=0;
    for(auto it:vec){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.first;
        if(ds->finduParent(u)!=ds->finduParent(v)){
            mstwt+=wt;
            ds->unionByRank(u,v);
        }

    }
    return mstwt;
}

int main(){

}