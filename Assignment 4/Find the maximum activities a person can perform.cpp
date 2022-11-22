#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    return a.second<b.second;
}
int activitySelection(int n,vector<int> &start,vector<int> &end){
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++)
    {
        vec.push_back(make_pair(start[i],end[i]));
    }
    sort(vec.begin(),vec.end(),cmp);///sort it by the ending time
    int count = 1;
    int prev = vec[0].second;
    for(int i=1;i<n;i++)
    {
        if(vec[i].first>=prev)
        {
            count++;
            prev=vec[i].second;
        }
    }
    
    return count;
}


int main(){
    int n;
    cin>>n;
    vector<int> start(n),ending(n);
    for(int i=0;i<n;i++)
    cin>>start[i]>>ending[i];
    cout<<activitySelection(n,start,ending);
    return 0;
}