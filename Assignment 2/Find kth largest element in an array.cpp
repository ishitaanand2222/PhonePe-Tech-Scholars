
#include <bits/stdc++.h>
using namespace std;

class KthLargestElementInAnArray {
public:
    int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for ( int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;
    int result = KthLargestElementInAnArray().findKthLargest(nums, k);
    cout << result;
    return 0;
}
