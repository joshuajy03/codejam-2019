#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        vector<long long> a;
        vector<long long> b;
        long long sum = 0;
        long long half = 0;
        for (int j = 0; j < 30; j++) {
            a.push_back(1<<j);
            cout << (1<<j) << " ";
            half += (1<<j);
        }
        for (int j = 0; j < n-31; j++) {
            b.push_back(1000000000-j);
            cout << 1000000000-j << " ";
            half += 1000000000-j;
        }
        cout << 1000000000-69 << endl;
        half += 1000000000-69;
        for (long long j = 0; j < n; j++) {
            long long x;
            cin >> x;
            b.push_back(x);
            half += x;
        }
        sort(b.begin(), b.end(), greater<long long>());
        long long half2 = half;
        half /= 2;
        vector<long long> ans;
        for (int j = 0; j < b.size(); j++) {
            if (sum + b.at(j) <= half) {
                sum += b.at(j);
                ans.push_back(b.at(j));
            }
        }
        for (int j = a.size()-1; j >= 0; j--) {
            if (sum + a.at(j) <= half) {
                sum += a.at(j);
                ans.push_back(a.at(j));
            }
        }

        for (long long j = 0; j < ans.size()-1; j++) {
            cout << ans[j] << " ";
        }
        cout << ans[ans.size()-1] << endl;

    }
}
