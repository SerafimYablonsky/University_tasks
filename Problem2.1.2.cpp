#include <iostream>
#include <cmath>
using  namespace std;

int number(double a, int k) {
    int a1 = floor(a * pow(10,k));
    return a1%10;
}
int main() {
    setlocale(LC_ALL, "RU");
    double a; int n,i=0, delta, num;
    cout<<"Введите вещественное число a и задайте n"<<endl;
    cout<<"a = "; cin>>a; cout<<"n = "; cin>>n; cout<<"\n";
    delta = number(a,2) - number(a,1);
    num=2;

    while (i<n-2) {
        if (number(a,i+3)-number(a,2+i) == delta) num++;
        i++;
    }
    if (num==n) cout<<"Верно";
    else cout<<"Не верно";
}
