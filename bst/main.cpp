#include <iostream>
using namespace std;
#include <queue>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


Node* insertIntoBST(Node* &root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(Node* & root){
    int d;
    cout<<"Enter the data:"<<endl;
    cin>>d;
    while(d!=-1){
        insertIntoBST(root,d);
   
        cin>>d;
    }
}

void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* a=q.front();
        q.pop();
        if(a==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<a->data<<" ";
            if(a->left){
                q.push(a->left);
            }
            if(a->right){
                q.push(a->right);
            }
        }

    }
}
int main(){
    Node* root=NULL;
    takeInput(root);
    levelOrderTraversal(root);

}
