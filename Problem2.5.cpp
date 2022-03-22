#include <iostream>

using  namespace std;

bool IsPrime (int n) {
    if (n%2 == 0) return false;
    for (int i=3; i< n; i+=2) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    int k;
    cout<<"Enter the value: "; cin>>k; cout<<endl;
    int prev_num=1, curr_num=2, counter=1, buffer;
    for (int i=0;;i++) {
        buffer = curr_num;
        curr_num += prev_num;
        prev_num = buffer;
        if (IsPrime(curr_num)) counter++;
        if (counter == k) {
            cout<<curr_num;
            break;
        }
    }
}

