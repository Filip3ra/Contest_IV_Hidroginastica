#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){

    string str;
    string teclado = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while (getline(cin, str)){

        for(int i = 0; i < str.size(); ++i){       
            
            if(str[i] == ' '){
                cout << " ";
            }
            else{
                for(int j = 0; j<teclado.length(); ++j){
                    if(teclado[j] == str[i]){
                        cout << teclado[j-1];
                        break;
                    }
                }
            }                    
        }
        cout << endl;
    }

    return 0;
}