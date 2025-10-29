#include <iostream>
using namespace std;
void combine(int v[], int stg, int mijl, int dr) {
    int n1 = mijl - stg + 1;
    int n2 = dr - mijl;
    int stgAux[n1], drAux[n2];
    for (int i = 0; i < n1; i++)
        stgAux[i] = v[stg + i];
    for (int j = 0; j < n2; j++)
        drAux[j] = v[mijl + 1 + j];

    int i = 0, j = 0;
    int k = stg;

    while (i < n1 && j < n2) {
        if (stgAux[i] <= drAux[j]) {
            v[k] = stgAux[i];
            i++;
        }
        else {
            v[k] = drAux[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = stgAux[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = drAux[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int stg, int dr) {
    if (stg >= dr)
        return;

    int mijl = stg + (dr - stg) / 2;
    mergeSort(v, stg, mijl);
    mergeSort(v, mijl + 1, dr);
    combine(v, stg, mijl, dr);
}

void afiseazaVector(int v[], int n) {
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    int v[] = {38, 27, 43, 10};
    int n = 4;

    cout << "Vector init: ";
    afiseazaVector(v, n);

    mergeSort(v, 0, n - 1);

    cout << "Vector sort: ";
    afiseazaVector(v, n);

    return 0;
}