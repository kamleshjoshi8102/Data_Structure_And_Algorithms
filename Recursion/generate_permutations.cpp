#include <bits/stdc++.h>
#define ll                  long long
#define en                  '\n'
#define rep(a,b)            for(ll i=a;i<b;i++)
#define pb                  push_back
#define fr                  first
#define se                  second
#define all(v)              v.begin(),v.end()
const ll                    mod = 1e9 + 7;

using namespace std;




void generate_permutations(string s,string osf)
{
    int n=s.size();
    if(n==0)
    {
        // cout<<osf<<en;
        return;
    }
    for(int i=0;i<n;i++)
    {
        string temp="";

        temp+=s.substr(0,i);    // will give upto i
        temp+=s.substr(i+1); 
        cout<<osf+s[i]<<en;   // will give string upto its size
        generate_permutations(temp,osf+s[i]);
    }
}



void solve()
{
        string s;
        cin>>s;

        generate_permutations(s,"");

}


int main(void)
{

        ios::sync_with_stdio(0);
        cin.tie(0);

     


      ll test_case=1;
 
     
      while(test_case--)
      {

        solve();
       
      }
      


  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
  return 0;

}
