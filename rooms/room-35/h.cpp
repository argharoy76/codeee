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

    int max = 0;
    int left = 0;
    long long current_odd_sum = 0;

    for (int right = 0; right < n; ++right) {
        if (a[right] % 2 != 0) {
            current_odd_sum += a[right];
        }

        while (current_odd_sum > s && left <= right) {
            if (a[left] % 2 != 0) {
                current_odd_sum -= a[left];
            }
            left++;
        }

        if (left <= right) {
            max = max(max, right - left + 1);
        }
    }

    cout << max << "\n";

    return 0;
}


