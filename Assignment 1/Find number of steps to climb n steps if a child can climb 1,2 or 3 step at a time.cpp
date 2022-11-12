#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;
int helper(int n, vector<int>& dp)
{
    if(n < 0)
    return 0;
    if(n == 0)
    return 1;

    if(dp[n] != -1)
    return dp[n];

    int a = helper(n-1,dp)%mod;
    int b = helper(n-2,dp)%mod;
    int c = helper(n-3,dp)%mod;

    return dp[n] = (a+b+c)%mod;
}
int number_of_ways(int n)
{
    //using O(1) space
    vector<int>dp(n+1,0);
    //return helper(n,dp);  
    int curr;
    if(n == 1 or n == 2)
    return n;
    int f = 1;
    int s = 1;
    int t = 2;
    for(int i=3;i<=n;i++)//reverse the loop
    {
        curr = (((f+s)%mod)+t)%mod;
        f=s;
        s=t;
        t=curr;
    }
    return t;
}


int main()
{
    int n;
    cin >> n;

    cout << number_of_ways(n) << endl;
}
