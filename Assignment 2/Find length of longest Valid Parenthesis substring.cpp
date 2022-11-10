#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s){
    int n = s.size();
    stack<int>st;
    st.push(-1);
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if(!st.empty())
            st.pop();

            if(!st.empty())
            {
                maxi = max(maxi, i-st.top());
            }
            else
            {
                st.push(i);
            }
        }
    }
    return maxi;
}


int main(){
    string S;
    cin >> S;
    int ans = longestValidParentheses(S);
    cout << ans;
}
