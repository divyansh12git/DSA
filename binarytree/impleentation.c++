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

void buildFromLevelOrder(Node* root){
    cout<<"Enter data :"<<endl;
    int d;cin>>d;
    root=new Node(d);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->data<<endl;
        int l;cin>>l;
        if(l!=-1){
            temp->left=new Node(l);
            q.push(root->left);
        }
        cout<<"Enter the right child of "<<temp->data<<endl;
        int r;cin>>r;
        if(r!=-1){
            temp->right=new Node(r);
            q.push(temp->right);
        }
    }
}

int height(Node* root){
    if(root==NULL)return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

pair<int,int> diameter(Node* root){//height,diameter
    if(root==NULL)return {0,0};
    pair<int,int> l=diameter(root->left);
    pair<int,int>r=diameter(root->right);
    int h=max(l.first,r.first)+1;
    int dia=max(l.second,max(r.second,r.first+l.first+1));
    return {h,dia};
}

pair<bool,int> isBalanced(Node* root){//condn,height
   if(root==NULL)return {true,0};
    pair<bool,int> l=isBalanced(root->left);
    pair<bool,int> r=isBalanced(root->right);
    int nh=max(l.second,r.second)+1;
    bool ans=l.first && r.first && abs(l.second-r.second)<=1;
    return {ans,nh};
}

pair<bool,int>isSumTree(Node* root){//cond,sum
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        int s=0;
        if(root!=NULL)s+=root->data;
        return {true,s};
    }
    pair<bool,int> l=isSumTree(root->left);
    pair<bool,int> r=isSumTree(root->right);
    int newsum=l.second+r.second;
    bool ans=l.first && r.first && newsum==root->data;
    // cout<<ans<<"||"<<newsum+root->data<<endl;
    return {ans,newsum+root->data};
}

//Traversals->

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

void inorderTraversal(Node* root){
    if(root==NULL)return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root==NULL)return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void zigzagTraversal(Node* root){
    if(root==NULL)return ;
    queue<Node*>q;
    q.push(root);q.push(NULL);
    // cout<<"HI"<<endl;
    bool ltr=true;
    while(!q.empty()){
        // cout<<"Yup"<<endl;
        vector<Node*>vec;
        while(!q.empty() && q.front()!=NULL){
            Node* temp=q.front();
            vec.push_back(temp);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            q.pop();
        }
        
        if(!ltr){
            reverse(vec.begin(),vec.end());
        }
        ltr=!ltr;
        for(auto i:vec){
            cout<<i->data<<" ";
        }
        if(q.front()==NULL){
            cout<<"\n";
            q.pop();
            if(!q.empty())q.push(NULL);
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
    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);
    // cout<<height(root)<<endl;
    // cout<<diameter(root).second<<endl;
    // cout<<isBalanced(root).first<<endl;
    // cout<<isSumTree(root).first<<endl;
    cout<<"ZIG ZAG traversal->"<<endl;
    zigzagTraversal(root);
    // levelOrderTraversal(root);
    // cout<<endl;
    // inorderTraversal(root);
    // cout<<endl;
    // preOrder(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
}

