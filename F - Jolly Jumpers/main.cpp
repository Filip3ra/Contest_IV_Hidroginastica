#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    int i, j, n, diferenca, sequencia[3001], vet_bits[3001];
    
    cin >> n;

    for(i = 0; i<n; ++i)
        vet_bits[i] = 0;

    for(i = 0; i<n; ++i)
        cin >> sequencia[i];

    bool condicao = false;
    for(i = 0; i<n-1; ++i){
        diferenca = abs(sequencia[i] - sequencia[i+1]);
        if(diferenca > n-1){
            cout << "Not jolly" << endl;
            condicao = true;
            break;
        }
        else
            vet_bits[diferenca] = 1;
    }

    if(!condicao){
        for(i = 1; i<n-1; ++i){
            if(vet_bits[i] != 1){
                cout << "Not jolly" << endl;
                condicao = true;
                break;
            }
        }
        if(!condicao)
            cout << "Jolly" << endl;
    }

    return 0;
}