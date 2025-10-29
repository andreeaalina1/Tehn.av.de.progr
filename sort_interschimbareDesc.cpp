#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;

int v[100];
int i;
for (i = 1; i <= n; i++)
        cin>>v[i];

int j;
for (i = 1; i <= n-1; i++){
        for (j = i+1; j <= n; j++){
                if (v[i] < v[j]){
                        int aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                }
        }
}

for (i = 1; i <= n; i++)
        cout<<v[i]<<" ";
return 0;

}