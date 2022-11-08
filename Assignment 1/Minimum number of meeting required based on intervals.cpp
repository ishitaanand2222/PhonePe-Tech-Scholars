#include<bits/stdc++.h>
using namespace std;

int meetingRooms(int n, vector<vector<int>>& time){
    vector<int>arr(n);
    vector<int>dep(n);
    for(int i=0;i<n;i++)
    {
        arr[i] = time[i][0];
        dep[i] = time[i][1];
    }
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int i=1,j=0,plat=1,maxi = 1;
    while(i<n and j<n)
    {
        if(arr[i]<dep[j])//indicates that the ith meeting has to start and ith meeting is not over yet
        {
            plat++;
            i++;
        }
        else//indicates that the jth meeting is now over
        {
            plat--;
            j++;
        }
        maxi = max(maxi, plat);
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>time(n);
    for (int i = 0; i < n; i++)
    {
        int s,e;
        cin>>s>>e;
        time[i].push_back(s);
        time[i].push_back(e);
    }
    int ans = meetingRooms(n,time);
    cout<<ans;
}
