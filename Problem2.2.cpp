#include <iostream>
#include <cmath>
#include <iomanip>

using  namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x = 0; double x0=0.1; int xn=1;
    double d_y=0.000001;
    cout<<fixed<<"\nВ нуле функция не существует\n"<<endl;
    for(int i=0; x<=xn; i++) {
        double y=0;
        x=x0 + i*0.1;
        int n=0;
        for (int j=1;;j+=2) {
            double delta = pow(x-1,j) * ((j+1)-j*(x-1)) / j / (j+1);
            y+=delta;n++;
            if ( abs(delta) < d_y) break;
        }
        cout<<"Для x = "<<setprecision(1)<<x<<" значение функции равно "<<setprecision(6)<<y-x+1<<endl;
        cout<<"Встроенные методы подсчета дают результат "<<log(x)-x+1<<endl;
        cout<<"Количество потребовавшихся слагаемых: "<< 2*n <<"\n"<<endl;
    }
}
