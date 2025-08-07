#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n, sum = 0;
vector<int> s;
vector<bool> usado;
vector<int> ordem;
bool achou = false;

const int p1 = 1000;
const int p2 = 10000;
int64_t codifica(int in, int a, int b){
    return 1LL * in * p1 * p2 + 1LL * a * p2 + b;
}
unordered_map<int64_t, int> usado2;

void backtracking(int in, int a, int b){
    if(achou) return;
    if(in == n){
        if(a == b){
            for(int i = 0; i < n; i++){
                cout << s[ordem[i]] << (i != (n - 1) ? ' ' : endl);
            }
            achou = true;
        }
        return;
    }
    
    if(a > sum / 2 || b > sum / 2) return;
    
    int64_t chave = codifica(in, a, b);
    if(usado2.count(chave)) return;
    usado2[chave] = true;
    
    

    for(int i = 0; i < n; i++){
        if(!usado[i]){
            usado[i] = true;
            ordem[in] = i;

            if(a <= b)
                backtracking(in + 1, a + s[i], b);
            else
                backtracking(in + 1, a, b + s[i]);
            usado[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    s.resize(n);
    usado.assign(n, false);
    ordem.resize(n);

    for(int i = 0; i < n; i++){
        cin >> s[i];
        sum += s[i];
    }

    if(sum % 2 != 0){
        cout << -1 << endl;
        return 0;
    }

    backtracking(0, 0, 0);

    if(!achou){
        cout << -1 << endl;
    }

    return 0;
}