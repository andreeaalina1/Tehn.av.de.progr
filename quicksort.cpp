#include <iostream>
using namespace std;

int imparte(int v[], int stg, int dr) {
    int pivot = v[dr];
    int i = stg - 1;
    for (int j = stg; j <= dr - 1; j++) {
        if (v[j] < pivot) {
            i++;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    int aux = v[i + 1];
    v[i + 1] = v[dr];
    v[dr] = aux;
    
    return i + 1;
}

void quickSort(int v[], int stg, int dr) {
  
    if (stg < dr) {
   
        int pi = imparte(v, stg, dr);
        quickSort(v, stg, pi - 1);
        quickSort(v, pi + 1, dr);
    }
}
void afiseazaVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int v[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    
    cout << "Vector init: ";
    afiseazaVector(v, n);
    
    quickSort(v, 0, n - 1);
    
    cout << "Vector sort: ";
    afiseazaVector(v, n);
    
    return 0;
}