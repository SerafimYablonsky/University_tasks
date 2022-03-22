#include <iostream>
#include <cmath>

using  namespace std;

int factorial (int n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

int main() {
    setlocale(LC_ALL, "RU");
    int n,copy_n,num=1, fact, counter=0;
    cout<<"Введите n: "; cin>>n;
    fact = factorial(n);
    copy_n = fact;
    while ((copy_n/=10)>0) num++;
    int A[num], B[10];
    B[0]=17;
    cout<<"{ ";
    for (int i=0; i<num; i++) {
        A[i] = fact / pow(10, num - 1 - i);
        fact -= A[i] * pow(10, num - 1 - i);
        cout<<A[i]<<' ';
        B[A[i]] = A[i];
    }
    cout<<'}'<<endl;
    cout<<"Всего символов в числе: "<<num<<endl;
    for (int i=0; i<10; i++) {
        if (B[i] == i) counter++;
    }
    cout<<"Уникальных: "<<counter;
}
