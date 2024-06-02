#include <iostream>
#include <math.h>
using namespace std;

int ncr(int n,int r){
    int a=1,b=1,d=n-r ,ans=1;
    if(n==0){
        a=1;
    }
    else if(r==0){
        b=1;
    }
    else{
    for(;n>0,r>0,d>0;n--,r--,d--){
        a=a*n;b*=r;d*=d;

    }
    }
    return a/(b*d);
}


int main(){
    int n,r;
    cin>>n>>r;
    int ans=ncr(n,r);
    cout<<"the ncr of input is "<<ans<<endl;



}
