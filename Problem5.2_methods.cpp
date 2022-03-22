
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void array_fill_up (int *A, int size) {
    for (int i = 0; i < size; i++) A[i] = i;
}
void array_fill_up (float *A, int size) {
    for (int i = 0; i < size; i++) A[i] = i;
}
void array_fill_up (double *A, int size) {
    for (int i = 0; i < size; i++) A[i] = i;
}
void array_fill_up (char *A, int size) {
    for (int i = 0; i < size; i++) A[i] = '0' + i;
}


void array_fill_down (int *A, int size) {
    for (int i = 0; i < size; i++) A[i] = size - i;
}
void array_fill_down (float *A, int size) {
    for (int i = 0; i < size; i++) A[i] = size - i;
}
void array_fill_down (double *A, int size) {
    for (int i = 0; i < size; i++) A[i] = size - i;
}
void array_fill_down (char *A, int size) {
    for (int i = 0; i < size; i++) A[i] = 'a' + size - i;
}


void array_fill_random (int *A, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) A[i] = rand()%101;
}
void array_fill_random (float *A, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) A[i] = rand()%1001 * 0.001;
}
void array_fill_random (double *A, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) A[i] = rand()%1001 * 0.001;
}
void array_fill_random (char *A, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) A[i] = '0' + rand()%80;
}

void array_print (int *A, int size) {
    for (int i = 0; i<size; i++) cout<<A[i]<<' ';
}
void array_print (float *A, int size) {
    for (int i = 0; i<size; i++) cout<<A[i]<<' ';
}
void array_print (double *A, int size) {
    for (int i = 0; i<size; i++) cout<<A[i]<<' ';
}
void array_print (char *A, int size) {
    for (int i = 0; i<size; i++) cout<<A[i]<<' ';
}

void sort_by_simple_insert (int A[], int size) {
    int buffer = 0, counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            for (int j = 0; j < i; j++) {
                if (buffer < A[j]) {
                    for (int k = i; k > j; k--) {
                        A[k] = A[k-1];
                        counter_replace++;
                    }
                    A[j] = buffer;
                    counter_compare++;
                    break;
                }
                counter_compare++;
            }
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}
void sort_by_simple_insert (float A[], int size) {
    float buffer = 0;
    int counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            for (int j = 0; j < i; j++) {
                if (buffer < A[j]) {
                    for (int k = i; k > j; k--) {
                        A[k] = A[k-1];
                        counter_replace++;
                    }
                    A[j] = buffer;
                    counter_compare++;
                    break;
                }
                counter_compare++;
            }
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}
void sort_by_simple_insert (double A[], int size) {
    double buffer = 0;
    int counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            for (int j = 0; j < i; j++) {
                if (buffer < A[j]) {
                    for (int k = i; k > j; k--) {
                        A[k] = A[k-1];
                        counter_replace++;
                    }
                    A[j] = buffer;
                    counter_compare++;
                    break;
                }
                counter_compare++;
            }
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}
void sort_by_simple_insert (char A[], int size) {
    char buffer = 0;
    int counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            for (int j = 0; j < i; j++) {
                if (buffer < A[j]) {
                    for (int k = i; k > j; k--) {
                        A[k] = A[k-1];
                        counter_replace++;
                    }
                    A[j] = buffer;
                    counter_compare++;
                    break;
                }
                counter_compare++;
            }
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}


void sort_by_binary_insert (int A[], int size) {
    int buffer = 0, counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            short high = i, low = 0;
            while (low < high) {
                short mid = low + floor((high - low) * 0.5);
                if (buffer < A[mid]) {
                    high = mid;
                }
                else low = mid + 1;
                counter_compare++;
            }
            for (int k = i; k > low; k--) {
                A[k] = A[k - 1];
                counter_replace++;
            }
            A[low] = buffer;
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}
void sort_by_binary_insert (float A[], int size) {
    float buffer = 0;
    int counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            short high = i, low = 0;
            while (low < high) {
                short mid = low + floor((high - low) * 0.5);
                if (buffer < A[mid]) {
                    high = mid;
                }
                else low = mid + 1;
                counter_compare++;
            }
            for (int k = i; k > low; k--) {
                A[k] = A[k - 1];
                counter_replace++;
            }
            A[low] = buffer;
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}
void sort_by_binary_insert (double A[], int size) {
    double buffer = 0;
    int counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            short high = i, low = 0;
            while (low < high) {
                short mid = low + floor((high - low) * 0.5);
                if (buffer < A[mid]) {
                    high = mid;
                }
                else low = mid + 1;
                counter_compare++;
            }
            for (int k = i; k > low; k--) {
                A[k] = A[k - 1];
                counter_replace++;
            }
            A[low] = buffer;
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}
void sort_by_binary_insert (char A[], int size) {
    char buffer = 0;
    int counter_replace = 0, counter_compare = 0;
    for (int i = 1; i < size; i++) {
        if (A[i]<A[i-1]) {
            buffer = A[i];
            short high = i, low = 0;
            while (low < high) {
                short mid = low + floor((high - low) * 0.5);
                if (buffer < A[mid]) {
                    high = mid;
                }
                else low = mid + 1;
                counter_compare++;
            }
            for (int k = i; k > low; k--) {
                A[k] = A[k - 1];
                counter_replace++;
            }
            A[low] = buffer;
        }
        counter_compare++;
    }
    cout<<"Number of replacements: "<<counter_replace<<endl;
    cout<<"Number of comparisons: "<<counter_compare<<endl;
}