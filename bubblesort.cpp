#include <iostream>
using namespace std;
void bubbleSort(int v[], int n) {
    bool schimbat;
    for (int i = 0; i < n - 1; i++) {
        schimbat = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                schimbat = true;
            }
        }
  
        if (!schimbat)
            break;
    }
}

void afiseazaVector(int v[], int n) {
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    int v[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7; 
    
    cout << "Vector init: ";
    afiseazaVector(v, n);
    
    bubbleSort(v, n);
    
    cout << "Vector sort: ";
    afiseazaVector(v, n);
    
    return 0;
}