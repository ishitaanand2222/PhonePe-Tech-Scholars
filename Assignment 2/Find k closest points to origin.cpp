#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosestPointsToOrigin(vector<vector<int>> points, int k){
    vector<pair<int,vector<int>>>vec;
    for(int i=0;i<points.size();i++)
    {
        int x = points[i][0];
        int y = points[i][1];
        int dist = sqrt(pow((points[i][0]),2) + pow((points[i][1]),2));
        vec.push_back({dist,{x,y}});
    }
    sort(vec.begin(),vec.end());
    vector<vector<int>>ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(vec[i].second);
    }
    return ans;
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    vector<vector<int>> closestPoints = kClosestPointsToOrigin(points, k);
    for (auto point : closestPoints)
    {
        for (auto value : point)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
