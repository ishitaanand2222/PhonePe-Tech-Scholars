#include <bits/stdc++.h>
using namespace std;

class WordSearch {
  private:
  bool search(int ind, int row, int col, vector<vector<char>>& board, string word, int n, int m)
    {
        if(ind == word.size())
            return true;
        
        if(row>=n or col>=m or row<0 or col<0 or board[row][col] != word[ind] or board[row][col] == '#')return false;
        
        char c = board[row][col];
        board[row][col] = '#';
        
        if(search(ind+1,row+1,col,board,word,n,m) or search(ind+1,row-1,col,board,word,n,m) or search(ind+1,row,col+1,board,word,n,m) or search(ind+1,row,col-1,board,word,n,m) )
            return true;
        
        board[row][col] = c;
        
        return false;
    }
  public:
    bool exist(vector<vector<char>> &board, string &word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(search(0,i,j,board,word,n,m))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> grid(row,vector<char> (col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cin>>grid[i][j];
    }
    string word;
    cin >> word;
    bool result = WordSearch().exist(grid, word);
    if(result == true)
        cout<<"true";
    else
        cout<<"false";
}
