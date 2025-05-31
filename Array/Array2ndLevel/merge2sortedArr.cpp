void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int i = m - 1;        // Last valid element in v1
    int j = n - 1;        // Last element in v2
    int k = m + n - 1;    // Last index in v1 (after expansion)

    // Merge from the back of the arrays
    while (i >= 0 && j >= 0) {
        if (v1[i] > v2[j]) {
            v1[k--] = v1[i--]; // Place element from v1 in its correct position
        } else {
            v1[k--] = v2[j--]; // Place element from v2 in its correct position
        }
    }

    // If there are any remaining elements in v2, copy them
    while (j >= 0) {
        v1[k--] = v2[j--];
    }
}

/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/