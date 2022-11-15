#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void backtrack(int ind, vector<int>& arr, int target, vector<int>& vec)
{
    if(ind == arr.size())
    {
        if(target == 0)
        {
            ans.push_back(vec);
            return;
        }
        return;
    }
    
    if(arr[ind]<=target)
    {
        vec.push_back(arr[ind]);
        backtrack(ind,arr,target-arr[ind],vec);
        vec.pop_back();
    }
    backtrack(ind+1,arr,target,vec);
}
vector<vector<int>> combinationSum(vector<int>& arr, int target)
{
    int ind = 0;
    vector<int>vec;
    sort(arr.begin(),arr.end());
    backtrack(ind,arr,target,vec);
    
    return ans;
}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>candidates(n,0);
    for(int i=0;i<n;i++)cin>>candidates[i];

    vector<vector<int>>vec=combinationSum(candidates,target);
    if(vec.size()==0)
    {
        cout<<"NA";
    }
    for(auto x:vec)
    {
       for(auto y:x)cout<<y<<" ";
       cout<<endl;
    }

}