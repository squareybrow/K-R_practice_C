#include <stdio.h>

int bin_search(int x, int v[], int low, int high);
int bin_search_ite(int x, int v[], int n);
int bin_search_two(int x, int v[], int n);

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%i\n", bin_search(3, arr, 0, 9));
    printf("%i\n", bin_search_two(3, arr, 10));
}

int bin_search(int x, int v[], int low, int high) {
    if (low > high) return -1;

    int mid = (low + high) / 2;
    if (x < v[mid]) {
        return bin_search(x, v, low, mid - 1);
    }
    else if (x > v[mid]) {
        return bin_search(x, v, mid + 1, high);
    }
    else return mid;
}

int bin_search_ite(int x, int v[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int bin_search_two(int x, int v[], int n) {
    int low = 0, high = n - 1;
    int mid = (low + high) / 2;
    while (low < high) {
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    
    if (x == v[mid]) {
        return mid;
    }

    return -1;
}