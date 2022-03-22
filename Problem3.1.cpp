#include <iostream>
#include <cstdlib>
#include <ctime>

using  namespace std;

enum Choice {
    INIT = 1,
    ASSIGN = 2,
    ENTER = 3,
};

bool IsPeriodic (const int A[], int size) {
    for (int i=1; i<=size/2; i++) {
        int counter=0;
        for (int j=0; j<(size - i); j++) {
            if (A[j]==A[j+i]) counter++;
        }
        if (counter == size - i) return true;
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    cout<<"Choose your preferred initialization type: \nType '1' for initialization while declaring,"
          "\nType '2' for random values assignment,\nType '3' if you want to enter the values manually"<<endl;
    cin>>choice;
    if (choice == INIT) {
        int A[6] = {12, 13, 12, 13, 12, 13};
        IsPeriodic(A, 6)? cout<<"Periodic": cout<<"Non-periodic";
    }
    else if (choice == ASSIGN) {
        int n;
        cout<<"Choose the length of your array: "; cin>>n;
        int B[n];
        srand(time(0));
        for (int i=0; i<n; i++) {
            B[i] = rand() % 100 + 1;
        }
        cout<<"{ ";
        for (int i=0; i<n; i++) {
            cout<<B[i]<<' ';
        }
        cout<<'}'<<endl;
        IsPeriodic(B, n)? cout<<"Periodic": cout<<"Non-periodic";
    }
    else if (choice == ENTER) {
        int n;
        cout<<"Choose the length of your array: "; cin>>n;
        int C[n];
        for (int i=0; i<n; i++) {
            cin>>C[i];
        }
        IsPeriodic(C, n)? cout<<"Periodic": cout<<"Non-periodic";
    }
}