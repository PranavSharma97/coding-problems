/*
ID: reachto2
PROG: ride
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include"bits/stdc++.h"
using namespace std;
int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string a,b;
    fin>>a>>b;
    long long prod1=1,prod2=1;
    for(int i=0; i<a.length(); i++)
    {
        prod1*=(a[i]-64);
    }
    for(int i=0; i<b.length(); i++)
    {
        prod2*=(b[i]-64);
    }
    
    if(prod1%47==prod2%47)
    {
        fout<<"GO"<<endl;
    }
    else
    {
        fout<<"STAY"<<endl;
    }
    
}
