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
};
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){
    Node* node1 =new Node(50);
    Node* head=node1;
    insertAtHead(head,40);
    insertAtHead(head,400);
    insertAtHead(head,-20);
    insertAtHead(head,0);
    insertAtHead(head,80);
    print(head);
}