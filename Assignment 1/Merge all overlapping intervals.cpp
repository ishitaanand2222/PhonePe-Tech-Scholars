#include <bits/stdc++.h>
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"

using namespace std;

class MergeIntervals {
  public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& arr) {
      vector<vector<int>>ans;
      sort(arr.begin(),arr.end());
      ans.push_back(arr[0]);
      for(int i=1;i<arr.size();i++)
      {
        if(ans.back()[1]>=arr[i][0])
        {
          ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
        else
        {
          ans.push_back(arr[i]);
        }
      }
      return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums;
    ReadMatrix<int>().TwoDMatrix(n, 2, nums);
    vector<vector<int>> result = MergeIntervals().mergeIntervals(nums);
    PrintMatrix<int>().TwoDMatrix(result);
    return 0;
}
