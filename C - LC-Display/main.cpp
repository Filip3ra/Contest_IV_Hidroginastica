#include <iostream>
#include <cmath>

using namespace std;

int conta_digitos(int num) {
   return int(log10(num) + 1);
}

int main(int argc, char const *argv[]){

    int s, n;         // 'n' é o número e 's' é o tamanho dele
    int qtd_digitos;  //

    while (cin >> s >> n){

        if(s == 0 && n == 0)
            break;

        // decubro quantos dígitos tem meu número
        qtd_digitos = conta_digitos(n);

        // crio uma matriz com tamanho adequado as regras

        
        cout << s << " " << n << "qtd digitos = " << qtd_digitos << endl;
    }
    

    
    return 0;
}


