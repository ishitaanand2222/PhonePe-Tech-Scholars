#include <bits/stdc++.h>
using namespace std;

bool twoSumInSortedArray(int n, vector<int> arr, int target){
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int sum = arr[i]+arr[j];
        if(sum == target)
        return true;
        
        else if(sum > target)
        j--;

        else
        i++;
    }
    return false;
}


int main(){
    int n;
    cin>>n;
    vector<int > arr(n);
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    int target;
    cin >> target;
    bool ans = twoSumInSortedArray(n, arr, target);
    cout << (ans ? "Present" : "Not Present") << "\n";
}
