#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    // Insertion
    void insertUtil(TrieNode* root,string word){
        // base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        // assumption - word will be in lower case
        int index = word[0]-'a';
        TrieNode* child;

        // present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        // absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    // Search
    bool searchUtil(TrieNode* root,string word){
        // base case
        if(word.length()==0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode* child;

        // present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        // absent
        else{
            return false;
        }

        // recursive call
        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }


    // deletion
    void deleteUtil(TrieNode* root,string word){
        // base case
        if(word.length()==0){
            root->isTerminal = false;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        deleteUtil(child,word.substr(1));


        // check
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void deleteWord(string word){
        deleteUtil(root,word);
    }

};

int main(){
    Trie* t = new Trie();
    t->insertWord("apple");
    t->deleteWord("apple");
    cout<<t->searchWord("apple")<<endl;
    cout<<t->searchWord("app")<<endl;


    return 0;

}