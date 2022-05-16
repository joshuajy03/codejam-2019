#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int ink[3][4];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> ink[j][k];
            }
        }
        int minInk[4];
        int total = 0;
        for (int j = 0; j < 4; j++) {
            minInk[j] = min(ink[0][j], min(ink[1][j], ink[2][j]));
            total += minInk[j];
        }
        int subtract = total - 1000000;
        if (total < 1000000) {
            cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl; 
        } else {
            cout << "Case #" << i+1 << ":";
            for (int j = 0; j < 4; j++) {
                if (subtract > 0) {
                    if (minInk[j] < subtract) {
                        subtract -= minInk[j];
                        minInk[j] = 0;
                    } else {
                        minInk[j] -= subtract;
                        subtract = 0;
                    }
                }
                cout << " " << minInk[j];
            }
            cout << endl;
        }
    }
}
