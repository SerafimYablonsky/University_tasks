#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using  namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n, length;
    cout<<"Введите n: "; cin>>n;
    length = pow(n,2);
    int A[length], B[length];
    for (int i=0; i<n; i++) {
        srand(time(0) + i + 4);
        A[i*(n+1)]=rand()%18 - 9;
        for (int j=1; j<n-i; j++) {
            srand(time(0)+i+j*length);
            int floor_index = i*(n+1);
            A[floor_index + j] = rand()%18 - 9;
            A[floor_index + j + j*(n-1)] = A[floor_index + j];
        }
    }
    for (int i=0; i<n; i++) {
        srand(time(0) + i + 30);
        B[i*(n+1)]=rand()%18 - 9;
        for (int j=1; j<n-i; j++) {
            srand(time(0)+i+j*length + 25);
            int floor_index = i*(n+1);
            B[floor_index + j] = rand()%18 - 9;
            B[floor_index + j + j*(n-1)] = B[floor_index + j];
        }
    }
    for(int k=0; k<length; k++) {
        cout<<A[k]<<' ';
        if (((k+1) % n) == 0) cout<<endl;
    }
    cout<<endl;
    for(int k=0; k<length; k++) {
        cout<<B[k]<<' ';
        if (((k+1) % n) == 0) cout<<endl;
    }
    int B_squared[length];
    for (int k=0; k<length; k++) {
        B_squared[k]=0;
    }
    for (int row=0; row<n; row++) {
        for(int line=0; line<n; line++) {
            for (int index=0; index<n; index++) {
                B_squared[row + line*n] += (B[index + line*n] * B[row + index*n]);
            }
        }
    }
    cout<<endl;
    for(int k=0; k<length; k++) {
        cout<<B_squared[k]<<' ';
        if (((k+1) % n) == 0) cout<<endl;
    }
    int C[length];
    for (int index=0; index<length; index++) {
        C[index] = A[index] + B_squared[index];
    }
    cout<<endl;
    for(int k=0; k<length; k++) {
        cout<<C[k]<<' ';
        if (((k+1) % n) == 0) cout<<endl;
    }
}