#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){

    int m, n;
    bool boring = false;
    vector<int> vet;
    int vet_size;
    while(cin >> n >> m) {

        if(n < 2 || m == 0 || m > n) {
            cout << "Boring!" << endl;
            boring = true;
        }

        if(!boring){
            vet.push_back(n);
            for(int i = 0; vet[i] != 1; ++i){
                if(vet[i]%m != 0){
                    cout << "Boring!" << endl;
                    boring = true;
                    break;
                }
                else if(vet[i]/m == m){
                    vet.push_back(1);
                }
                else
                    vet.push_back(vet[i]/m);
            }
            vet_size = vet.size();
        }

        

        if(!boring){
            for(int i = 1; i < vet_size; ++i){
                if(vet[i-1] < vet[i]){
                    cout << ">Boring!" << endl;
                    break;
                }
            }
        }

        if(!boring){
            for(int i = 0; i < vet_size; ++i){
                cout << vet[i] << " ";
            }
            cout << endl;
        } 
        vet.clear();
        boring = false;
    }


    return 0;
}


/*

    while(cin >> n >> m) {
        
        //
        if(n < 2 || m == 0 || m < n) {
            cout << "Boring!" << endl;
        }

        int ans[100] = {m};
        for(i = 1; ; i++) {
            if(ans[i-1] == 1)
                break;
            if(ans[i-1]%n) {
                i = -1;
                break;
            }
            ans[i] = ans[i-1]/n;
        }
        if(i < 0)   puts("Boring!");
        else {
            printf("%d", ans[0]);
            for(m = 1; m < i; m++)
                printf(" %d", ans[m]);
            puts("");
        }


        */