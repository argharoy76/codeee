Subarray Odd Sum
Time limit: 1 second • Memory limit: 256 MB
You are given an array A consisting of N integers and an integer S.
Your task is to find the maximum length of a contiguous subarray such that the sum of all odd
numbers within that subarray does not exceed S.
Note that even numbers within the subarray do not contribute to the odd sum constraint, but
they are included in the length of the subarray. If a subarray has a sum of odd elements greater
than S, it is considered invalid.
Input
The first line contains two integers N and S (1 ≤ N ≤ 2 · 105

, 0 ≤ S ≤ 1014), the number of

elements in the array and the maximum allowed sum of odd elements.
The second line contains N integers A1, A2, . . . , AN (1 ≤ Ai ≤ 109
).

Output
Print a single integer representing the maximum length of a contiguous subarray whose sum of
odd elements is less than or equal to S.
If there is no valid subarray, print 0.
Examples
Sample Input 1 Sample Output 1
5 10
2 5 3 4 1

5

Sample Input 2 Sample Output 2
3 5
7 9 11

0

Notes
In the first sample, consider the entire array [2, 5, 3, 4, 1]. The odd elements are 5, 3, and 1, and
their sum is 5 + 3 + 1 = 9. Since 9 ≤ 10, the entire array is valid, and its length is 5.
In the second sample, every element is odd and strictly greater than S = 5 (7 > 5, 9 > 5,
11 > 5). Any non-empty subarray contains at least one of these elements, so its odd sum is at
least 7, which exceeds 5. Hence no non-empty subarray is valid, and the answer is 0.

7





#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
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

g
