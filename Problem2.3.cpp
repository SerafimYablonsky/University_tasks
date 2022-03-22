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
    int n, m = 2;
    cout<<"Введите n\n"; cin>>n;
    for (int i=3; i<=n; i+=2) {
        for (int j=3; j<n; j+=2) {
            if ((i%j)==0) {
                break;
            }
            else {
                if (number(i)>number(m)) m = i;
            }
        }
    }
    cout<<m;
}