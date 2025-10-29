#include <iostream>
using namespace std;

void insertionSort(int v[], int n)
{
    for (int i = 1; i < n; i++) {
        int cheie = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > cheie) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = cheie;
    }
}

void afiseazaVector(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    int v[] = { 12, 11, 13, 5, 6 };
    int n = 5;

    cout << "Vector init: ";
    afiseazaVector(v, n);

    insertionSort(v, n);

    cout << "Vector sort: ";
    afiseazaVector(v, n);

    return 0;
}