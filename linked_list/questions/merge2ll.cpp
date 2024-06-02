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


Node* merge2sortedll(Node* h1,Node* h2){
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    Node* t1=NULL;
    Node* t2=NULL;
    Node* ans=NULL;
    if(h1->data>h2->data){
        t1=h2;
        t2=h1;
        ans=h2;
    }else{
        ans=h1;
        t1=h1;
        t2=h2;
    }
    print(ans);
    print(t1);
    print(t2);
    // print(t2);
    Node* fwd1=NULL;
    Node* fwd2=NULL;
    if(t1->next==NULL){
        t1->next=t2;
        return ans;
    }
    while(t1->next!=NULL && t2!=NULL){
            fwd1=t1->next;
            fwd2=t2->next;
        if(t1->data<=t2->data && t2->data<=fwd1->data){
            t1->next=t2;
            t1=t1->next;
            t2->next=fwd1;
            t2=fwd2;
        }else{
            t1=t1->next;
            if(t1->next==NULL){
                t1->next=t2;
            }
        }
        // print(ans);

    }
    return ans;


}


int main(){
    Node* head1=new Node(8);
    // insertAtHead(head1,9);
    // insertAtHead(head1,6);
    // insertAtHead(head1,4);
    print(head1);
    Node* head2=new Node(7);
    insertAtHead(head2,4);
    insertAtHead(head2,3);
    print(head2);
    Node* mer=merge2sortedll(head1,head2);
    print(mer);
}