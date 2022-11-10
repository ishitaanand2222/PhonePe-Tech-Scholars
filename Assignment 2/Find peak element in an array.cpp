#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int>&nums){
    int start = 0, end = nums.size()-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(mid>0 and mid<nums.size())
        {
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
            return mid;
            else if(nums[mid-1]>nums[mid])
            {
                end = mid-1;
            }
            else 
            {
                start = mid+1;
            }
        }
        if(mid == 0)
        {
            return nums[0]>nums[1] ? 0 : 1;
        }
        if(mid == nums.size()-1)
        {
            return nums[nums.size()-1]>nums[nums.size()-2] ? nums.size()-1 : nums.size()-2;     
        }
    }
    return -1;

}

int main(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(auto &x:nums)cin>>x;
    cout<<peakElement(nums)<<"\n";
}
