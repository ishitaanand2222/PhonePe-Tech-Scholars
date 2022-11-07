#include <bits/stdc++.h>
using namespace std;

bool conditionFail(pair<int, int > &pos, vector<vector<int>> &matrix, int &n){
    int x = pos.first, y = pos.second;
    if(x >= n || x < 0 || y >= n || y < 0)
        return true;
    if (matrix[x][y] != 0)
        return true;
    return false;
}  

vector<vector<int > > spiralMatrixII(int n){
    //code starts here
    vector<vector<int>>ans(n,vector<int>(n));
    int fr=0,fc=0;
    int count=1;
    int row=n-1,col=n-1;
    int num = 1;
    while(fr<=row and fc<=col)
    {
        for(int i=fr;i<=col;i++)
        {
            ans[fr][i]=count;
            count++;
        }
        fr++;

        for(int i=fr;i<=row;i++)
        {
            ans[i][col]=count;
            count++;
        }
        col--;

        for(int i=col;i>=fc;i--)
        {
            ans[row][i]=count;
            count++;
        }
        row--;
        for(int i=row;i>=fr;i--)
        {
            ans[i][fc]=count;
            count++;
        }
        fc++;
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int> > result = spiralMatrixII(n);
    for(auto &row: result){
        for(auto &element: row){
            cout<<element<<" ";
        }
        cout<<"\n";
    } 
}
