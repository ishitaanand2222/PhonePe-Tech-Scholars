#include <bits/stdc++.h>
using namespace std;


vector<int> findAnagrams(string s, string p)
{
	int n1 = s.size();
	int n2 = p.size();
	vector<int>ans;
	if(n1<n2)return ans;
	vector<int>mp1(26,0),window(26,0);
	for(int i=0;i<p.size();i++)
	{
		mp1[p[i]-'a']++;
		window[s[i]-'a']++;
	}
	
	if(mp1 == window)
		ans.push_back(0);
	
	for(int i=p.size();i<s.size();i++)
	{
		window[s[i]-'a']++;//taking current element into account
		window[s[i-p.size()]-'a']--;//removing the first element of the last window as we are increasing the size of the window
		if(mp1 == window)
		{
			ans.push_back(i-n2+1);
		}
	}
	return ans;
}

int main()
{
	string s, p;
	cin >> s >> p;
	vector<int> answer = findAnagrams(s, p);
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}