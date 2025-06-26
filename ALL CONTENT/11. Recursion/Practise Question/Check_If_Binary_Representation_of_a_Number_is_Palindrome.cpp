#include <bits/stdc++.h>
using namespace std;

// Function to convert number to binary
string binary(int num) {
    string binary = "";
    if (num == 0) return "0";
    while (num > 0) {
        binary = char((num % 2) + '0') + binary;
        num /= 2;
    }
    return binary;
}

// Function to check if a string is a palindrome (recursive)
bool isPalindrome(string& str, int i, int j) {
    if (i >= j) return true;
    if (str[i] != str[j]) return false;
    return isPalindrome(str, i + 1, j - 1);
}

// Function to check if the binary representation is a palindrome
bool checkPalindrome(long long N) {
    string str = binary(N);
    return isPalindrome(str, 0, str.length() - 1);
}

// Main function to test
int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;

    if (checkPalindrome(num)) {
        cout << "Binary of " << num << " is a palindrome." << endl;
    } else {
        cout << "Binary of " << num << " is not a palindrome." << endl;
    }

    return 0;
}
