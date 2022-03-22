
#include <iomanip>
#include <iostream>

using namespace std;

void array_fill(int** A, int n) {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[j][i] = rand() % 50;
        }
    }
}
void array_output(int** A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << A[j][i] << " ";
        }
        cout << endl;
    }
}

int column_max(const int* A, int border){ //находит максимальное значение в массиве A до символа под номером border
    int max = 0;
    for (int i=0; i<border; i++) if (A[i] > max) max = A[i];
    return max;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int** A = new int* [n];
    for (int i = 0; i<n; i++) A[i] = new int [n];
    int** B = new int* [n];
    for (int i = 0; i<n; i++) B[i] = new int [n];
    array_fill(A,n);
    array_output(A,n);
    cout<<endl;
    for (int i = 0; i<n; i++) {            //итерация по столбцам
        for (int j = 0; j<n; j++) {         //итерация по строкам
            int local_max = column_max(A[i],j + 1); // нахожу максимум в той части столбца рассматриваемой
            int border = j;               //ячейки, что находится выше неё (её включая). а здесь задаю границу рассмотрения для следующего столбца
            for (int k = i + 1; border > 0 && k<n ; k++) {
                if (column_max(A[k], border) > local_max) {     //рассматриваю столбцы справа
                    local_max = column_max(A[k],border);
                }
                border--;
            }               //идея в том, что border как ползунок уменьшается на 1 при продвижении влево или вправо
            border = j;
            for (int k = i - 1; border > 0 && k>=0 ; k--) {     //теперь рассматриваем слева
                if (column_max(A[k], border) > local_max) {
                    local_max = column_max(A[k],border);
                }
                border--;
            }
            B[i][j] = local_max;
        }
    }
    array_output(B,n);
}