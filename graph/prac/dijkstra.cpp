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

vector<int> dijkstra(int src,int v,unordered_map<int,list<pair<int,int>>>&graph){
    vector<int>dist(v+1,1e9);
    set<pair<int,int>>st;
    st.insert({src,0});
    dist[src]=0;
    while(!st.empty()){
        pair<int,int> f=*(st.begin());
        int node=f.first;
        int w=f.second;
        for(auto i:graph[node]){
            if(w+i.second<dist[i.first]){
                auto record=st.find({dist[i.first],i.first});
                if(record!=st.end()){
                    st.erase(record);
                }
                //update
                dist[i.first]=i.second+w;
                st.insert({i.first,dist[i.first]});
            }
        }
    }
}




int main(){

}