#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
#include<algorithm>
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

int main(){
    DisjointSet ds(7);
    cout<<ds.finduParent(3)<<endl;
    ds.unionByRank(0,1);
    cout<<ds.finduParent(0)<<" "<<ds.finduParent(1)<<endl;
}