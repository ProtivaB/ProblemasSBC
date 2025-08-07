/*
Exercicio E
Samuel Alves Navarro

O problema e um concurso com N candidatos e N rodadas.
Para cada candidato 'i', o objetivo é encontrar um "pivo" (indice 'j') que maximize uma pontuacao especifica

A estrategia utilizada:
1. Iterar por cada um dos N candidatos
2. Para cada candidato, testar todos os N possiveis pivos
3. A formula da pontuacao para um pivo 'j' envolve a soma dos elementos
a esquerda e a direita do pivo. Para calcular essas somas de forma
eficiente (em O(1)), usamos as tecnicas de somas prefixas e sufixas
4. Apos encontrar a pontuacao maxima e o melhor pivo para cada candidato,
uma ultima varredura determina o candidato vencedor geral, aplicando as regras de desempate
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> cand(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cand[i][j];
        }
    }
    
    //armazenam o melhor resultado para cada candidato 'i'
    vector<int> melhorPivo(n, n);
    vector<ll> maiorPontuacao(n, LLONG_MIN);

//loop principal para processar cada candidato individualmente
    for(int i = 0; i < n; i++) {
//os dois vetores sao respectivamente a de soma de prefixos e a soma de sufixo, 
//sao reiniciados para cada candidato
        vector<ll> px(n+1, 0);
        vector<ll> krl(n+1, 0);
        
        //calcula a soma de prefixo para a linha de pontuacoes do candidato 'i'
        for(int j = 1; j <= n; j++){
            px[j] = px[j-1] + cand[i][j-1] * 1LL;
        }
        //calcula a soma de sufixo para a mesma linha
        for(int j = n-1; j >= 0; j--){
            krl[j] = krl[j+1] + cand[i][j] * 1LL;
        }

        //testa cada posicao 'j' como um possivel pivo
        for(int j = 1; j <= n; j++){
            /*implementa a formula de pontuacao especifica do problema
            (n-j) e a quantidade de elementos a direita do pivo j-1
            px[j-1] e a soma dos elementos a esquerda
            krl[j] e a soma dos elementos a direita*/
            ll pontuacao = (n - j) * px[j-1] - krl[j] * 1LL;
            
//atualiza o melhor resultado para o candidato 'i' se a nova pontuacao for maior
//ou se for igual mas com um pivô de índice menor (regra de desempate)
            if(pontuacao > maiorPontuacao[i] || 
               (pontuacao == maiorPontuacao[i] && j < melhorPivo[i])){
                maiorPontuacao[i] = pontuacao;
                melhorPivo[i] = j;
            }
        }
    }

    //imprime a primeira parte da saida: o melhor pivo para cada candidato
    for(int p : melhorPivo) cout << p << " ";
    cout << endl;

    //Encontra o vencedor geral comparando as pontuacoes maximas de todos
    int vencedor = 0;
    for(int i = 1; i < n; i++){
        //desempate: se as pontuacoes forem iguais, vence o candidato de menor indice
        if(maiorPontuacao[i] > maiorPontuacao[vencedor] || 
           (maiorPontuacao[i] == maiorPontuacao[vencedor] && i < vencedor)){
            vencedor = i;
        }
    }

    //imprime a segunda parte da saida: o indice do vencedor e sua pontuacao
    cout << vencedor + 1 << " " << maiorPontuacao[vencedor] << endl;
    
    return 0;
}