
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char A[100] = "", Final_string[100]="";  int i=0;
    cout<<"Enter your string:"<<endl;
    cin.getline(A, sizeof(A));

    while (i < strlen(A)) {

        char One_letter[2] = {A[i]};
        char Four_letters[5] = "";
        memset (Four_letters, A[i], 4);

        if (&A[i] == strstr(A, Four_letters)) {
            int counter = 4;
            while ( (i + counter) < strlen(A) && A[i + counter] == A[i]) {
                counter++;
            }
            char number_of_letters[2 + sizeof(char)] = "";
            sprintf(number_of_letters, "%d", counter);
            strcat(Final_string, "(");
            strcat(Final_string, number_of_letters);
            strcat(Final_string, ")");
            strcat(Final_string, One_letter);
            i += counter;
        }
        else {
            strcat(Final_string, One_letter);
            i++;
        }
    }
    puts(Final_string);
}