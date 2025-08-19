#include <bits/stdc++.h>

using namespace std;

/*

*/

//calcula por meio do resto se um numero e divisivel por outro na base binaria
int resto(const string& m, int n){
    int rest = 0;
    for(char c : m){
        rest = (rest * 2 + (c - '0')) % n;
    }
    return rest;
}

void backtracking(int pos, string m, string n, vector<int> inM, vector<int> inN){
   
    //se todas as casas * que estavam em M e N foram preenchidas,
    //entra para checar se valores sao validos
    if(pos == inM.size() + inN.size()){
        string M = m;
        string N = n;

        int divi = stoi(N, nullptr, 2);
        //volta pra recursao pois nenhum numero e divisivel por zero
        if(divi == 0)
            return;

        if(resto(M, divi) == 0){
            cout << M << endl;
            exit(0);
        }
        return;
    }
    if(pos < inM.size()){ //checa se e necessario preencher valores no M
        int i = inM[pos]; //pego a posicao que precisa ser preenchida
        m[i] = '0'; //coloco 0 nessa posicao
        backtracking(pos + 1, m, n, inM, inN);//
        //cout << "chegou";
        m[i] = '1';
        backtracking(pos + 1, m, n, inM, inN);
    }else{ //se n precisa no M, precisa no N
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