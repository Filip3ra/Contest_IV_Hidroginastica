#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    int n, contador = 0;
    int c, p, t;
    char L;

    cin >> n;
    cout << n << endl;


    while( true ){
        
        if((cin >> c >> p >> t >> L).eof())
            break;
        else if((cin >> c >> p >> t >> L) == n){
            
        }



        cout << c << " " << p << " " << t << " " << L << endl; 

        contador++;
    }

    return 0;
}