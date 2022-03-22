
#include <iostream>

using namespace std;

void string_insert (char string[], char sub_string[], short position) {
    short len_string = strlen(string), len_sub_string = strlen(sub_string);
    for (int i = len_string - len_sub_string - 1; i >= position ; i--) {
        string[i + len_sub_string] = string[i];                 //смещаем символы вправо по размеру подстроки
    }
    memcpy(&string[position], sub_string, len_sub_string);  //вставляем подстроку в освободившееся место
}

int main() {
    setlocale(LC_ALL, "RU");
    const short size = 100;
    char A[size] = " ", whitespace[2] = " ";
    for (short i = 0; i<size-1; i++) A[i] = ' ';//заполняем массив пробелами
    cout<<"Введите текст:"<<endl;
    cin.getline(A, size);
    A[strlen(A)] = ' ';  //метод getline добавляет '\0' после введенного, тут избавляемся от него
    for (short i = 1; i < size; i++) {
        if (A[i] == A[i-1]) {
            string_insert(A, whitespace, i);
            i += strlen(whitespace);  //смещаем индекс т.к. текст сместился вправо
        }
    }
    puts(A);
}