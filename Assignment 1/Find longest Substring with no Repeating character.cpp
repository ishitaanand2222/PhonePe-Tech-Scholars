#include "../crio/cpp/io/FastIO.hpp"
#include <bits/stdc++.h>
using namespace std;

class LongestSubstringWithoutRepeatingCharacter {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char>st;
        int i=0,j=0,ans=0;
        while(j<n)
        {
            if(st.find(s[j]) == st.end())
            {
                st.insert(s[j++]);
                ans = max(ans,(int) st.size());
            }
            else
            {
                st.erase(s[i++]);
            }
        }
        return ans;
    }
};

int main() {
    FastIO();
    string s;
    getline(cin, s);
    int result =
        LongestSubstringWithoutRepeatingCharacter().lengthOfLongestSubstring(s);
    cout << result;
    return 0;
}