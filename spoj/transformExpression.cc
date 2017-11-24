#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        stack<char> pile;
        string s,result="";
        cin>>s;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==')')
            {
                result+=pile.top();
                pile.pop();
                pile.pop();
            }
            else if(s[i]=='(' || !(isalpha(s[i])))
            {
                pile.push(s[i]);
            }
            else
            {
                result+=s[i];
            }
            
        }
        
        cout<<result<<endl;
        
    }
}
