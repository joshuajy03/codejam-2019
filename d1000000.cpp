#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int nums[n];
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }
        sort(nums, nums + n);
        int counter = 0;
        for (int j = 0; j < n; j++) {
            if (counter + 1 <= nums[j]) {
                counter++;
            }
        }
        cout << "Case #" << i+1 << ": " << counter << endl;

    }
}
