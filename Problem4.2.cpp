

#include <iostream>
#include <stdlib.h>

using namespace std;

short int binary_number(int n, bool number_bin[], short int &latest_one) {   // в указанный адрес кладет двоичное представление числа n
    short int number_of_ones = 0;
    for (short int i=0; i<32; i++) {  //раскладываем число на 0 и 1
        int pow_of_two = pow(2,i);
        number_bin[i] = ((n | pow_of_two) == n);
        if (number_bin[i]) {
            number_of_ones++;  //считаем количество единиц
            latest_one = i;  //находим номер последней единицы (чтобы в след.функцию передать size)
        }
    }
    return number_of_ones;    //возвращает количество единиц
}

bool IsArithmetic (bool A[], short int size, short int number_of_ones) {
    for (int i=1; i<=(size/2); i++) { //проверка периодов от 1 до половины длины рассм. последовательности
        short int counter=0;
        for (int j=0; j<(size - i); j++) { //проверка разрядов от 0 до (длина минус период)
            if (A[j] && A[j+i]) counter++;
        }
        if ((counter >= 2) && counter == (number_of_ones - 1)) return true;  //если номера ненулевых разрядов образуют ->
    }                                   //-> арифм.последовательность, то счетчик равен количеству единиц минус один
    return false;
}

int main() {
    setlocale(LC_ALL, "RU");
    char str_input[16] = "";
    char *err = nullptr;
    int int_input = 0, base = 0;

    cout<<"Enter the number: ";
    cin>> str_input;
    cout<<"Choose the base: ";
    cin>> base;

    int_input = strtol(str_input, &err, base);  //перевод из str в int по основанию base
    cout << int_input << endl;
    for (int curr_num_int = 7; curr_num_int < int_input; curr_num_int++) { //итерация по числам до N
        bool *curr_num_bin = new bool[32];
        short int number_of_ones = 0, latest_one = 0;
        number_of_ones = binary_number(curr_num_int, curr_num_bin, latest_one);
        if ( IsArithmetic(curr_num_bin, latest_one + 1, number_of_ones) ) {
            cout << curr_num_int << ' ';                                //вывод десят. представления
            for(int i=0;i<32;i++) cout<<curr_num_bin[i]; cout<<endl;  //вывод бинарного представления
        }
        delete[] curr_num_bin;
    }
}