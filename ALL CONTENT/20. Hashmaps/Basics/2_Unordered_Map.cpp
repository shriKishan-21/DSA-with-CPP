#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    // creation
    unordered_map<string,int> m;

    // insertion
    // Method 1 : using insert function
    pair<string,int> p = make_pair("data",1);
    m.insert(p);

    // Method 2 : using insert function
    pair<string,int> p1("structure",1);
    m.insert(p1);

    // Method 3 : using [] operator
    m["algorithm"] = 1;

    // Method 4 : using insert function
    m.insert({"c++",1});

    // Ques : what happens if we again insert the same key
    m["c++"] = 2; // -- the previous same key will be updated
    // First insetion of key -> creation is Done
    // Second insetion of same key -> updatation is Done
    
    // Seaching
    cout<<m["c++"]<<endl; // return value corresponding to key
    cout<<m.at("c++")<<endl; // return value corresponding to key

    // Ques : what happens if we search for non existing key
    cout<<m.at("unknownKey")<<endl; // throws exception

    // but what if we use 
    cout<<m["unknownKey"]<<endl; // it will cretae a new key and return 0
    cout<<m.at("unknownKey")<<endl; // it will return the value associated with the previous created key

    // Size
    cout<<m.size()<<endl;

    // To check presence
    cout<<m.count("c++")<<endl; // return 1 if present else 0

    // erase function
    m.erase("c++");

    // Acess elements inside unordered_map
    // 1. Using loop
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // 2. Iterator
    unordered_map<string,int> :: iterator it = m.begin(); // it points to first element of unordered_map
    while(it != m.end()){ // it points to last element of unordered_map
        cout<<it->first<<" "<<it->second<<endl;
        it++; // it points to next element of unordered_map
    }

    return 0;
}
