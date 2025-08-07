#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){
    fastio;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> cont(101, 0);

    for(int x : a){
        for(int b = 0; b <= 100; b++){
            if(x & (1 << b)) cont[b]++;
        }
    }

    vector<int> res(n, 0);
    for(int i=0; i < n; i++){
        for(int b = 100; b >= 0; b--){
            if(cont[b] > 0){
                res[i] |= (1 << b);
                cont[b]--;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << res[i] << (i+1 == n?'\n':' ');
    }
    return 0;
}