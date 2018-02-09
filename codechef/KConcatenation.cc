#include"bits/stdc++.h"
using namespace std;

long long maxNum(long long x, long long y)
{
    return x>y?x:y;
}

long long mss(vector<int> num)
{
    vector<int> mss;
    long long sum,curr;
    sum = num[0];
    mss.push_back(num[0]);
    
    for(int i=1; i<num.size(); i++)
    {
        curr = maxNum((mss[i-1]+num[i]), num[i]);
        mss.push_back(curr);
        if(curr>sum)
        {
            sum = curr;
        }
    }
    
    return sum;
    
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,k,in;
        long long sumTotal,maxSum;
        vector<int> num;
        
        scanf("%d %d", &n, &k);
        scanf("%d", &in);
        num.push_back(in);
        sumTotal = num[0];
        
        for(int i=1; i<(k>1?2*n:n); i++)
        {            
            if(i<n)
            {
                scanf("%d", &in);
                sumTotal+=in;
            }
            else
            {
                in = num[i-n];
            }
            num.push_back(in);
        }
        
        maxSum = mss(num);
        
        if(k==1 || sumTotal<=0)
        {
            printf("%lld\n", maxSum);
        }
        else
        {
            printf("%lld\n", max(maxSum, (k-2)*sumTotal + maxSum));
        }
    }
}
