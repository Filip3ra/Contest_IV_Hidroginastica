#include <iostream>

using namespace std;



int main(int argc, char const *argv[]){

    int n, m;
    int cont = 0; // contator de inputs, usado para apresentar "Field #i:"
    char c;
    
    while(true){

        cin >> n >> m;

        if(n == 0 && m == 0)
            break;
        else if(cont != 0)
            cout << endl;

        int campo[n][m];

        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                cin >> c;
                campo[i][j] = c;
            }
        }
        
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){

                if(campo[i][j] == 42){  // verifica o entorno da mina
                    int l, c;

                    // diagonal superior esquerda
                    l = i-1;
                    c = j-1;
                    if(l >= 0 && c >= 0){
                        if(campo[l][c] == 46)       // se for '.' troca pra 1
                            campo[l][c] = 1;
                        else if(campo[l][c] != 42)  // se for número incrementa, se for '*' deixa como ta
                            campo[l][c] += 1;
                    }
                    // superior
                    l = i-1;
                    if(l >= 0){
                        if(campo[l][j] == 46)
                            campo[l][j] = 1;
                        else if(campo[l][j] != 42)
                            campo[l][j] += 1;
                    }
                    // diagonal superior direita
                    l = i-1;
                    c = j+1;
                    if(l >= 0 && c < m){
                        if(campo[l][c] == 46)
                            campo[l][c] = 1;
                        else if(campo[l][c] != 42)
                            campo[l][c] += 1;
                    }
                    // esquerda
                    c = j-1;
                    if(c >= 0){
                        if(campo[i][c] == 46)
                            campo[i][c] = 1;
                        else if(campo[i][c] != 42)
                            campo[i][c] += 1;
                    }
                    // direita
                    c = j+1;
                    if(c < m ){
                        if(campo[i][c] == 46)
                            campo[i][c] = 1;
                        else if(campo[i][c] != 42)
                            campo[i][c] += 1;
                    }
                    // diagonal inferior esquerda
                    l = i+1;
                    c = j-1;
                    if(l < n && c >= 0){
                        if(campo[l][c] == 46)
                            campo[l][c] = 1;
                        else if(campo[l][c] != 42)
                            campo[l][c] += 1;
                    }
                    // inferior
                    l = i+1;
                    if(l < n){
                        if(campo[l][j] == 46)
                            campo[l][j] = 1;
                        else if(campo[l][j] != 42)
                            campo[l][j] += 1;
                    }
                    // diagonal inferior direita
                    l = i+1;
                    c = j+1;
                    if(l < n && c < m){
                        if(campo[l][c] == 46)
                            campo[l][c] = 1;
                        else if(campo[l][c] != 42)
                            campo[l][c] += 1;
                    }

                }
                else if(campo[i][j] == 46){ // testa se é '.' e troca por 0
                    campo[i][j] = 0;
                }

            } // fim do for J

        } // fim do for I

        ++cont;
        cout << "Field #" << cont << ":\n";
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                if(campo[i][j]==42)
                    cout << "*";
                else
                    cout << campo[i][j];
            }
            cout << endl;
        }
    } // fim while
     

    return 0;
}