#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        vector<int> A;
        int n,in,c,d,s;
        double t,delay;
        scanf("%d", &n);
        
        for(int i=0; i<n; i++)
        {
            cin>>in;
            A.push_back(in);
        }
        
        scanf("%d %d %d", &c, &d, &s);
        t = (double)d/s;
        
        delay = A[0];
        int diff=0;
        
        for(int i=0; i<n-1; i++)
        {
            if(A[i+1] + diff - A[i] > 0)
             {
                delay = A[i+1];
                diff=0;
            }
            else
            {
                diff = A[i+1] + diff - A[i];
            }
        }
        
        printf("%.9f\n", (delay*(c-1)));
        
    }
}
