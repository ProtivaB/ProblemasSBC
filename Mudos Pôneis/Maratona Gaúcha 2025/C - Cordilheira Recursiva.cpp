/*
Exercicio C
Samuel Alves Navarro
O problema consiste em estabilizar uma cordilheira circular de montanhas,
a regra de estabilidade e que uma montanha não pode ser mais do que 1 unidade
mais alta que suas vizinhas diretas (altura[i] <= altura[vizinho] + 1)

Dado isso, foi utilizada em abordagem de BFS(Busca em Largura) para resolver o problema, 
utilizando dos seguintes ideias:
1. Todos os picos sao inicialmente adicionados a uma fila para verificacao
2. Um pico e retirado da fila e sua altura e comparada com a de seus vizinhos
3. Se o pico for "alto demais", sua altura e reduzida para o máximo permitido
4. Como essa reducao pode fazer com que os picos vizinhos agora violem a regra,
eles sao adicionados de volta à fila para serem re-avaliados
5. O processo termina quando a fila fica vazia, o que significa que toda
a cordilheira esta estavel e nenhuma outra altura precisa ser reduzida
O objetivo final e encontrar a maior altitude apos a estabilizacao
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin >> n;

    vector<int> montanha(n);
    for(int i = 0; i < n; i++){
        cin >> montanha[i];
    }

    queue<int> fila;
    vector<bool> usados(n, true);

    for(int i = 0; i < n; i++) fila.push(i);

    //o loop continua enquanto houver picos potencialmente instaveis.
    while(!fila.empty()){
        int i = fila.front(); fila.pop();
        usados[i] = false; //marca que o pico 'i' nao esta mais na fila.

        //pega as alturas dos vizinhos esquerdo e direito de forma circular.
        int esq = montanha[(i - 1 + n) % n];
        int dir = montanha[(i + 1) % n];

        //se a montanha 'i' for mais alta do que o permitido por qualquer um dos vizinhos...
        if(montanha[i] > esq + 1 || montanha[i] > dir + 1){
            
            // ...sua altura e reduzida para o maximo valor estavel possivel
            montanha[i] = min(montanha[i], min(esq + 1, dir + 1));

            //como a altura de 'i' mudou, seus vizinhos precisam ser reverificados
            int vizEsq = (i - 1 + n) % n;
            int vizDir = (i + 1) % n;

            //adiciona o vizinho da direita na fila se ele ja nao estiver la.
            if(!usados[vizDir]){
                fila.push(vizDir);
                usados[vizDir] = true;
            }
        }
    }
    //apos a estabilizacao, ordena as alturas para encontrar a maior
    sort(montanha.begin(), montanha.end());
    cout << montanha[n - 1] << endl;

    return 0;
}