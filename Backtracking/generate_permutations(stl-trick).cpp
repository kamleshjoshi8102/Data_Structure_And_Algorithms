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

vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
            
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }


void solve()
{
    ll n;
    cin>>n;
    vector<int>v(n);
    rep(0,n)
    {
        cin>>v[i];
    }
    generate_permutation(v,0);
    for(auto y:ans)
    {
        for(auto x:y)
        {
            cout<<x<<" ";
        }
        cout<<en;
    }
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
