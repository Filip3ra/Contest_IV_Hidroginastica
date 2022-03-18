#include <iostream>
#include <cmath>
#include <vector>
#include <string>


using namespace std;

// variaveis globais
int col_inicial_c, col_inicial_m, col_inicial_b;
int qtd_digitos;  // quantidade e dígitos que o número possui
int s, n;         // 'n' é o número e 's' é o tamanho dele
int l, c, cc;

int conta_digitos(int num) {
   return int(log10(num) + 1);
}

vector<vector<string>> cima(vector<vector<string> > m){

    int fim = col_inicial_c+c;
    int contador = 0;

    // percorro da col inicial até a quantidade de colunas para um dígito
    for(int i = 0; i < 1; ++i){ 
        for(int j = col_inicial_c; j < fim; ++j){
            if(contador>0 && j<fim-1){
                m[i][j].pop_back();
                m[i][j].push_back('-');
            }
            contador ++;
        }
    }
    
    return m;
}

vector<vector<string>> meio(vector<vector<string> > m){

    int fim = col_inicial_m+c;
    int contador = 0;

    // percorro da col inicial até a quantidade de colunas para um dígito
    int lin = (l-1)/2;
    for(int i = lin; i < lin+1; ++i){ 
        for(int j = col_inicial_c; j < fim; ++j){
            if(contador>0 && j<fim-1){
                m[i][j].pop_back();
                m[i][j].push_back('-');
            }
            contador ++;
        }
    }
    
    return m;
}

vector<vector<string>> baixo(vector<vector<string> > m){

    int fim = col_inicial_b+c;
    int contador = 0;
    
    for(int i = l-1; i < l; ++i){ 
        for(int j = col_inicial_b; j < fim; ++j){
            if(contador>0 && j<fim-1){
                m[i][j].pop_back();
                m[i][j].push_back('-');
            }
            contador ++;
        }
    }    
    return m;
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
vector<vector<string>> digito_sete(vector<vector<string> > m){

    m = cima(m);

    return m;
}
vector<vector<string>> digito_oito(vector<vector<string> > m){
    m = cima(m);
    m = meio(m);
    m = baixo(m);
    return m;
}
vector<vector<string>> digito_nove(vector<vector<string> > m){
    m = cima(m);
    m = meio(m);
    m = baixo(m);
    return m;
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

        // variávis que auxiliam no posicionamento da matriz 
        col_inicial_c = col_inicial_m = col_inicial_b = 0;

        // acesso cada um dos dígitos que devo printar
        for(int i = 0; i < temp_str.size() ; ++i){

            if(i!=0){
                col_inicial_c += c;
                col_inicial_m += c;
                col_inicial_b += c;
            }

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
                matrix = digito_sete(matrix);
                break;
            case '8':
                matrix = digito_oito(matrix);
                break;
            case '9':
                matrix = digito_nove(matrix);
                break;
            
            default:
                break;
            }
        }

        for(int i = 0; i < l; ++i){
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