
#include "Problem5.2_methods.cpp"

template <typename T>
T * array_creation (int size) {
    T * array = new T[size];
    return array;
}

int main() {
    setlocale(LC_ALL, "RU");
    short n;
    cout<<"Enter the size of array: ";
    cin>>n;
    auto array_int = array_creation<int>(n);
    auto array_float = array_creation<float>(n);
    auto array_double = array_creation<double>(n);
    auto array_char = array_creation<char>(n);
    short datatype_choice;
    cout<<"Choose data type. Type: 1-int, 2-float, 3-double, 4-char. ";
    cin>>datatype_choice;
    short mode_choice;
    cout<<"Select filling mode. Type: 1-Up, 2-Down, 3-Random. ";
    cin>>mode_choice;
    switch (datatype_choice) {
        case 1:
            if (mode_choice == 1) array_fill_up(array_int,n);
            else if (mode_choice == 2) array_fill_down(array_int,n);
            else if (mode_choice == 3) array_fill_random(array_int,n);
            break;
        case 2:
            if (mode_choice == 1) array_fill_up(array_float,n);
            else if (mode_choice == 2) array_fill_down(array_float,n);
            else if (mode_choice == 3) array_fill_random(array_float,n);
            break;
        case 3:
            if (mode_choice == 1) array_fill_up(array_double,n);
            else if (mode_choice == 2) array_fill_down(array_double,n);
            else if (mode_choice == 3) array_fill_random(array_double,n);
            break;
        case 4:
            if (mode_choice == 1) array_fill_up(array_char,n);
            else if (mode_choice == 2) array_fill_down(array_char,n);
            else if (mode_choice == 3) array_fill_random(array_char,n);
            break;
    }
    short sort_mode_choice;
    cout<<"Choose sorting mode. 1-simple insertions, 2-binary search insertions: ";
    cin>>sort_mode_choice;
    switch (sort_mode_choice) {
        case 1:
            if(datatype_choice == 1) sort_by_simple_insert(array_int, n);
            else if(datatype_choice == 2) sort_by_simple_insert(array_float,n);
            else if(datatype_choice == 3) sort_by_simple_insert(array_double,n);
            else if(datatype_choice == 4) sort_by_simple_insert(array_char,n);
            break;
        case 2:
            if(datatype_choice == 1) sort_by_binary_insert(array_int, n);
            else if(datatype_choice == 2) sort_by_binary_insert(array_float,n);
            else if(datatype_choice == 3) sort_by_binary_insert(array_double,n);
            else if(datatype_choice == 4) sort_by_binary_insert(array_char,n);
            break;
    }
    if(datatype_choice == 1) array_print(array_int, n);
    else if(datatype_choice == 2) array_print(array_float,n);
    else if(datatype_choice == 3) array_print(array_double,n);
    else if(datatype_choice == 4) array_print(array_char,n);
}