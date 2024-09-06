#include<iostream>
#include<vector>
using namespace std;

int traverse(vector<vector<int>>&A,int x,int y,int n,int & ans,int maxi,vector<vector<int>>&dp){
    if(x>1 || y>=n )return;
    if(x==1 && y==n-1){
        ans=min(ans,maxi);
    }
    // if(dp[x][y]!=-1)return;
    maxi=max(maxi,A[x][y]);
    traverse(A,x+1,y,n,ans,maxi,dp);
    traverse(A,x,y+1,n,ans,maxi,dp);

}

int main(){

}