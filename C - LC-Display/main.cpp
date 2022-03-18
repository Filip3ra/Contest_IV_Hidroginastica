#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstddef>
#include <cstring>

using namespace std;

// variaveis globais
int col_inicial_c, col_inicial_m, col_inicial_b;
int col_inicial_dir_sup, col_inicial_dir_inf;
int col_inicial_esq_sup, col_inicial_esq_inf;
int qtd_digitos;  // quantidade e dígitos que o número possui
int s;         // 'n' é o número e 's' é o tamanho dele
string n;
int l, c, cc;

int conta_digitos(string num) {   
    //string temp_str = to_string(num);            // converte um número pra string
    //char const* num_array = temp_str.c_str();
    //size_t Size = strlen(num);
    return num.size();
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
            contador++;
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
            contador++;
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
            contador++;
        }
    }    
    return m;
}
vector<vector<string>> sup_esq(vector<vector<string> > m){

    int col = (col_inicial_esq_sup);
    int contador = 0;
    
    for(int j = col; j < col+1; ++j){
        for(int i = 1; contador<s; ++i){
            m[i][j].pop_back();
            m[i][j].push_back('|');
            contador++;
        }
    }
    return m;
}
vector<vector<string>> sup_dir(vector<vector<string> > m){

    int col = (col_inicial_dir_sup+c)-1;
    int contador = 0;
    
    for(int j = col; j < col+1; ++j){ 
        for(int i = 1; i <= s; ++i){
            if(contador<s){
                m[i][j].pop_back();
                m[i][j].push_back('|');
            }
            contador++;
        }
    }
    return m;
}
vector<vector<string>> inf_esq(vector<vector<string> > m){

    int col = (col_inicial_esq_inf);
    int contador = 0;
    int lin = ((l-1)/2)+1;
    
    for(int j = col; j < col+1; ++j){
        for(int i = lin; contador<s; ++i){
            m[i][j].pop_back();
            m[i][j].push_back('|');
            contador++;
        }
    }
    return m;
}
vector<vector<string>> inf_dir(vector<vector<string> > m){

    int col = (col_inicial_dir_inf+c)-1;
    int contador = 0;
    int lin = ((l-1)/2)+1;
    for(int j = col; j < col+1; ++j){ 
        for(int i = lin; contador < s; ++i){
            m[i][j].pop_back();
            m[i][j].push_back('|');
            contador++;
        }
    }
    return m;
}

vector<vector<string>> digito_zero(vector<vector<string> > m){
    
    m = cima(m);
    m = baixo(m);
    m = sup_dir(m);
    m = inf_dir(m);
    m = sup_esq(m);
    m = inf_esq(m);
    return m;
}
vector<vector<string>> digito_um(vector<vector<string>> m){
    m = sup_dir(m);
    m = inf_dir(m);
    return m;
}
vector<vector<string>> digito_dois(vector<vector<string> > m){
    m = cima(m);
    m = meio(m);
    m = baixo(m);
    m = sup_dir(m);
    m = inf_esq(m);
    return m;
}
vector<vector<string>> digito_tres(vector<vector<string>> m){
    m = cima(m);
    m = meio(m);
    m = baixo(m);
    m = sup_dir(m);
    m = inf_dir(m);
    return m;
}
vector<vector<string>> digito_quatro(vector<vector<string> > m){
    m = meio(m);
    m = sup_dir(m);
    m = inf_dir(m);
    m = sup_esq(m);
    return m;
}
vector<vector<string>> digito_cinco(vector<vector<string> > m){
    m = cima(m);
    m = meio(m);
    m = baixo(m);
    m = inf_dir(m);
    m = sup_esq(m);
    return m;
}
vector<vector<string>> digito_seis(vector<vector<string> > m){
    m = meio(m);
    m = baixo(m);
    m = inf_dir(m);
    m = sup_esq(m);
    m = inf_esq(m);
    return m;
}
vector<vector<string>> digito_sete(vector<vector<string> > m){

    m = cima(m);
    m = sup_dir(m);
    m = inf_dir(m);
    return m;
}
vector<vector<string>> digito_oito(vector<vector<string> > m){
    m = cima(m);
    m = meio(m);
    m = baixo(m);
    m = sup_dir(m);
    m = inf_dir(m);
    m = sup_esq(m);
    m = inf_esq(m);
    return m;
}
vector<vector<string>> digito_nove(vector<vector<string> > m){
    m = cima(m);
    m = meio(m);
    m = baixo(m);
    m = sup_dir(m);
    m = inf_dir(m);
    m = sup_esq(m);
    return m;
}

int main(int argc, char const *argv[]){   


    while (cin >> s >> n){

        if(s == 0 && n == "0")
            break;

        // decubro quantos dígitos tem meu número
        qtd_digitos = conta_digitos(n);
        //cout << qtd_digitos << "<--";

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
                //cout << " *";
            }
            //cout << endl;
        }

        // descubro quem são os dígitos que devo printar no display
        //string temp_str = to_string(n);            // converte um número pra string
        char const* num_array = n.c_str();  // converte uma string pra um vetor char

        // variávis que auxiliam no posicionamento da matriz 
        col_inicial_c = col_inicial_m = col_inicial_b = 0;
        col_inicial_dir_sup = col_inicial_dir_inf = 0;
        col_inicial_esq_sup = col_inicial_esq_inf = 0;

        // acesso cada um dos dígitos que devo printar
        for(int i = 0; i < n.size() ; ++i){

            if(i!=0){
                col_inicial_c += c;
                col_inicial_m += c;
                col_inicial_b += c;
                col_inicial_dir_sup += c;
                col_inicial_dir_inf += c;
                col_inicial_esq_sup += c;
                col_inicial_esq_inf += c;
            }

            switch (num_array[i])
            {
            case '0':
                matrix = digito_zero(matrix);
                break;
            case '1':
                matrix = digito_um(matrix);
                break;
            case '2':
                matrix = digito_dois(matrix);
                break;
            case '3':
                matrix = digito_tres(matrix);
                break;
            case '4':
                matrix = digito_quatro(matrix);
                break;
            case '5':
                matrix = digito_cinco(matrix);
                break;
            case '6':
                matrix = digito_seis(matrix);
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
        
        matrix.clear();        
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






           
        cout << "linhas " << l << endl;
        cout << "colunas totais " << cc << endl;
        cout << "colunas " << c << endl;

*/