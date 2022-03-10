#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// variaveis globais
int col;
int qtd_digitos;  // quantidade e dígitos que o número possui
int s, n;         // 'n' é o número e 's' é o tamanho dele

int conta_digitos(int num) {
   return int(log10(num) + 1);
}

void digito_1(vector<vector<string> > m, int ll, int cc){
    
    int j = col;
    int qtd_iteracoes_j = cc/qtd_digitos;
    int limit_j = j + qtd_iteracoes_j;


    int i = 0;
    for(int k = 0; k < 2; ++k){
        for(; i < s; ++i)
            m[i+1][limit_j-1] = '|';
    }

    for(int i = 0; i < ll; ++i){         // preenche a matrix com vazios
        for(j = 0; j < limit_j; ++j){
            m[i][j].push_back();
        }         
    }

    col = limit_j;
}

int main(int argc, char const *argv[]){

    


    while (cin >> s >> n){

        if(s == 0 && n == 0)
            break;

        // decubro quantos dígitos tem meu número
        qtd_digitos = conta_digitos(n);

        cout << s << " " << n << "qtd digitos = " << qtd_digitos << endl;

        // crio uma matriz com tamanho adequado as regras
        int l = (s*2)+3;
        int c = (s+2)*qtd_digitos;
        char s = ' ';

        vector<vector<string> > matrix(l); // organiza quantidade de colunas
        for ( int i = 0 ; i < l ; i++ )
            matrix[i].resize(c);

        for(int i = 0; i < l; ++i){         // preenche a matrix com vazios
            for(int j = 0; j <c; ++j){
                matrix[i][j].push_back(s);
            }         
        }

        // descubro quem são os dígitos que devo printar no display

        // faço um swhitch case para cada número
        col = 0;
            // se o dígito for 1, chama função digito_1()

        
        
    }
    

    
    return 0;
}


/*

        for(int i = 0; i < l; ++i){
            for(int j = 0; j <c; ++j){
                cout << matrix[i][j] << j << " ";
            }
            cout << endl;            
        }

*/