#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* constructBST(Node* root,int d){
    if(root==NULL){
        Node* node=new Node(d);
        root=node;
        return root;
    }
    if(d>root->data){
        root->right=constructBST(root->right,d);
    }else{
        root->left=constructBST(root->left,d);
    }
    return root;
}

Node* createBST(){
    int x;
    cout<<"enter root"<<endl;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node* root=new Node(x);
    cout<<"enter data"<<endl;
    cin>>x;
    while(x!=-1){
        cout<<"enter data"<<endl;
        root=constructBST(root,x);
        cin>>x;
    }
    return root;
}

Node* findMin(Node* root){
    if(root==NULL)return root;
    if(root->left==NULL)return root;
    return findMin(root->left);
}

Node* deleteFromBST(Node* root, int val){
    if(root==NULL)return root;
    if(val>root->data){
        root->right=deleteFromBST(root->right,val);
    }
    else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if((root->left==NULL && root->right!=NULL)||(root->left!=NULL && root->right==NULL)){
            Node* temp=NULL;
            if(root->left){
                temp=root->left;
            }
            if(root->right){
                temp=root->right;
            }
            delete root;
            return temp;
        }else if(root->left!=NULL && root->right!=NULL){
            Node* temp=findMin(root->right);
            root->data=temp->data;
            delete temp;
        }
    }
    return root;
}

//recursive code...
bool searchInBST(Node* root,int d){
    if(root==NULL || d==-1)return false;
    
    if(d==root->data)return true;
    if(d>root->data){
        return searchInBST(root->right,d);
    }
    else{
        return searchInBST(root->left,d);
    }
    return false;
}
//iterative code...
bool searchInBSTIter(Node* root,int d){
    Node* temp=root;
    bool ans=false;
    while(temp!=NULL ){
        if(temp->data==d){
            ans=true;break;
        }
        if(temp->data>d){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return ans;
}
int main(){
    Node* root=createBST();
    cout<<searchInBST(root,15)<<endl;
    cout<<searchInBSTIter(root,5)<<endl;
    deleteFromBST(root,5);
}