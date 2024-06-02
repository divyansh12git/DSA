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
void insertAtHead(Node* &Head,int d){
    Node* temp=new Node(d);
    temp->next=Head;
    Head=temp;
}
void print(Node* &Head){
    Node* temp=Head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}




int main(){
    Node* node1=new Node(1);
    Node* Head=node1;

    insertAtHead(Head,2);
    insertAtHead(Head,3);
    insertAtHead(Head,4);
    insertAtHead(Head,5);
    insertAtHead(Head,6);
    insertAtHead(Head,7);
    insertAtHead(Head,8);
    insertAtHead(Head,9);
    print(Head);
}