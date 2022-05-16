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
        vector<int> array;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            array.push_back(x);
        }
        int min = 0;
        int answer = 0;
        while (array.size() > 0) {
            if (array[0] <= array[array.size()-1]) {
                if (array[0] >= min) {
                    answer++;
                    min = array[0];
                }
                array.erase(array.begin());
            } else {
                if (array[array.size()-1] >= min) {
                    answer++;
                    min = array[array.size()-1];
                }
                array.pop_back();
            }
        }
        cout << "Case #" << i+1 << ": "  << answer << "\n";

    }
}
