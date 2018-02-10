#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,m,x,k;
        int evenLimit,oddLimit,evenWorkers=0,oddWorkers=0,total=0;
        string workerMonths;
        scanf("%d %d %d %d", &n, &m, &x, &k);
//         scanf("%s", &workerMonths);
        cin>>workerMonths;
        
        evenLimit = (m/2)*x;
        oddLimit = (m - evenLimit/x)*x;
        
        for(int i=0; i<workerMonths.length(); i++)
        {
            if(workerMonths[i]=='E')
            {
                evenWorkers++;
            }
            else
            {
                oddWorkers++;
            }
        }
        
        if(evenWorkers>=evenLimit)
        {
            total = evenLimit;
        }
        else
        {
            total = evenWorkers;
        }
        
        if(oddWorkers>=oddLimit)
        {
            total += oddLimit;
        }
        else
        {
            total += oddWorkers;
        }
        
        if(total>=n)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        
    }
}
