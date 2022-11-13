#include <bits/stdc++.h>
using namespace std;

//Based on Prefix sumg
vector<int> largestSubarraySumZero(int n, vector<int> arr){
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
        //else{
        if(i-mp[preSum]>maxi)
        {
            maxi=i-mp[preSum];
            ind=mp[preSum]+1;
        }
        //}
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

    vector<int> arr(n);
    for(auto &i:arr) {
        cin>>i;
    }

    vector<int> longestSubarray = largestSubarraySumZero(n, arr);
    
    for(auto i:longestSubarray) {
        cout<<i<<" ";
    }
}
