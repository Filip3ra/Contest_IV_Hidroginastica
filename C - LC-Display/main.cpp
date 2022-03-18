#include <iostream>
#include <cmath>
#include <vector>
#include <string>


using namespace std;

// variaveis globais
int col;
int qtd_digitos;  // quantidade e dígitos que o número possui
int s, n;         // 'n' é o número e 's' é o tamanho dele

int conta_digitos(int num) {
   return int(log10(num) + 1);
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
        int cc = (s+2)*qtd_digitos; // total de colunas ocupadas por todos os dígitos
        int c = s+2;                // colunas ocupadas por um dígito
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
        string temp_str = to_string(n);            // converte um número pra string
        char const* num_array = temp_str.c_str(); // converte uma string pra um vetor char

        // acesso cada um dos dígitos que devo printar
        for(int i = 0; i < temp_str.size() ; ++i){
            cout << "> " << num_array[i];
        }
        
        
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