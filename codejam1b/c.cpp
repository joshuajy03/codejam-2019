#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    for (int  i = 0; i < t; i++) {
        cout << "00001111" << endl;
        while (true) {
            int n;
            cin >> n;
            if (n == 0) {
                break;
            }
            if (n == -1) {
                return 0;
            }
            string s = "";
            for (int i = 0; i < n; i++) {
                s+= "1";
            }
            for (int i = 0; i < 8-n; i++) {
                s+= "0";
            }
            cout << s << endl;
        }

    }
}
