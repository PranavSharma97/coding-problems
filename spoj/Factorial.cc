#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N;
        scanf("%d",&N);
        int count=0;
        while(N>=5)
        {
            count+=N/5;
            N/=5;
        }
        printf("%d\n",count);
    }
}
