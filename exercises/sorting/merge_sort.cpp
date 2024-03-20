#include <iostream>

void print_array(int arr[], int n) {
    std::cout << "[ ";
    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int left_arr[n1];
    int right_arr[n2];

    for(int i = 0; i < n1; i++) left_arr[i] = arr[p + i - 1];

    for(int i = 0; i < n2; i++) right_arr[i] = arr[q + i];

    left_arr[n1 + 1] = -99;
    right_arr[n2 + 1] = -99;

    int i = 0, j = 0;

    for(int k = p; k < r; k++) {
        if(left_arr[i] < right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
    }
}

void merge_sort(int arr[], int start, int finish) {
    if(start < finish) {
        int med = (start + finish) / 2;
        merge_sort(arr, start, med);
        merge_sort(arr, med + 1, finish);
        merge(arr, start, med, finish);
    }
}


int main() {

    int arr[] = {5, 2, 7, 3, 1};

    print_array(arr, 4);

    merge_sort(arr, 0, 4);

    print_array(arr, 4);

    return 0;
}