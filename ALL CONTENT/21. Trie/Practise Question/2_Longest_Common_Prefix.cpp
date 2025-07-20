#include<iostream>
#include<vector>
using namespace std;

// Approach 1
string longestCommonPrefix(vector<string> &arr , int n){

    // string to store ans
    string ans = "";

    // for traversing all characters of first string
    for(int i=0;i<arr[0].length();i++){
        char ch = arr[0][i];

        bool match = true;

        // for comapring with res of the string
        for(int j=1;j<n;j++){
            if(arr[j].length()==i || arr[j][i]!=ch){
                match = false;
                break;
            }
        }

        if(match==true){
            ans.push_back(ch);
        }
        else{
            break;
        }
    }

    return ans;

}

// Approach 2 -- using trie
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childcount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childcount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root = new TrieNode(ch);
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
            root->childcount++;
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void lcp(string str , string &ans){

        for(int i=0;i<str.length();i++){
            char ch = str[i];

            if(root->childcount==1){
                ans.push_back(ch);
                // move forward
                int index = ch-'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }
    }

};

string longestCommonPrefix2(vector<string> &arr , int n){
    Trie* t = new Trie('\0');

    // insert all string into trie
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }

    // find lcp
    string first = arr[0];
    string ans = "";

    t->lcp(first,ans);

    return ans;
}


int main()
{
    // Approach 1
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    int n = arr.size();
    cout<<longestCommonPrefix(arr,n);

    cout<<endl;

    // Approach 2
    cout<<longestCommonPrefix2(arr,n);


    return 0;

}