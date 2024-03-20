#include <iostream>

void print_array(int arr[], int n) {
    std::cout << "[ ";
    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int partition(int arr[], int first, int last) {
    int x = arr[last];
    int i = first - 1;

//    parto dal pivot fino all'inizio dell'array
    for(int j = first; j < last; j++) {
        // se l'elemento che voglio confrontare è minore del pivot lo sposto a sinistra del pivot
        if(arr[j] <= x) {
            i++;

            // inverto i due elementi
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[last];
    arr[last] = arr[i + 1];
    arr[i + 1] = tmp;

    return i + 1;
}

void quick_sort(int arr[], int first, int last) {
    if(first < last) {
        int pivot = partition(arr, first, last);
        quick_sort(arr, first, pivot - 1);
        quick_sort(arr, pivot + 1, last);
    }
}


int main() {

    int arr[] = {7, 1, 3, 6, 2, 5};

    int first_pos = 0;
    int last_pos = 5;

    print_array(arr, 5);

    quick_sort(arr, first_pos, last_pos);

    print_array(arr, 5);

    return 0;
}