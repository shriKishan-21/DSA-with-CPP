#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> maze)
{

    if ((x >= 0 && x < n) && (y >= 0 && y < n) && maze[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // src pe khade he
    visited[x][y] = 1;

    // 4 choice --> D/L/R/U

    // 1. Down
    int newx = x + 1;
    int newy = y;
    // check the basic conditions
    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('D');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // 2. Left
    newx = x;
    newy = y - 1;
    // check the basic conditions
    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('L');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // 3. Right
    newx = x;
    newy = y + 1;
    // check the basic conditions
    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('R');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // 4. Up
    newx = x - 1;
    newy = y;
    // check the basic conditions
    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('U');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
    // code here

    int n = maze.size();

    vector<string> ans;

    // if source is 0
    if (maze[0][0] == 0)
    {
        return ans;
    }

    // current x and y position
    int srcx = 0;
    int srcy = 0;

    // create visited array
    vector<vector<int>> visited = maze;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    // create a path to store individual path
    string path = "";

    // call solve function
    solve(maze, n, ans, srcx, srcy, visited, path);

    // sort to maintain lexicographical order
    sort(ans.begin(), ans.end());

    return ans;
}
int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = ratInMaze(maze);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}