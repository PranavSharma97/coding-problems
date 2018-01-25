#include"bits/stdc++.h"
using namespace std;

int eval(vector<int> c, vector<int> x, int xin, int n);
void interPolate(vector<int> x, vector<int> y);

int counterDd=0,counterEvenDd=0;
vector<int> coeff;
vector< vector <int> > mainY;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int s,c;
        cin>>s>>c;
        int in;
        vector<int> x;
        vector<int> y;
        for(int i=1; i<=s; i++)
        {
            cin>>in;
            y.push_back(in);
            x.push_back(i);
        }
        
        mainY.push_back(y);
        interPolate(x,y);
        
        for(int i=0; i<c; i++)
        {
            mainY.back().push_back(mainY.back()[0]);
        }
    
        for(int j=mainY.size()-2; j>=0; j--)
        {
            int n=mainY[j].size();
            for(int i=0; i<c; i++)
            {
                mainY[j].push_back(mainY[j][n-1] + mainY[j+1][n-1]);
                n++;
            }
        }
        
        for(int i=s; i<(s+c); i++)
        {
            cout<<mainY[0][i];
            if(i!=(s+c-1))
            {
                cout<<" ";
            }
            else
            {
                cout<<endl;
            }
        }
        
        coeff.clear();
        mainY.clear();
        counterDd=0;
        counterEvenDd=0;
        
    }
}

void interPolate(vector<int> x, vector<int> y)
{
    
    coeff.push_back(y[0]);
    
    if(y.size()==1)
    {
        return;
    }
    
    if(counterDd%2==0)
    {
        counterEvenDd++;
    
        vector<int> newY;
        int tempY;
        
        for(int i=0; i<y.size()-1; i++)
        {
            tempY = (y[i+1] - y[i]);
            newY.push_back(tempY);
        }
        
        int flag=0;
        
        for(int i=0; i<newY.size()-1; i++)
        {
            if(newY[i]!=newY[i+1])
            {
                flag=1;
                break;
            }
        }
        
        mainY.push_back(newY);
        if(flag==0)
        {
            return;
        }
        counterDd++;
        interPolate(x,newY);
        
    }
    else
    {
        vector<int> newY;
        int tempY;
        
        for(int i=0; i<y.size()-1; i++)
        {
            tempY = (y[i+1] - y[i]);
            newY.push_back(tempY);
        }
        
        int flag=0;
        
        for(int i=0; i<newY.size()-1; i++)
        {
            if(newY[i]!=newY[i+1])
            {
                flag=1;
                break;
            }
        }
        
        mainY.push_back(newY);
        if(flag==0)
        {
            return;
        }
        counterDd++;
        interPolate(x,newY);
    }
    
}

int eval(vector<int> c, vector<int> x, int xin, int n)
{
    if(n==0)
    {
        return c[0];
    }
    
    int prod = 1;
    
    for(int i=0; i<n; i++)
    {
        prod = prod * (xin - x[i]);
    }
    
    return (prod*c[n]) + eval(c,x,xin,n-1);
    
}
