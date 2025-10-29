#include <iostream>
using namespace std;

void countingSort(int v[], int n) {
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > maxi) {
            maxi = v[i];
        }
    }

    int count[maxi + 1];
    for (int i = 0; i <= maxi; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[v[i]]++;
    }

    for (int i = 1; i <= maxi; i++) {
        count[i] += count[i - 1];
    }

    int sort[n];
    for (int i = n - 1; i >= 0; i--) {
        sort[count[v[i]] - 1] = v[i];
        count[v[i]]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = sort[i];
    }
}

void afiseazaVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    int v[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = 8;

    cout << "Vector init: ";
    afiseazaVector(v, n);

    countingSort(v, n);

    cout << "Vector sort: ";
    afiseazaVector(v, n);

    return 0;
}