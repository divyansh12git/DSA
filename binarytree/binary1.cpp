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

Node* buildTree(Node* root){
  cout<<"Enter the data"<<endl;
  int data;
  cin>>data;
  if(data==-1){
    return NULL;
  }
  root=new Node(data);
  
  cout<<"for left child"<<endl;
  root->left=buildTree(root->left);
  
  cout<<"for right child"<<endl;
  root->right=buildTree(root->right);

  return root;
  
}
void LevelOrderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    
    if(temp==NULL){
      cout<<endl;
      if(!q.empty())
        q.push(NULL);
    }
    else{
      cout<<temp->data<<" ";
      if(temp->left){
        q.push(temp->left);
        
      }
      if(temp->right){
        q.push(temp->right);
      }
    }


    
  }
  





  
}

int main(){
  Node* root=NULL;
  buildTree(root);
  LevelOrderTraversal(root);



  return 0;
}