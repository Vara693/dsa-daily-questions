// Given an sorted array arr[] of integers. Sort the array into a wave-like array 
// (In Place). In other words, arrange the elements into a sequence 
// such that : arr[0] ≥ arr[1] ≤ arr[2] ≥ arr[3] ≤ arr[4] ≥ ... and so on. 
// If there are multiple solutions, find the lexicographically smallest one.

// Note: The given array is sorted in ascending order, and modify the given array 
// in-place without returning a new array.

void sortInWave(int *arr, int n) {
    // code here
    for (int i =1; i<n; i+=2) {
        int tmp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = tmp;
    }
}