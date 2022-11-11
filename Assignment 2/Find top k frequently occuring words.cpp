#include<bits/stdc++.h>
using namespace std;
struct MyComp {
	bool operator() (const pair<string,int>& a, const pair<string,int>& b) {
		if(a.second != b.second) {
			return a.second > b.second;
		}
		else {
			return a.first < b.first;
		}
	}
};
vector<string> frequentWords(vector<string>& words , int k) {
	unordered_map<string,int>mp;
	vector<string>ans;
	for(int i=0;i<words.size();i++)
	{
		mp[words[i]]++;
	}
	priority_queue<pair<string,int>,vector<pair<string,int>>,MyComp>pq;
	for(auto x:mp)
	{
		pq.push({x.first,x.second});
		if(pq.size()>k)
			pq.pop();
	} 
	while(!pq.empty())
	{
		auto t = pq.top();
		ans.push_back(t.first);
		pq.pop();
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main() {
	int n, k;
	cin >> n;
	vector<string> v(n);
	for ( int i = 0; i < n; i++) cin >> v[i];
	cin >> k;
	vector<string> ans = frequentWords(v, k);
	for ( auto it : ans) {
		cout << it << endl;
	}
}
