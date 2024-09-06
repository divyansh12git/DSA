#include <iostream>
using namespace std;

#include <queue>

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
    Node* temp=new Node(d);
    cout<<"Enter the left child of "<<d<<" : ";
    temp->left=buildTree(temp->left);
    cout<<"Enter the right child of "<<d<<" : ";
    temp->right=buildTree(temp->right);
    return temp;
}
void levelOrderTraversal(Node* root){
    if(root==NULL)return;
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

    
int count(Node* root){
    if(root==NULL)return 0;
    return 1+count(root->left)+count(root->right);
}
bool isCBT(Node* root,int tot,int i){
    if(root==NULL)return true;
    if(i>=tot)return false;
    return isCBT(root->left,tot,2*i+1) && isCBT(root->right,tot,2*i+2);
}
bool isMinHeap(Node* root){
    if(root==NULL)return true;
    if(root->left==NULL && root->right==NULL)return true;
    if(root->right==NULL)return ( root->data<root->left->data);
    return isMinHeap(root->left) && isMinHeap(root->right) && (root->data<root->left->data)
            && root->data<root->right->data;

}

bool isBTHeap(Node* root){
    if(root==NULL)return true;
    int totalNodes=count(root);
    if(!isCBT(root,totalNodes,0))return false;
    return isMinHeap(root);
}

int main(){
    //  #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("Error.txt", "w", stderr);
    // #endif 
    Node* root=NULL;
    root=buildTree(root);
    levelOrderTraversal(root);
    cout<<isBTHeap(root)<<endl;

  return 0;
}