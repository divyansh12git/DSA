#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a;
    int i=0;
    cin>>a;
    int ans=0;
    while(a!=0){
        int bit=a&1;
        ans+=bit*pow(10,i);
        i++;
        a=a>>1;
    }
cout<<ans;

}