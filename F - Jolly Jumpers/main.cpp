#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    int i, j, n, diferenca, a[100], b[100];
    
    cin >> n;

    for(i = 0; i <n; ++i){
        b[i] = 0;
    }

    for(i = 0; i<n; ++i){
        cin >> a[i];
    }

    int ansFound = 0;
    for(i = 0; i<n-1; ++i){
        diferenca = abs(a[i] - a[i+1]);
        cout << "->" << diferenca << endl;
        if(diferenca>n-1){
            cout << "Not jolly" << endl;
            ansFound = 1;
            break;
        }
        else{
            b[diferenca] = 1;
        }
    }

    if(!ansFound){
        for(i = 1; i<n-1; ++i){
            
                cout << b[i] << " ";
            if(b[i] != 1){
                cout << "Not jolly" << endl;
                ansFound = 1;
                break;
            }
        }
        cout << endl;
        if(!ansFound){
            cout << " Jolly" << endl;
        }
    }


    

    return 0;
}