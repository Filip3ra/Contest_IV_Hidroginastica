#include <iostream>
#include <cmath>
#include <vector>
#include <string>


using namespace std;

// variaveis globais
int col_inicial;
int qtd_digitos;  // quantidade e dígitos que o número possui
int s, n;         // 'n' é o número e 's' é o tamanho dele
int l, c, cc;

int conta_digitos(int num) {
   return int(log10(num) + 1);
}

void cima(vector<vector<string> > m){
                cout << "entrei " << endl;
    int fim = col_inicial+c;
    char traco = '-';

    cout << "fim = " << fim << endl;
    // percorro da col inicial até a quantidade de colunas para um dígito
    for(int i = 0; i < 1; ++i){ 
        for(int j = col_inicial; j < fim; ){
            cout << "rodei" << endl;
            if(j>0 && j<fim-1){
                cout << " estou aqui ";
                m[i][j].push_back('-');
            }
            
            ++j;
            col_inicial += j;
        }
    }

}

void meio(){

}

void baixo(){

}

void sup_esq(){

}

void sup_dir(){

}

void inf_esq(){

}

void inf_dir(){

}



void digito_zero(){

}
void digito_um(){
cout << ">>1" << endl;
}
void digito_dois(){

cout << ">>2" << endl;
}
void digito_tres(){

cout << ">>3" << endl;
}
void digito_quatro(){

}
void digito_cinco(){

}
void digito_seis(){

}
void digito_sete(vector<vector<string> > m){
    cima(m);
}
void digito_oito(){

}
void digito_nove(){

}

int main(int argc, char const *argv[]){   


    while (cin >> s >> n){

        if(s == 0 && n == 0)
            break;

        // decubro quantos dígitos tem meu número
        qtd_digitos = conta_digitos(n);

        // crio uma matriz com tamanho adequado as regras
        l = (s*2)+3;
        cc = (s+2)*qtd_digitos; // total de colunas ocupadas por todos os dígitos
        c = s+2;                // colunas ocupadas por um dígito
        char s = ' ';
        vector<vector<string>> matrix(cc); // organiza quantidade de colunas

        
        for ( int i = 0 ; i < l ; i++ )
            matrix[i].resize(cc);

        for(int i = 0; i < l; ++i){         // preenche a matrix com vazios
            for(int j = 0; j <cc; ++j){
                matrix[i][j].push_back(s);
            }
        }

        // descubro quem são os dígitos que devo printar no display
        string temp_str = to_string(n);            // converte um número pra string
        char const* num_array = temp_str.c_str();  // converte uma string pra um vetor char

        // acesso cada um dos dígitos que devo printar
        col_inicial = 0;
        for(int i = 0; i < temp_str.size() ; ++i){
            switch (num_array[i])
            {
            case '0':
                digito_zero();
                break;
            case '1':
                digito_um();
                break;
            case '2':
                digito_dois();
                break;
            case '3':
                digito_tres();
                break;
            case '4':
                digito_quatro();
                break;
            case '5':
                digito_cinco();
                break;
            case '6':
                digito_seis();
                break;
            case '7':
                digito_sete(matrix);
                break;
            case '8':
                digito_oito();
                break;
            case '9':
                digito_nove();
                break;
            
            default:
                break;
            }
        }

        for(int i = 0; i < l; ++i){         // preenche a matrix com vazios
            for(int j = 0; j <cc; ++j){
                cout << matrix[i][j];
            }
            cout << endl;
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