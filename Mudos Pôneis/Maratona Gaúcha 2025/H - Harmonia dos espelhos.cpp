#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std; 

char trocaLetra(int c)
{
   
    switch(c)
    {
        case 'a': return 'z';
            break;
        case 'b': return 'y';
            break;
        case 'c': return 'x';
            break;
        case 'd': return 'w';
            break;
        case 'e': return 'v';
            break;
        case 'f': return 'u';
            break;
        case 'g': return 't';
            break;
        case 'h': return 's';
            break;
        case 'i': return 'r';
            break;
        case 'j': return 'q';
            break;
        case 'k': return 'p';
            break;
        case 'l': return 'o';
            break;
        case 'm': return 'n';
            break;
        case 'n': return 'm';
            break;
        case 'o': return 'l';
            break;
        case 'p': return 'k';
            break;
        case 'q': return 'j';
            break;
        case 'r': return 'i';
            break;
        case 's': return 'h';
            break;
        case 't': return 'g';
            break;
        case 'u': return 'f';
            break;
        case 'v': return 'e';
            break;
        case 'w': return 'd';
            break;
        case 'x': return 'c';
            break;
        case 'y': return 'b';
            break;
        case 'z': return 'a';
            break;
        default:
            return 0;
    }
}
int main()
{
    string s;
    cin >> s;
    int soma = 0;
    
    //int x = 'B' - 'A';
    //cout << x << endl;
    for(auto j : s)
    {
        char c = trocaLetra(j);
        soma += (c - 'a') + 1;
        //cout << c << " " << soma << endl;
    }
    
    cout << soma << endl;
    return 0;
}