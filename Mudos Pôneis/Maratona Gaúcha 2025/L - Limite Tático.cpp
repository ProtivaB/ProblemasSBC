#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std; 


int main()
{
   ll x;
   cin >> x;
   vector<ll> v(x);
   set<ll> m;
   for(ll i = 0; i < x; i++)
   {
       cin >> v[i];
       m.insert(v[i]);
   }
   
   sort(v.begin(), v.end());
   

    ll res = INT_MAX;
    ll i = 0;
   if(v[x-1] != v[x-2])
   {
       cout << v[x-1] << endl;
       return 0;
   }
   else
   {
       int mmax = x-1;
       
       for(ll j = 0; j < x; j++)
       {
          auto k = m.upper_bound( (v[mmax] - v[j]) );
          //cout << "k " << *k << endl;
          if(k != m.end() && (*k != v[j] || v[j+1] == v[j] ))
          {
              res = min(*k + v[j], res);
          }
       }
       cout << res << endl;
       return 0;
   }
  
    cout << "-1" << endl;
    return 0;
}