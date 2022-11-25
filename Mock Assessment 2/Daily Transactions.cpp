#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTransactions(int n, vector<int> arr){
    int preSum = 0;
    int maxi = 0,ind = -1;
    unordered_map<int,int>mp;
    mp.insert({0,-1});
    for(int i=0;i<n;i++)
    {
        preSum+=arr[i];
        if(mp.find(preSum) == mp.end());
        {
            mp.insert({preSum,i});
        }
        if(i-mp[preSum]>maxi)
        {
            maxi=i-mp[preSum];
            ind=mp[preSum]+1;
        }
    }
    if(ind == -1)return {-1};

    int x = 0;
    vector<int>ans;
    while(x<maxi)
    {
        ans.push_back(arr[ind+x]);
        x++;
    }

    return ans;
}


int main(){
    
    int n;
    cin>>n;

    vector<int> transactions(n);
    for(auto &i:transactions) {
        cin>>i;
        assert (i != 0);
    }

    vector<int> result = dailyTransactions(n, transactions);
    
    for(auto i: result) {
        cout<<i<<" ";
    }
}
