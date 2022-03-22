
#include <iostream>

using namespace std;

double reference_result = 0;

enum Choice {
    RETURN = 1,
    POINTER = 2,
    REFERENCE = 3,
};

double sum (int x, int n, double *result, double& ref = reference_result) {
    double y = 0, last_addend = 0, x_pow_n = 1, factorial_n = 1;
    const double epsilon = 0.000001;
    int counter = 0;

    for(int i = 1; i<=n; i++) {   //находим x в степени n и факториал n для оптимизации вычислений
        x_pow_n *= x;
        factorial_n *= i;
    }
    last_addend = - x * x * x_pow_n / factorial_n / (n + 1); //хранит последнее слагаемое, здесь кладем начальное (k=1)
    for (int k = 2; ; k++) {
        double delta = last_addend * (-1) * x * x / (n+k) / k;
        y += delta;
        last_addend = delta;
        counter++;
        if ( abs(delta) < epsilon) break;
    }
    if (result != nullptr) *result = y;
    ref = y;
    cout<<counter<<endl; //кол-во операций сложения
    return y;
}


int main() {
    int x = 0, n = 0, choice = 0;
    cout<<"Choose the output method. Enter 1 for return, 2 for pointer, 3 for reference"<<endl;
    cin>>choice;
    cout<<"Enter x and n:"<<endl;
    cin>>x>>n;
    if (choice == RETURN) {
        cout<<sum(x,n,nullptr);
    }
    else if (choice == POINTER) {
        double y = 0;
        sum(x,n,&y);
        cout<<y;
    }
    else if (choice == REFERENCE) {
        double y = 0;
        sum(x,n, nullptr, y);
        cout<<y;
    }
}