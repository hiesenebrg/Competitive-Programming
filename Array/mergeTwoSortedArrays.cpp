//GapMethod- generally used shell sorting

#include <vector>
#include <cmath>
using namespace std;

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b) {
    int n = a.size();
    int m = b.size();
    int total = n + m;
    int gap = (total + 1) / 2;

    while (gap > 0) {
        int i = 0, j = gap;
        while (j < total) {
            long long val_i, val_j;

            // Get value at i
            if (i < n) val_i = a[i];
            else val_i = b[i - n];

            // Get value at j
            if (j < n) val_j = a[j];
            else val_j = b[j - n];

            // Swap if needed
            if (val_i > val_j) {
                if (i < n && j < n)
                    swap(a[i], a[j]);
                else if (i < n && j >= n)
                    swap(a[i], b[j - n]);
                else
                    swap(b[i - n], b[j - n]);
            }

            i++;
            j++;
        }

        if (gap == 1) break;
        gap = (gap + 1) / 2;
    }
}
