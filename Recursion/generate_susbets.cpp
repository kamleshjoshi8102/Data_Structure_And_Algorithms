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

void generate_subset(vector<int>a,int idx,vector<int>osf)
{
    int n=a.size();
    if(idx==n)
    {
        for(auto x:osf)
        {
            cout<<x<<' ';
        }
        cout<<en;
        return;
    }
    generate_subset(a,idx+1,osf); // not taking a[idx] in current subset
    osf.pb(a[idx]);                 // pushing a[idx]
    generate_subset(a,idx+1,osf);   // taking a[idx]
}


void solve()
{
        ll n;
        cin>>n;
        vector<int> v(n);
        rep(0,n)
        {
          cin>>v[i];
        }
        vector<int>osf;
        generate_subset(v,0,osf);

}



int main(void)
{

        ios::sync_with_stdio(0);
        cin.tie(0);

      // #ifndef ONLINE_JUDGE
      //  freopen("input.txt", "r", stdin);//for input from input.txt
      //  freopen("output.txt", "w", stdout); //for Output.txt
      // #endif
       


      ll test_case=1;
 
     
      while(test_case--)
      {

        solve();
       
      }
      


  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
  return 0;

}
