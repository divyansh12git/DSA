#include<iostream>
using namespace std;
#define ll long long
int MOD=1e9+7;
ll MOD2=1e18;
ll modPower(ll a, ll b, ll modulus) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % modulus;
        }
        a = (a * a) % modulus;
        b /= 2;
    }
    return result;
}
int main(){
    int x=modPower(10,3,10e9+7);
    int a=55,b=88;
    int p=log10(b)/log10(a);
    cout<<x<<endl;
}