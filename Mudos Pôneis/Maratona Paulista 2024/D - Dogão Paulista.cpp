#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
Ele quer todas as combinacoes de receitas possiveis desconsiderando as receitas
que nao combinam.
Para resolver essa questao foi utilizado um metodo que forma todas as combinacoes
verifica quais ingredientes estao essa scombinacoes para adicionar no vetor comb
e depois checa por meio de um vetor booleano se essa combinacao e possivel ou nao
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p, s;
    cin >> n >> m >> p >> s;
    //vetor com as combinacoes invalidas
    vector<vector<bool>> tira(21, vector<bool>(21, false));

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        tira[a][b] = true;
        tira[b][a] = true;
    }

    int count = 0;
    int total = pow(2, n);
    //forma todas as combinacoes possiveis
    for(int k = 0; k < total; k++){
        
        vector<int> comb;
        int pao = 0;
        int sal = 0;
        //monta o conjunto da receita atual
        for(int i = 0; i < n; i++){
            //verifica se o ingrendiente (i+1), esta na receita por meio de operacoes bit-a-bit
            //se o bit menos significativo for '1' depois de andar i vezes para direita
            //o ingrediente na posicao i esta na receita atual
            if((k >> i) & 1){
                int in = i + 1;
                comb.push_back(in);

                if(in >= 1 && in <= p){
                    pao++;
                }else if (in >= p+1 && in <= p+s){
                    sal++;
                }
            }
        }
        //exclui receitas com mais de um pao e salsicha
        if(pao != 1 || sal != 1)
            continue; 
        
            bool ch = false;
        //checa as receitas invalidas
        for(int i = 0; i < comb.size(); i++){
            for(int j = i + 1; j < comb.size(); j++){
                int ing1 = comb[i];
                int ing2 = comb[j];
                //acha receita invalida e marca ch = false para tirar esse receita
                if(tira[ing1][ing2]){
                    ch = true;
                    break;
                }
            }
            if(ch)
                break;
            
        }

        if(ch)
            continue;
    
        count++;
        
    }

    cout << count << endl;

    return 0;
}