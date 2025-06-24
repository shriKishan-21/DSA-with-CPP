#include <bits/stdc++.h>
using namespace std;

int main()
{

// --------------------------------------------

    // creating 2D array of size n*n (Same row and column size) :
    int n;
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    // creation done

    // Taking input -->
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Output -->
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deleting 2D array :
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

// ---------------------------------------------

    // Creating 2D array of size row*col(different row and column size) :
    int row;
    cin>>row;

    int col;
    cin >> col;

    int **nums = new int *[row];

    for (int i = 0; i < row; i++)
    {
        // for the rows creating array of size column
        arr[i] = new int[col];
    }
    // creation done

    // Taking input -->
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Output -->
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deleting 2D array :
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

// ---------------------------------------------

    return 0;
    
}