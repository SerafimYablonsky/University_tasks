
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char A[50]="",  Message[50]="";
    cout<<"Enter your string:"<<endl;
    cin.getline(A, sizeof(A));
    char *word = strtok(A," ");
    while (word) {
        int len = strlen(word);
        int counter = 0;  // Вычисляем количество "оболочек" вокруг b, т.е. кол-во символов в a(c)
        while (counter < (len/2) && word[counter] == word[len - 1 - counter]) {
            counter++;
        }
        char Middle_word[50] = "";
        memcpy(Middle_word, &word[counter], len - 2 * counter);
        strcat(Message, Middle_word);
        strcat(Message, " ");
        word = strtok(NULL, " ");
    }
    puts(Message);
}