#include <iostream>


using  namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int xn=0, sum=0, s=0;
    for (int i;;i++) {
        cin>>xn;
        if (xn==0) { sum+=s; break; }
        s+=xn; sum+=s;
    }
    cout<<sum+1;
}