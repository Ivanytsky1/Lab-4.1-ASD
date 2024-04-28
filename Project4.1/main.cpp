#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to fill the array with elements of a geometric progression
void fillArray(vector<double>& arr, double firstTerm, double commonRatio, int currentIndex, int N) {
    if (currentIndex == N) {
        return;
    }

    arr[currentIndex] = firstTerm * pow(commonRatio, currentIndex);
    fillArray(arr, firstTerm, commonRatio, currentIndex + 1, N);
}

// Function to calculate the sum of elements in the array
double calculateSum(const vector<double>& arr, int currentIndex) {
    if (currentIndex < 0) {
        return 0;
    }

    return arr[currentIndex] + calculateSum(arr, currentIndex - 1);
}

// Tail recursion function to sort the array
void tailRecursionSort(vector<double>& arr, int endIndex) {
    if (endIndex <= 1) {
        return;
    }

    for (int i = 0; i < endIndex - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    tailRecursionSort(arr, endIndex - 1);
}

// Linear recursion function to sort the array
void linearRecursionSort(vector<double>& arr, int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return;
    }

    for (int i = startIndex; i < endIndex; i++) {
        if (arr[startIndex] > arr[i]) {
            swap(arr[startIndex], arr[i]);
        }
    }

    linearRecursionSort(arr, startIndex + 1, endIndex);
}

int main() {
    int N;
    double firstTerm, commonRatio;

    cout << "Enter the size of the array (100 < N < 1000): ";
    cin >> N;

    cout << "Enter the first term of the geometric progression: ";
    cin >> firstTerm;

    cout << "Enter the common ratio of the geometric progression: ";
    cin >> commonRatio;

    vector<double> arr(N);
    fillArray(arr, firstTerm, commonRatio, 0, N);

    cout << "Array elements:" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using tail recursion
    tailRecursionSort(arr, N);

    cout << "Array elements sorted using tail recursion:" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using linear recursion
    linearRecursionSort(arr, 0, N);

    cout << "Array elements sorted using linear recursion:" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Calculate and print the sum of the progression
    double sum = calculateSum(arr, N - 1);
    cout << "Sum of the progression: " << sum << endl;

    return 0;
}
