#include <iostream>
#include <cmath>

using  namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x0=0, dx=0.4, x=0; int xm=4,n, answer;
    cout<<"Enter n: "; cin>>n;
    cout<<"Choose the preferred calculation method. Type 0 for Horner's method and 1 for straight summation: ";
    cin>>answer; cout<<endl;
    if (answer) {
        for (int i=0; x<=xm; i++) {
            double y=0; int counter_mult = 0, counter_sum = 1;
            x=x0 + dx * i;
            for (int j=n; j>0; j--) {
                y+=pow(-1,j) * 2 * j * pow(x,j);
                counter_mult += 3 + 2*j;
                counter_sum += 1;
            }
            cout<<"\nFor x="<<x<<" y="<<y+1<<endl;
            cout<<"The number of multiplications is "<<counter_mult<<endl;
            cout<<"The number of sums is "<<counter_sum<<endl;
        }
    }
    else {
        for (int i=0; x<=xm; i++) {
            int counter_mult = 0, counter_sum = 1;
            double y = pow(-1,n) * 2 * n;
            x=x0 + dx * i;
            for (int j=n-1; j>=0; j--) {
                y = pow(-1, j) * 2 * j + x * y;
                counter_mult += 3+j ;
                counter_sum += 1;
            }
            cout<<"\nFor x="<<x<<" y="<<y+1<<endl;
            cout<<"The number of multiplications is "<<counter_mult<<endl;
            cout<<"The number of sums is "<<counter_sum<<endl;
        }
    }
}
