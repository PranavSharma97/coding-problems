#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> start;
        int center = -1;
        vector<int> end;
        map<char,int> indices;
        
        for(int i=0; i<s.length(); i++)
        {
            if(indices.find(s[i])!=indices.end())
            {
                start.push_back(indices[s[i]]);
                end.push_back(i);
                indices.erase(s[i]);
            }
            else
            {
                indices[s[i]] = i;
            }
        }
        
        if((start.size() + end.size()) < s.length() - 1)
        {
            printf("-1");
        }
        else
        {
            for(auto item: indices)
            {
                center = item.second;
            }
            
            for(int i=0; i<start.size(); i++)
            {
                printf("%d ", start[i]+1);
            }
            
            if(center!=-1)
            {
                printf("%d ", center+1);
            }
            
            for(int i=end.size()-1; i>=0; i--)
            {
                printf("%d", end[i]+1);
                if(i!=0)
                {
                    printf(" ");
                }
            }
                        
        }
        
        printf("\n");
        
    }
}
