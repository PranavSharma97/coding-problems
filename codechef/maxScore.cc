#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<vector<int> > num(n, vector<int>(n,0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d", &num[i][j]);
            }
        }
        
        int max=0,last=INT_MAX;
        long long sum=0;
        
        for(int i=n-1; i>=0; i--)
        {
            max=0;
            for(int j=n-1; j>=0; j--)
            {
                if((num[i][j]>max) && (num[i][j]<last))
                {
                    max = num[i][j];
                }
            }
            
            sum+=max;
            last = max;
            if(max==0)
            {
                break;
            }
        }
        
        if(max==0)
        {
            printf("%d\n", -1);
        }
        else
        {
            printf("%lld\n", sum);
        }
        
    }
}
