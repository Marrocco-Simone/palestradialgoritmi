#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int i, int m, int f)
{
    int n1 = m - i + 1;
    int n2 = f - m;

    int L[n1], R[n2];

    for (int x = 0; x < n1; x++)
        L[x] = arr[i + x];
    for (int y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y];

    int x = 0, y = 0, z = i;

    while (x < n1 && y < n2)
    {
        if (L[x] <= R[y])
        {
            arr[z] = L[x];
            x++;
        }
        else
        {
            arr[z] = R[y];
            y++;
        }
        z++;
    }

    while (x < n1)
    {
        arr[z] = L[x];
        x++;
        z++;
    }

    while (y < n2)
    {
        arr[z] = R[y];
        y++;
        z++;
    }
}

void mergeSort(int arr[], int i, int f)
{
    if (i < f)
    {
        int m = i + (f - i) / 2;

        mergeSort(arr, i, m);
        mergeSort(arr, m + 1, f);

        merge(arr, i, m, f);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
}
