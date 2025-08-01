#include <bits/stdc++.h>

using namespace std;

int resto(const string& m, int n){
    int rest = 0;
    for(char c : m){
        rest = (rest * 2 + (c - '0')) % n;
    }
    return rest;
}

void backtracking(int pos, string& m, string& n, vector<int>& inM, vector<int>& inN){
   
    if(pos == inM.size() + inN.size()){
        string M = m;
        string N = n;

        int divi = stoi(N, nullptr, 2);
        
        if(divi == 0)
            return;

        if(resto(M, divi) == 0){
            cout << M << endl;
            exit(0);
        }
        return;
    }
    if(pos < inM.size()){
        int i = inM[pos];
        m[i] = '0';
        backtracking(pos + 1, m, n, inM, inN);
        //cout << "chegou";
        m[i] = '1';
        backtracking(pos + 1, m, n, inM, inN);
    }else{
        int i = inN[pos - inM.size()];
        n[i] = '0';
        backtracking(pos + 1, m, n, inM, inN);
        //cout<<"chegou";
        n[i] = '1';
        backtracking(pos + 1, m, n, inM, inN);
    }
}

int main(){
    string m, n;
    cin >> m >> n;

    vector<int> inM, inN;

    for(int i = 0; i < m.size(); i++)
        if(m[i] == '*') inM.push_back(i);

    for(int i = 0; i < n.size(); i++)
        if(n[i] == '*') inN.push_back(i);

    backtracking(0, m, n, inM, inN);

    return 0;
}