#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r;
        int c;
        cin >> r >> c;
        string first = "";
        string second = "";
        string third = "";
        string fourth = "";
        for (int j = 0; j < c; j++) {
            if (j == 0) {
                first += "..";
                second += "..";
            }
            else {
                first += "+-";
                second += "|.";
            }
            third += "+-";
            fourth += "|.";
        }
        first += "+";
        second += "|";
        third += "+";
        fourth += "|";
        cout << "Case #" << i+1 << ":" << endl;
        cout << first << endl;
        cout << second << endl;
        for (int j = 1; j < r; j++) {
            cout << third << endl;
            cout << fourth << endl;
        }
        cout << third << endl;

    }
}
