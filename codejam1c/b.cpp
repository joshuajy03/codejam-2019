#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    for (int  i = 0; i < t; i++) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        long long answer = 0;
        long long answer2 = 0;
        for (int j = 0; j < n; j++) {
            long long x;
            cin >> x;
            answer += x;
            answer2 += x*x;
        }
        if (answer*answer == answer2) {
            cout << "Case #" << i+1 << ": "  << 0 << "\n";
            continue;
        }
        bool possible = false;
        for (long long j = -1000000000; j < 1000000000; j++) {
            long long first = answer+j;
            first = exp2(first) - exp2(j);
            if (first == answer2) {
                possible = true;
                cout << "Case #" << i+1 << ": "  << j << "\n";
                break;
            }
        }
        if (possible == false) {
            cout << "Case #" << i+1 << ": "  << "IMPOSSIBLE" << "\n";
        }

    }
}
