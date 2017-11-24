#include"bits/stdc++.h"
using namespace std;

int max(int x , int y)
{
    return x>y?x:y;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ad,s,m;
        string in;
        cin>>in;
        string a,b,ca,cb,op;
        ad = in.find("+");
        s = in.find("-");
        m = in.find("*");
        if(ad!=std::string::npos)
        {
            op="+";
            a = in.substr(0,ad);
            b = in.substr(ad+1,in.length()-ad-1);
        }
        else if(s!=std::string::npos)
        {
            op="-";
            a = in.substr(0,s);
            b = in.substr(s+1,in.length()-s-1);
        }
        else if(m!=std::string::npos)
        {
            op="*";
            a = in.substr(0,m);
            b = in.substr(m+1,in.length()-m-1);
        }
        
        ca=a;
        cb=b;
        int tempCarry=0;
        string prod(1000,'0'),sum(510,'0'),diff(510,'0');
        vector<int> carry(1000,0);
        vector<vector <int> > res(500,vector<int>(1000,-1));
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end()); 
        if(op=="*")
        {
            for(int i=0; i<b.length(); i++)
            {
                for(int j=0; j<a.length(); j++)
                {
                    int x = a[j] - 48;
                    int y = b[i] - 48;
                    
                    if(y==0)
                    {
                        carry[i+j+1] = (prod[i+j] - 48 + carry[i+j])/10 + carry[i+j+1];
                        prod[i+j] = to_string((prod[i+j] - 48 + carry[i+j])%10)[0];
                        carry[i+j] = 0;
                        res[i][j+i]=0;
                        break;
                    }
                    
                    int rem = (x*y+tempCarry)%10;
                    tempCarry = (x*y+tempCarry)/10;
                    string temp = to_string(tempCarry);
                    
                    if(j==a.length()-1 && tempCarry!=0)
                    {
                        prod[i+j+1] = temp[0];
                        res[i][i+j+1] = temp[0]-48;
                    }
                    
                    carry[i+j+1] = (prod[i+j] - 48 + rem + carry[i+j])/10 + carry[i+j+1];
                    
                    prod[i+j] = to_string((prod[i+j] - 48 + rem + carry[i+j])%10)[0];
                    carry[i+j] = 0;
                    if(j==a.length()-1 && i==b.length()-1)
                    {
                        int next = (prod[i+j+1] + carry[i+j+1] - 48)/10;
                        prod[i+j+1] = to_string((prod[i+j+1] + carry[i+j+1] - 48)%10)[0]; 
                        if(next!=0)
                        {
                            prod[i+j+2] = next + 48;
                        }
                    }
                    res[i][j+i] = rem;                
                }
                tempCarry=0;
            }
            
            reverse(prod.begin(),prod.end());
            prod.erase(0, min(prod.find_first_not_of('0'), prod.size()-1));
            cb.insert(0,"*");
            int m = max(ca.length(),cb.length());
            int f = max(m,prod.length());
            cout<<setw(f)<<ca<<endl;
            cout<<setw(f)<<cb<<endl;
            vector<int>::iterator it = find(res[0].begin(),res[0].end(),-1);
            string dash(max(cb.length(),it-res[0].begin()),'-');
            cout<<setw(f)<<dash<<endl;
            if(cb.length()!=2)
            {
                for(int i=0; i<cb.length()-1; i++)
                {
                    for(int j=f-1; j>=i; j--)
                    {
                        if(res[i][j]!=-1)
                        {
                            cout<<res[i][j];
                        }
                        else
                        {
                            cout<<" ";
                        }
                    }
                    if(i!=cb.length()-1)
                    cout<<endl;
                }
                string dash2(prod.length(),'-');
                cout<<setw(f)<<dash2<<endl;
            }
            cout<<setw(f)<<prod;
        }
        else if(op=="+")
        {
            int n = min(a.length(),b.length());
            int carry=0;
            for(int i=0; i<n; i++)
            {
                sum[i] = to_string((a[i] + b[i] - 96 + carry)%10)[0];
                carry = (a[i] + b[i] - 96 + carry)/10;
                if(a.length()==b.length())
                {
                    sum[i+1]=to_string(carry)[0];
                }
            }
            
            if(a.length()>b.length())
            {
                for(int i=n; i<a.length(); i++)
                {
                    sum[i] = to_string((a[i] - 48 + carry)%10)[0];
                    carry = (a[i] - 48 + carry)/10;
                    if(i==a.length()-1 && carry!=0)
                    {
                        sum[i+1] = to_string(carry)[0];
                    }
                }
            }
            else
            {
                for(int i=n; i<b.length(); i++)
                {
                    sum[i] = to_string((b[i] - 48 + carry)%10)[0];
                    carry = (b[i] - 48 + carry)/10;
                    if(i==b.length()-1 && carry!=0)
                    {
                        sum[i+1] = to_string(carry)[0];
                    }
                }
            }
            
            reverse(sum.begin(),sum.end());
            sum.erase(0, min(sum.find_first_not_of('0'), sum.size()-1));
            cb.insert(0,"+");
            int m = max(ca.length(),cb.length());
            int f = max(m,sum.length());
            cout<<setw(f)<<ca<<endl;
            cout<<setw(f)<<cb<<endl;
            string dash(max(cb.length(),sum.length()),'-');
            cout<<setw(f)<<dash<<endl;
            cout<<setw(f)<<sum;
        }
        else if(op=="-")
        {
            int n = a.length();
            for(int i=0; i<n; i++)
            {
                if(i<b.length())
                {    
                    if(a[i]>=b[i])
                    {
                        diff[i] = to_string((a[i] - b[i]))[0];
                    }
                    else
                    {
                        diff[i] = to_string((a[i] + 10 - b[i]))[0];
                        for(int j=i+1; j<a.length(); j++)
                        {
                            if(a[j]!='0')
                            {
                                a[j] = a[j] - 1;
                                break;
                            }
                            else
                            {
                                a[j] = '9';
                            }
                        }
                    }
                }
                else
                {
                    diff[i] = a[i];
                }
            }
            
            reverse(diff.begin(),diff.end());
            diff.erase(0, min(diff.find_first_not_of('0'), diff.size()-1));
            cb.insert(0,"-");
            int m = max(ca.length(),cb.length());
            cout<<setw(max(m,diff.length()))<<ca<<endl;
            cout<<setw(max(m,diff.length()))<<cb<<endl;
            string dash(max(cb.length(),diff.length()),'-');
            cout<<setw(max(ca.length(),diff.length()))<<dash<<endl;
            cout<<setw(max(m,diff.length()))<<diff;
        }
        
        cout<<endl<<endl;
        
    }
}








