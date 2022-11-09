#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class SearchInRotatedSortedArray {
  public:
    int search(vector<int>& nums, int target) {
        // Your implementation goes here
        int n = nums.size();
        int start = 0; int end = n-1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[start]<=nums[mid])
            {
                if(target>=nums[start] and target<=nums[mid])
                {
                    end = mid;
                }
                else
                {
                    start = mid+1;
                }
            }
            else if(nums[mid]<=nums[end])
            {
                if(target>=nums[mid] and target<=nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);

    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        int target;
        cin >> target;
        int result = SearchInRotatedSortedArray().search(nums, target);
        cout << result << "\n";
    }

    return 0;
}