#include <bits/stdc++.h>




int main(void)
{

        ll n;
        cin>>n;
        ll temp;
        cin>>temp;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            cin>>temp;
            ans=ans^temp;
        }
        cout<<ans<<en;

  return 0;

}

