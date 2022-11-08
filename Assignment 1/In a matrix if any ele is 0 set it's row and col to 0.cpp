#include <bits/stdc++.h>
using namespace std;

class SetMatrixZeroes {
  public:

    void setMatrixZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool col0 = false;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0] == 0)
            col0 = true;
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=1;j--)
            {
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if(col0 == true)
            matrix[i][0] = 0;
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
        cout<<"\n";
    }
    SetMatrixZeroes().setMatrixZeroes(grid);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
