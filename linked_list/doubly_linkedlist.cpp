#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->next=NULL;
        this->prev=NULL;
        this->data=data;
    }

};
void insertionathead(Node*& head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    temp->prev=NULL;
    head->prev=temp;
    head=temp;
}
void insertionattail(Node*& tail,int d){
    Node* temp=new Node(d);
    temp->next=NULL;
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}

void insertionAtMiddle(Node*& head,Node*& tail,int d,int pos){
    if(pos==1){
        insertionathead(head,d);
        return;
    }
    Node* temp=head;
    Node* newNode=new Node(d);
    int count=1;
    while(count<pos){
        count++;
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertionattail(tail,d);
        return;
    }
    temp->prev->next=newNode;
    newNode->prev=temp->prev;
    newNode->next=temp;
    temp->prev=newNode;


}


void print(Node*& head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}



int main(){
    Node* node1=new Node(5);
    Node* head=node1;
    Node* tail=node1;
 
    insertionathead(head,4);
    print(head);
    insertionattail(tail,6);
    print(head);
    insertionAtMiddle(head,tail,100,2);
    print(head);
    insertionAtMiddle(head,tail,10,1);
    print(head);
    cout<<head->data<<" ";
    cout<<tail->data<<" ";
    insertionAtMiddle(head,tail,100,5);
    print(head);
    cout<<head->data<<" ";
    cout<<tail->data<<" ";
    


}