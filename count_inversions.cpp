#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0;  
    int j = 0; // Initial index of second subarray
    int k = left;  
    int count = 0;  

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            count += (n1 - i);
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return count;
}

int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSortAndCount(arr, left, mid);

        count += mergeSortAndCount(arr, mid + 1, right);

        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

int main() {
    vector<int> arr = {10, 20, 30, 35, 40, 50};
    
    int n = arr.size();
    
    int inversionCount = mergeSortAndCount(arr, 0, n - 1);
    
    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}