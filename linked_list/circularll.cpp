#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
        // cout<<"Success"<<endl;
    }
};
void insertAtHead(Node* &head,Node*&tail,int d){
    if(head==NULL){
        head=new Node(d);
    }
    Node* newNode=new Node(d);
    newNode->next=head;
    tail->next=newNode;
    head=newNode;
}
void insertAttail(Node* &head,Node*&tail,int d){
    Node* nn=new Node(d);
    tail->next=nn;
    tail=nn;
    nn->next=head;
}

void print(Node*head){
    Node*temp=head;
    if(head==NULL)return;
    cout<<temp->data<<"->";
    
    temp=temp->next;
    while(temp!=head && temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<endl;
}

int main(){
    Node* head=new Node(5);
    Node* tail=head;
    
    insertAtHead(head,tail,4);
    
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,1);
    insertAttail(head,tail,6);
    insertAttail(head,tail,7);
    insertAttail(head,tail,8);
    print(head);

    cout<<head->data<<" "<<tail->data<<endl;

}