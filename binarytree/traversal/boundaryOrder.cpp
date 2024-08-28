    #include<iostream>
    #include<queue>
    #include<algorithm>
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

void traverseLeftNodes(Node* root,vector<int>&ans){
    if(root==NULL)return ;
    if(root->left==NULL && root->right==NULL)return;

    ans.push_back(root->data);
    if(root->left!=NULL){
        traverseLeftNodes(root->left,ans);
    }
    else{
        traverseLeftNodes(root->right,ans);
    }
}

void traverseLeafNodes(Node* root,vector<int>& ans){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    traverseLeafNodes(root->left,ans);
    traverseLeafNodes(root->right,ans);
}

void traverseRightNodes(Node* root,vector<int>& ans){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)return;
    ans.push_back(root->data);
    if(root->right!=NULL)traverseRightNodes(root->right,ans);
    else traverseRightNodes(root->left,ans);
}

vector<int>boundaryOrderTraversal(Node* root){
    if(root==NULL)return {};
    vector<int>ans;
    ans.push_back(root->data);
    //left part
    traverseLeftNodes(root->left,ans);
    //leaf part
    traverseLeafNodes(root,ans);
    //right part
    traverseRightNodes(root->right,ans);
    return ans;
}



int main(){
    Node* root=buildTree(root);
    vector<int>v;
    v=boundaryOrderTraversal(root);
    for(auto i:v)cout<<i<<" ";cout<<endl;
}