#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long s;
    if (!(cin >> n >> s)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_len = 0;
    int left = 0;
    long long current_odd_sum = 0;

    for (int right = 0; right < n; ++right) {
        // Only odd numbers contribute to the sum
        if (a[right] % 2 != 0) {
            current_odd_sum += a[right];
        }

        // Shrink the window until the odd sum is <= S
        while (current_odd_sum > s && left <= right) {
            if (a[left] % 2 != 0) {
                current_odd_sum -= a[left];
            }
            left++;
        }

        // If the window is valid and non-empty
        if (left <= right) {
            max_len = max(max_len, right - left + 1);
        }
    }

    cout << max_len << "\n";

    return 0;
}


