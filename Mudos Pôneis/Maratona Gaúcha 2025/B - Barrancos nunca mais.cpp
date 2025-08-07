/*Exercício B
Samuel Alves Navarro

A estrategia se baseia na conservacao do volume total de solo:
1. Caso Ideal (1 nivel - Se o volume total de cubos for perfeitamente
divisivel pelo numero de celulas do terreno): O custo é o total de cubos que
precisam ser movidos de altitudes acima da média para preencher as altitudes abaixo da média.

2. Caso de (2 niveis - Se a divisao nao for exata) : Se a divisao nao for exataPara minimizar a 
diferença entre eles (segunda prioridade),
os niveis serao duas alturas consecutivas (H e H+1). A quantidade
de celulas em cada altura e determinada pela divisao e resto do
volume total. O custo mínimo é obtido ordenando as altitudes e 
mapeando as mais baixas para o nível H e as mais altas para H+1.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
    pair<ll, int> res;
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, c;
    cin >> l >> c;

    vector<vector<int>> t(l, vector<int>(c));
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> t[i][j];
        }
    }

    ll totalV = 0;
    int numC = l * c;

    //'alt' armazena todas as altitudes do terreno em um único vetor para facilita
    vector<int> alt;
    alt.reserve(numC);

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            totalV += t[i][j];
            alt.push_back(t[i][j]);
        }
    }

//verifica se e possivel aplainar o terreno em um unico nivel (isso so acontece se o volume total for multiplo do numero de celulas)
    if(totalV % numC == 0){
        ll peg = totalV / numC; //'peg' é a altura do nível final único.
        ll cump = 0;  //'cump' (cubos movidos) calcula o total de cubos a serem removidos.

        for(int alt : alt){
            if(alt > peg){
                cump += alt - peg;
            }
        }
        ll cust = cump * 10;
        res = {cust, 1}; //armazena o resultado: custo e 1 nivel.
    } 
    else{ // Caso contrario, a solucao otima tera 2 niveis.
        // As alturas otimas serao dois inteiros consecutivos: o piso da media e o piso + 1.
        ll hB = totalV / numC;//altura baixa
        ll hA = hB + 1;//altura alta
        
        //o numero de celulas na altura alta é o resto da divisao do volume total.
        ll numA = totalV % numC;
        ll numB = numC - numA;

        //para minimizar o custo, ordenamos as altitudes originais.
        sort(alt.begin(), alt.end());
        
        ll totalD = 0; // Soma total das diferenças de altura.

        //as 'numB' células mais baixas originais serao transformadas para a altura baixa (hB).
        for(int i = 0; i < numB; i++){
            totalD += abs(alt[i] - hB);
        }
        //as 'numA' celulas mais altas originais serao transformadas para a altura alta (hA).
        for(int i = numB; i < numC; i++){
            totalD += abs(alt[i] - hA);
        }
        
        //o numero de cubos movidos e a metade da soma das diferencas, pois cada movimento e contado duas vezes (remocao e adicao)
        ll cum = totalD / 2;
        ll cust = cum * 10;
        
        res = {cust, 2}; //armazena o resultado de custo e 2 niveis 
    }

    ll cust = res.first;
    int nNvls = res.second;
    
    cout << cust << " " << nNvls << endl;

    return 0;
}