#include <bits/stdc++.h>
using namespace std;

string reverseWordsInAString(string s){
    int n = s.size();
    int j=0;
    string ans = "";
    int lastInd = 0;
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        while(i<n and s[i] == ' ')
        {
            i++;
        }
        
        int startInd = j;
        while(i<n and s[i] != ' ')
        {
            s[j++] = s[i++];
            lastInd = j;
        }
        reverse(s.begin()+startInd,s.begin()+lastInd);
        s[j++] = ' ';
    }
    
    s.resize(lastInd);
    return s;
}


int main(){
    string str;
    getline(cin, str);
    cout<<reverseWordsInAString(str);
}

