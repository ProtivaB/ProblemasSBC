#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define vi vector<int> 
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    
    if(a == 1)
        cout << b << endl;
    else
    {
        int c = b - (a-1);
        cout << (int)c/a << endl;
    }

    return 0;
}