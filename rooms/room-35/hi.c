#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    int64 S;
    cin >> S;

    vector<int64> W(N);
    for (auto &x : W) cin >> x;

    vector<int64> B(M);
    for (auto &x : B) cin >> x;

    vector<int64> D(Q);
    for (auto &x : D) cin >> x;

    // Step 1: Longest contiguous subarray with sum <= S
    int L = 0;
    int left = 0;
    int64 sum = 0;

    for (int right = 0; right < N; ++right) {
        sum += W[right];

        while (left <= right && sum > S) {
            sum -= W[left];
            ++left;
        }

        L = max(L, right - left + 1);
    }

    cout << L << '\n';

    // Step 2: Sort swords for binary search
    sort(B.begin(), B.end());

    int64 multiplier = (int64)L + 1;

    for (int j = 0; j < Q; ++j) {
        // Smallest base damage x satisfying:
        // x * multiplier >= D[j]
        //
        // ceil(D[j] / multiplier)
        int64 required = (D[j] + multiplier - 1) / multiplier;

        auto it = lower_bound(B.begin(), B.end(), required);

        if (it == B.end())
            cout << -1;
        else
            cout << *it;

        if (j + 1 < Q)
            cout << ' ';
    }

    cout << '\n';

    return 0;
}
