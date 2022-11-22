#include <bits/stdc++.h>
using namespace std;

int minimumPlatforms(int n, vector<int> &arr,vector<int> &dep){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int plat = 1, maxi = 1, i = 1, j = 0;
    while(i<n and j<n)
    {
        if(arr[i]<=dep[j])
        {
            plat++;
            i++;
        }
        else
        {
            plat--;
            j++;
        }
        maxi = max(maxi,plat);
    }
    return maxi;
}


int main(){
    int n;
    cin>>n;
    vector<int> arrival(n),departure(n);
    for(int i=0;i<n;i++)
    cin>>arrival[i]>>departure[i];
    cout<<minimumPlatforms(n,arrival,departure);
    return 0;
}
