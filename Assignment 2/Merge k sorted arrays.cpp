#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>> arr){
    priority_queue<int, vector<int>, greater<int>>pq;
    int n = arr.size();
    int m = arr[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            pq.push(arr[i][j]);
        }
    }
    vector<int>ans;
    while(!pq.empty())
    {
        int top = pq.top();
        ans.push_back(top);
        pq.pop();
    }
    return ans;
}

int main(){
    int K;
    cin >> K;
    vector<vector<int>> arrays(K);
    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int j = 0; j < n; j++)
        {
            cin >> array[j];
        }
        arrays[i] = array;
    }

    vector<int> sortedArray = mergeKSortedArrays(arrays);
    for (auto i : sortedArray)
    {
        cout << i << " ";
    }
    return 0;
}