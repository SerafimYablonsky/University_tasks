
#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    char fio[60] = "Иванов Иван Иванович";
    short age = 17;
    short year = 1;
    bool gender = true;
    float gpa = 8.5;
};

void array_filling (Student group[], short amount) {
    for(int i = 0; i<amount; i++) {
        char gender[15];
        cout<<"ФИО: ";
        cin>>group[i].fio;
        cout<<"Возраст: ";
        cin>>group[i].age;
        cout<<"Курс: ";
        cin>>group[i].year;
        cout<<"Пол: ";
        cin>>gender;
        if(strcmp(gender,"женский") != 0 || strcmp(gender,"Женский") != 0) group[i].gender = false;
        cout<<"Средний балл: ";
        cin>>group[i].gpa;
    }
}

void array_output(const Student group[], short amount) {
    for (int i = 0; i<amount; i++) {
        cout<<"Студент №"<< i <<endl;
        cout<<"ФИО: "<< group[i].fio <<endl;
        cout<<"Возраст: "<< group[i].age <<endl;
        cout<<"Курс: "<< group[i].year <<endl;
        cout<<"Пол: ";
        if (group[i].gender) cout<<"Мужской"<<endl;
        else cout<<"Женский"<<endl;
        cout<<"Средний балл: "<< group[i].gpa <<endl<<endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    const short amount = 5;  //количество студентов
    short year = 0;
    Student students[amount];
    array_filling (students, amount);
    cout<<"Введите курс: ";
    cin>>year;                      //курс, для которого найти неуспевающих
    float sum_of_gpas = 0;
    for (int i = 0; i < amount; i++) {
        sum_of_gpas += students[i].gpa;
    }
    float group_average = sum_of_gpas / amount;   //ищем средний балл по курсу
    short counter = 0;
    for (int i = 0; i < amount; i++) {
        if ((students[i].year == year) && (students[i].gpa < group_average)) counter++;
    }
    //array_output (students, amount);  //<-- Раскомментить, чтобы вывести данные студентов
    cout<<"На "<<year<<" курсе "<<counter<<" студентов имеют успеваемость ниже средней по курсу";
}

