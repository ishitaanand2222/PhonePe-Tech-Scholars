#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement( vector<int>& A) {
    int n = A.size();
    vector<int>ans(n,-1);
    stack<pair<int,int>>st;
    st.push({A[0],0});
    for(int i=1;i<n;i++)
    {
        if(st.empty())
        {
            st.push({A[i],i});
            continue;
        }
        while(!st.empty() and st.top().first<A[i])
        {
            ans[st.top().second]=A[i];
            st.pop();
        }
        st.push({A[i],i});
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for ( int i = 0; i < n; i++) cin >> A[i];

    vector<int> next_larger = nextLargerElement(A);
    for ( int i = 0; i < n; i++) {
        cout << next_larger[i] << " ";
    }
}
