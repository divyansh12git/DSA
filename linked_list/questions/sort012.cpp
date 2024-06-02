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
Node* Sort012(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* zero=NULL;
    Node* ztemp=NULL;
    Node* one=NULL;
    Node* otemp=NULL;
    Node* two=NULL;
    Node* ttemp=NULL;
    Node* temp=head;
    while(temp!=NULL){
            Node* nn=new Node(-1);
        if(temp->data==0){
            nn->data=0;
            if(zero==NULL){
                zero=nn;
                ztemp=zero;
            }else{
                ztemp->next=nn;
                ztemp=ztemp->next;
            }
        }
        else if(temp->data==1){
            nn->data=1;
            if(one==NULL){
                one=nn;
                otemp=one;
            }else{
                otemp->next=nn;
                otemp=otemp->next;
            }
        }
        else if(temp->data==2){
            nn->data=2;
            if(two==NULL){
                two=nn;
                ttemp=two;
            }else{
                ttemp->next=nn;
                ttemp=ttemp->next;
            }
        }
        temp=temp->next;
    }
    
    ztemp->next=one;
    otemp->next=two;
    return zero;

    


}

int main(){
    Node* head=new Node(0);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtHead(head,2);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtHead(head,0);
    insertAtHead(head,0);
    insertAtHead(head,0);
    print(head);
    Node* h=Sort012(head);
    print(h);
}