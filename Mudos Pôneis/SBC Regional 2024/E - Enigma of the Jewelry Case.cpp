#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define vi vector<int> 
using namespace std;
int main()
{
    int a;
    cin >> a;
    vector<vi> v(a);
    
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < a; j++)
        {
            int r; cin >> r;
            v[i].push_back(r);
        }
    }
    
    bool flag = false;
    bool flag2 = false;
    for(int i = 1; i < a; i++)
    {
        if(v[0][i] < v[0][i-1])
        {
            flag = true;
            break;
        }
    }
    for(int i = 1; i < a; i++)
    {
        if(v[i][0] < v[i-1][0])
        {
            flag2 = true;
            break;
        }
    }
    
    if(flag && flag2)
    {
        cout << "2" << endl;
    }
    else if(flag && !flag2)
    {
        cout << "1" << endl;
    }
    else if(!flag && flag2)
    {
        cout << "3" << endl;
    }
    else if(!flag && !flag2)
    {
        cout << "0" << endl;
    }
    
    
    return 0;
}