#include <iostream>
#include <utility>
using namespace std;

int firstMissingPositive(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter the numbers: ";
        cin >> arr[i];
    }

    cout << "Smallest missing positive: " << firstMissingPositive(arr, n) << endl;

    delete[] arr;
    return 0;
}