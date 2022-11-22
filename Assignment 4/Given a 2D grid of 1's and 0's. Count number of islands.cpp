#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class NumberOfIslands {
  public:
    void dfs(int row, int col, int n, int m, vector<string>& grid)
    {
      if(row<0 or col<0 or row>=n or col>=m or grid[row][col] == '3' or grid[row][col] == '0')
      return;

      grid[row][col] = '3';

      dfs(row+1,col,n,m,grid);
      dfs(row-1,col,n,m,grid);
      dfs(row,col+1,n,m,grid);
      dfs(row,col-1,n,m,grid);

      return;
    }
    int numIslands(vector<string>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      int count = 0;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(grid[i][j] == '1')
          {
            count++;
            dfs(i,j,n,m,grid);
          }
        }
      }
      return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid;
    ReadMatrix<string>().OneDMatrix(n, grid);
    int result = NumberOfIslands().numIslands(grid);
    cout << result;
    return 0;
}

/* 
Crio Methodology

Milestone 1: Understand the problem clearly
1. Ask questions & clarify the problem statement clearly.
2. Take an example or two to confirm your understanding of the input/output & extend it to test cases
Milestone 2: Finalize approach & execution plan
1. Understand what type of problem you are solving.
     a. Obvious logic, tests ability to convert logic to code
     b. Figuring out logic
     c. Knowledge of specific domain or concepts
     d. Knowledge of specific algorithm
     e. Mapping real world into abstract concepts/data structures
2. Brainstorm multiple ways to solve the problem and pick one
3. Get to a point where you can explain your approach to a 10 year old
4. Take a stab at the high-level logic & write it down.
5. Try to offload processing to functions & keeping your main code small.
Milestone 3: Code by expanding your pseudocode
1. Make sure you name the variables, functions clearly.
2. Avoid constants in your code unless necessary; go for generic functions, you can use examples for your thinking though.
3. Use libraries as much as possible
Milestone 4: Prove to the interviewer that your code works with unit tests
1. Make sure you check boundary conditions
2. Time & storage complexity
3. Suggest optimizations if applicable
*/