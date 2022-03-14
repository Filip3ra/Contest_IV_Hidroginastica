
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
  int n, m;
  while (cin >> n >> m) {
    int a[100]{n}, k{1};    
    bool boring;

    if(m == 1 || m == 0 || m > n)
        boring = true;
    else
        boring = false;

    while(!boring && n != 1){
      if(n % m != 0){
        boring = true;
      }

      n /= m;
      a[k++] = n;
    }

    if(!boring){
      cout << a[0];
      for (int i = 1; i < k; ++i)
        cout << " " << a[i];

      cout << endl;
    }
    else
      cout << "Boring!" << endl;

  }

  return 0;
}





/*
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    int m, n, i;
    while(cin >> n >> m) {
        if(n < 2 || m == 0 || m > n){
            cout << "Boring!" << endl;
            continue;
        }
        int vet[100] = {m};
        for(i = 1; ; i++){
            if(vet[i-1] == 1){
                break;
            }
            if(vet[i-1]%n == 1){
                i = -1;
                break;
            }
            vet[i] = vet[i-1]/n;
        }
        if(i < 0)   
            cout << "Boring!" << endl;
        else{
            cout << vet[0];
            for(m = 1; m < i; m++)
                cout << " " << vet[m];
            cout << endl;
        }
    }
    return 0;
}

/*






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
                else if((vet[i]/m) == n){
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
                    cout << "Boring!" << endl;
                    break;
                }
            }
        }

        if(!boring){
            cout << vet[0];
            for(int i = 1; i < vet_size; ++i){
                cout << " " << vet[i];
            }
            cout << endl;
        } 
        vet.clear();
        boring = false;
    }


    return 0;
}
*/

//-----------------------------------

    /*

#include <stdio.h>

int main() {
    int m, n, i;
    while(scanf("%d %d", &m, &n) == 2) {
        if(n < 2 || m == 0 || m < n) {
            puts("Boring!");
            continue;
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
    }
    return 0;
}

*/