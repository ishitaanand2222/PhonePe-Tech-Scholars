#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;


class ContainerWithMostWater {
  public:
    // Complete the function implementation below
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int left=0,right=height.size()-1;
        while(left<right)
        {
            int ht = min(height[left], height[right]);
            ans = max(ans, ht*(right-left));

            while(left<right and height[left]<=ht)left++;
            
            while(left<right and height[right]<=ht)right--;
        }
        return ans;
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> height;
    ReadMatrix<int>().OneDMatrix(n, height);
    int result = ContainerWithMostWater().maxArea(height);
    cout << result;
    return 0;
}
