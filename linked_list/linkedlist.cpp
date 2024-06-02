#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<value+"is free"<<endl;
    }
};
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &head,int d){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(d);
    temp->next=newNode;
}

void insertAtMiddle(Node* &head,int pos,int d){
    Node* nn=new Node(d);
    Node* temp=head;
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    
    int p=1;
    while(++p!=pos && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertAtTail(temp,d);
        return;
    }
    nn->next=temp->next;
    temp->next=nn;
    return;
}
void deleteNode(Node* &head,int pos){
    if(pos==1){
        Node* curr=head;
        head=head->next;
        curr->next=NULL;
        delete curr;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}


int main(){
    Node* node1 =new Node(50);
    Node* head=node1;
    insertAtHead(head,40);
    insertAtHead(head,400);
    insertAtHead(head,20);
    insertAtHead(head,0);
    // insertAtTail(head,80);
    // insertAtMiddle(head,4,38);
    // insertAtMiddle(head,8,38);
    // insertAtMiddle(head,1,38);
    print(head);
    deleteNode(head,3);
    print(head);
}