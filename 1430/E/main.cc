#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define NIL -1
#define ull unsigned long long

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r, ull &steps)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            // increase steps
            steps += n1 - i;

            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r, ull &steps)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, steps);
        mergeSort(arr, m + 1, r, steps);

        merge(arr, l, m, r, steps);
    }
}

int main()
{
    int n;
    cin >> n;

    char str[n + 1];
    cin >> str;

    char str_rev[n + 1];
    copy(str, str + n + 1, str_rev);
    reverse(str_rev, str_rev + n);

    // mark letters position
    vector<queue<int>> mark(26, queue<int>());
    for (int i = 0; i < n; i++)
    {
        int letter = str_rev[i] - 'a';
        mark[letter].push(i);
    }

    // convert str to integer array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int letter = str[i] - 'a';
        arr[i] = mark[letter].front();
        mark[letter].pop();
    }

    // sort arr with nlog(n) algorithm, and count steps
    ull steps = 0;
    mergeSort(arr, 0, n - 1, steps);

    cout << steps << endl;

    return 0;
}