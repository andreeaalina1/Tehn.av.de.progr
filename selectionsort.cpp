#include <iostream>
using namespace std;

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {

        int mini = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[mini]) {
                mini = j;
            }
        }

        int aux = v[i];
        v[i] = v[mini];
        v[mini] = aux;
    }
}

void afiseazaVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int v[] = {64, 25, 12, 22, 11};
    int n = 5;

    cout << "Vector init: ";
    afiseazaVector(v, n);

    selectionSort(v, n);

    cout << "Vector sort: ";
    afiseazaVector(v, n);

    return 0;
}