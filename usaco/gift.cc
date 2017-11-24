/*
ID: reachto2
PROG: gift1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include"bits/stdc++.h"
using namespace std;
int main()
{
    map<string,int> money;
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    vector<string> order;
    int m,n,mon;
    fin>>n;
    string name,giver,taker;
    for(int i=0; i<n; i++)
    {
        fin>>name;
        order.push_back(name);
        money[name]=0;
    }
    
    for(int i=0; i<n; i++)
    {
        fin>>giver>>mon>>m;
        if(m==0){
            continue;
        }
        for(int j=0; j<m; j++)
        {
            fin>>taker;
            money[taker]+=(mon/m);
        }    
        money[giver]+=(mon%m)-mon;
    }
    
    for(int i=0; i<n; i++){
        fout<<order[i]<<" "<<money[order[i]]<<endl;
    }
    
}
