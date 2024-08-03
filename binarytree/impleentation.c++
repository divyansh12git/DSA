#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;
    public:
    Node(int d){
        this->left=NULL;
        this->right=NULL;
        this->data=d;
    }
};
Node* buildTree(Node* root){
    cout<<"Enter the data"<<endl;
    int d;cin>>d;
    if(d==-1){
        return NULL;
    }
    root=new Node(d);
    cout<<"Enter the left child of"<<d<<" : ";
    root->left=buildTree(root->left);
    cout<<"Enter the right child of "<<d<<" : ";
    root->right=buildTree(root->right);
    return root;
}
void inorderTraversal(Node* root){
    if(root==NULL)return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preOrder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }

    }
}


int main(){
    #ifndef ONLINE_JUDGE4
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt", "w", stderr);
    #endif 
    Node* root;
    root=buildTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
}

