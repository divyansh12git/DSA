#include <iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char data){
            this->data=data;
            for(int i=0;i<26;i++){
                this->children[i]=NULL;
            }
            this->isTerminal=false;
        }
};
class Trie{
    public:
        TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtils(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[index]);
            root->children[index]=child;
        }
        //Recursion
        insertUtils(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtils(root,word);
    }
    
    bool searchUtils(TrieNode* root,string word){
        //base Case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];

        }
        else{
            return false;
        }
        //recursion
        return searchUtils(child,word.substr(1));
    }
    bool search(string word){
        return searchUtils(root,word);
    }
    void removeUtils(TrieNode* root,string word){
        //baseCase
        if(word.length()==1){
            root->isTerminal=false;
            return;
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return;  
        }
        return removeUtils(child,word.substr(1));
    }
    void removeWord(string word){
        removeUtils(root,word);
    }
};
int main(){
    Trie* t=new Trie();
    t->insertWord("abcdefg");
    cout<<t->search("abcd");
}



