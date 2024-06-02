#include<iostream>
using namespace std;
int main(){
    int arr[]={2,2,2,1,0,0,0,1,1,1,2,1,0,0,2,1};
    for(int i=0,j=15;i<j;){
        while(arr[i]==0){
            i++;
        }
        while(arr[j]==1 || arr[j]==2){
            j--;
        }
        if(i<j){
        swap(arr[i],arr[j]);
        }
    }
    for(int k=0,l=15;k<l;){
        while(arr[k]==0 || arr[k]==1){
            k++;
        }
        while(arr[l]==2){
            l--;
        }
        if(k<l){
        swap(arr[l],arr[k]);
    }
    }
    for(int k=0;k<16;k++){
        cout<<arr[k];
    }
}
