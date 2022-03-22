#include <iostream>
#include <cmath>

using  namespace std;

int number(int n) {
    int num=0;
    for (int i=0;; i++) {
        int pow_of_two = pow(2,i);
        if (pow_of_two>n) break;
        if ((n | pow_of_two) == n) num++;
    }
    return num;
}

int main() {
    setlocale(LC_ALL, "RU");
    int n, p=2, num_with_max=2; // p is the last found prime
    cout<<"Enter n: "; cin>>n;
    bool *A = new bool [n+1];
    A[0]=false; A[1]=false;
    for (int i=2; i<=n; i++) {
        A[i] = true;
    }
    cout<<p;
    while (true) {
        int i=0;
        while (pow(p,2) + i*p < n) {
            int del_num = pow(p,2) + i*p;
            A[del_num] = false;
            i++;
        }
        int copy_p = p;
        for (int j=p+1; j<n; j++) {
            if (A[j]) {
                p = j;
                break;
            }
        }
        if (number(p) > number(copy_p)) num_with_max = p;
        if (p == copy_p) break;
        cout<<' '<<p;
    }
    cout<<"\n"<<num_with_max;
}
