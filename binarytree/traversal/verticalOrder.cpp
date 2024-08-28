#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
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

void verticalOrderTraversal(Node* root){
    map<int,map<int,vector<int>>>nodes;
    if(root==NULL)return;
    queue<pair<Node*,pair<int,int>>>q;
    vector<int>ans;
    q.push({root,{0,0}});
    while(!q.empty()){
        pair<Node*,pair<int,int>>p=q.front();
        q.pop();
        int hd=p.second.first;
        int vh=p.second.second;
        nodes[hd][vh].push_back(p.first->data);
        if(p.first->left){
            q.push({p.first->left,{hd-1,vh+1}});
        }
        if(p.first->right){
            q.push({p.first->right,{hd+1,vh+1}});
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                cout<<k<<" ";
            }
        }
    }
    
}

int main(){
    Node* root;
    root=buildTree(root);
    verticalOrderTraversal(root);
}