#include<iostream>
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
            prev=head;
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

void reverseLL(Node*&head){
    if(head==NULL)return;
    if(head->next==NULL)return;
    Node*curr=head;
    Node*prev=NULL;    
    Node*fwd=NULL;
    while(curr->next!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }    
    curr->next=prev;
    head=curr;
}
void revsol(Node*& head,Node* curr,Node* prev){
    if(curr->next==NULL){
        curr->next=prev;
        head=curr;
        return;
    }
    Node* fwd=curr->next;
    revsol(head,fwd,curr);
    curr->next=prev;
    
}
void recReverseLL(Node*&head){
    if(head==NULL)return;
    if(head->next==NULL)return;
    Node* curr=head;
    Node* prev=NULL;
    revsol(head,curr,prev);
}

int main(){
    Node* head=new Node(5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    recReverseLL(head);
    print(head);
}