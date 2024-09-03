#include<iostream>
using namespace std;

class heap{
    public:
        int *arr;
        int size;
        heap(int maxi){
            size=0;
            arr=new int[maxi];
        }
        void insertHeap(int x){
            size++;
            arr[size]=x;
            int i=size;
            while(i>0){
                int p=size/2;
                if(p>0 && arr[p]<x){
                    swap(arr[p],arr[i]);
                    i=p;
                }else{
                    return;
                }
            }
            return;
        }
        void deleteHeap(){
            if(size==0){
                cout<<"Heap is empty"<<endl;
                return;
            }
            int x=arr[size];
            size--;
            swap(arr[1],x);
            int i=1;
            int l=2*i,r=2*i+1;
            if(l<=size && arr[l]>arr[i]){
                swap(arr[i],arr[l]);
                i=l;
            }else if(r<=size && arr[r]>arr[i]){
                swap(arr[r],arr[i]);
                i=r;
            }else {
                return;
            }
        }
        void printHeap(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
};

void heapify(int *arr,int size,int i){
    if(i>size)return;
    int l=2*i;
    int r=2*i+1;
    int largest=i;
    if(l<=size && arr[largest]<arr[l]){
        largest=l;
    }
    if(r<=size && arr[largest]<arr[r]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }else return;
    
}

void createHeap(int *arr,int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}
void heapSort(int *arr,int n){
    int size=n;
    createHeap(arr,n);
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}

int main(){
    // heap* h=new heap(100);
    // h->insertHeap(52);
    // h->insertHeap(60);
    // h->insertHeap(62);
    // h->insertHeap(59);
    // h->printHeap();
    // h->deleteHeap();
    // h->printHeap();
    int arr[]={-1,5,8,88,1,5,6};
    heapSort(arr,6);
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
}