
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


