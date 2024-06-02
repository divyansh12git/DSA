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
        if(this->next !=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"deleted "<<value<<endl;
    }

};
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtMiddle(Node* &head,Node* &tail,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    Node* prev=head;
    int cnt=1;
    while(cnt<pos-1){
        cnt++;
        prev=prev->next;
    }
    if(prev->next==NULL){
        insertAtTail(tail,d);
        return;
    }


    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=prev->next;
    prev->next=nodeToInsert;

}

void deleteAtIndex(Node* &head,int pos){
    
    if(pos==1){
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* current=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt!=pos-1){
            prev=current;
            current=current->next;
            cnt++;
        }
        prev->next=current->next;
        current->next=NULL;
        delete current;
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
    Node* node1=new Node(5);
    // cout<<node1->data<<endl;
    Node* head=node1;
    Node* tail=node1;
    
    insertAtHead(head,4);
    
    insertAtTail(tail,7);
  
    insertAtMiddle(head,tail,3,6);
      print(head);
      insertAtMiddle(head,tail,1,3);
      print(head);
      insertAtMiddle(head,tail,6,8);
      print(head);
}