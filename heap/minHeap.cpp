#include <iostream>
#include <vector>
using namespace std;
class heap{
    public:
    int size;
    vector<int>arr;
    heap(){
        size=0;
    }
    void insertHeap(int x){
        arr.push_back(x);
        size++;
        int i=size-1;
        while(i>0){
            int p=(i-1)/2;

            if(p>=0 && arr[p]>arr[i]){
                swap(arr[p],arr[i]);
                i=p;
            }else return;
        }
    }
    int deleteHeap(){
        if(size==0)return -1;
        int i=0;
        int ans=arr[0];
        swap(arr[0],arr[size-1]);
        size--;
        arr.pop_back();
        while(i<size){
            int l=2*i+1;
            int r=2*i+2;
            if(l<size && arr[i]>arr[l]){
                swap(arr[i],arr[l]);
                i=l;
            }
            else if(r<size && arr[i]>arr[r]){
                swap(arr[i],arr[r]);
                i=r;
            }else {
                break;
            }
        }
        return ans;
    }

};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    heap* h=new heap();
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(q[i].size()==2){
            h->insertHeap(q[i][1]);
        }else{
            int y=h->deleteHeap();
            if(y!=-1)ans.push_back(y);
        }
    }
    for(auto i:ans)cout<<i<<" ";cout<<endl;
    return ans;
}
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;cin>>n;
        vector<vector<int>>q(n);
        for(int i=0;i<n;i++){
            vector<int>l;
            
        }
    }
}