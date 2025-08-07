#include <bits/stdc++.h>
using namespace std;

vector<int> dp(42, -1);
int fibonacci(int n) 
{
    if (n <= 1) 
        return n; 
    if (dp[n] != -1) 
        return dp[n];
        
    dp[n] = fibonacci(n - 1) + fibonacci(n - 2); 
    return dp[n];
}


int main()
{
    
    int a;
    cin >> a;
    cout << fibonacci(a+1) << endl;

    return 0;
}