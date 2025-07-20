#include<iostream>
#include<vector>
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


    void printSuggestion(TrieNode* curr , vector<string> &temp , string prefix){
        // base case
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        // 
        for(char ch = 'a';ch<='z';ch++){
            int index = ch-'a';

            TrieNode* next = curr->children[index];

            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        
        }
    }

    vector<vector<string>> getSuggestion(string word){

        TrieNode* prev = root;
        vector<vector<string>> ans;

        string prefix = "";

        for(int i=0;i<word.length();i++){
            char lastchar = word[i];

            prefix.push_back(lastchar);

            // check lastchar -- present in string or not
            int index = lastchar-'a';
            TrieNode* curr = prev->children[index];

            // if not present
            if(curr==NULL){
                break;
            }
            
            // if found
            vector<string> temp;

            printSuggestion(curr,temp,prefix);

            ans.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr){

    // 1. creation of trie
    Trie* t = new Trie();

    // 2. insert all contact in trie
    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    // return ans
    return t->getSuggestion(queryStr);
}

int main(){
    vector<string> contactList = {"gforgeeks", "geeksquiz", "geeksforgeeks"};
    string queryStr = "ge";

    vector<vector<string>> ans = phoneDirectory(contactList,queryStr);
    for(int i=0;i<ans.size();i++){
        cout<<queryStr<<" ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
    
}

    
