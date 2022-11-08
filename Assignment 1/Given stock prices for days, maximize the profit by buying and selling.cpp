#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
using namespace std;

class BestTimeToBuyAndSellStocks {
    public:
        // Implement Your Solution Here
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // return helper(0,1,prices,dp);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int take = 0;
                if(buy)
                {
                    take = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                else
                {
                    take = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
                }

                dp[ind][buy] = take;
            }
        }
        return dp[0][1];
        }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> prices;
    ReadMatrix<int>().OneDMatrix(n, prices);
    int result = BestTimeToBuyAndSellStocks().maxProfit(prices);
    cout << result;
    return 0;
}