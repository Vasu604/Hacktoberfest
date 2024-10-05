#include <iostream>
using namespace std;

// Function to calculate the maximum sum of subarray of size k
int maxSumOfSubarray(int arr[], int n, int k) {
    if (n < k) {
        cout << "Invalid: The array size is smaller than the window size." << endl;
        return -1;
    }

    // Calculate the sum of the first window
    int maxSum = 0;
    for (int i = 0; i < k; i++)
        maxSum += arr[i];

    int windowSum = maxSum;

    // Slide the window from the start to the end of the array
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];  // Add next element and remove the first element of the previous window
        maxSum = max(maxSum, windowSum);   // Update maximum sum if current window is larger
    }

    return maxSum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = maxSumOfSubarray(arr, n, k);
    if (result != -1)
        cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;

    return 0;
}
