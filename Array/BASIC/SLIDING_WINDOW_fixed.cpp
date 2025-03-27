// SLIDING WINDOW FIXED SIZE

#include <bits/stdc++.h>
using namespace std;

// Function to compute the maximum sum of a fixed-size sliding window
int maxSlidingWindowSum(vector<int> &arr, int k)
{
    if (arr.size() < k)
    {
        cout << "Window size is larger than array size!" << endl;
        return -1;
    }

    int maxSum = 0, windowSum = 0;

    // Compute the sum of the first window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }
    maxSum = windowSum;

    // Slide the window through the array
    for (int i = k; i < arr.size(); i++)
    {
        windowSum += arr[i] - arr[i - k]; // Add new element, remove old element
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 2, 6, 4, 8};
    int k = 3; // Window size

    int result = maxSlidingWindowSum(arr, k);
    cout << "Maximum sum of any window of size " << k << " is: " << result << endl;

    return 0;
}