#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    // structure of map
    unordered_map<int, int> freq;

    // Example input
    int arr[] = {2, 2};

    // Count frequencies
    for (int i : arr) {
        freq[i]++;
    }
    vector<int> ans;
    // Output frequencies
    for (const auto& pair : freq) {
        cout << "Value: " << pair.first << ", Count: " << pair.second << std::endl;
        ans.push_back(pair.second);
    }
    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}
