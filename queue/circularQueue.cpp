#include<iostream>
using namespace std;


class Queue{
    int *arr;
    int front, rear;
    int size;
    public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0,rear=0;
    }
    bool enqueue(int x){
        bool ret=true;
        if((rear==size && front==0)&& (front!=0 && rear==(front-1)%(size-1))){
            cout<<"Queue Full"<<endl;
            return false;
        }
        if(front==-1){front++;}
        arr[rear]=x;
        rear++;
        if(front!=0 && rear==size){
            rear=0;
        }
        return true;
    }
    int dequeue(){
        if(front==rear || front==-1){
            cout<<"Queue empty"<<endl;
            return -1;
        }
        int x=arr[front];
        front++;
        if(front==size){
            front=0;
        }
        return x;
    }
    bool isEmpty(){
        if(front==rear)return true;
        return false;
    }
    int getfront(){
        if(front==rear)return -1;
        return arr[front];
    }
    void printQueue(){
        int x=front;
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){
    Queue *q=new Queue(4);
    q->enqueue(5);

    q->enqueue(6);

    q->enqueue(7);

    q->enqueue(8);

    cout<<q->dequeue()<<endl;
    q->enqueue(10);
    q->enqueue(10);
    q->enqueue(10);
    q->enqueue(10);
    q->enqueue(10);
    q->dequeue();
    

 
}