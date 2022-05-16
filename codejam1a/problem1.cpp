#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string n;
        cin >> n;
        string answer = "";
        int counter = 1;
        for (int j = 0; j < n.size()-1; j++) {
            if (n.at(j) < n.at(j+1)) {
                for (int k = 0; k < counter; k++) {
                    answer += n.at(j);
                }
                counter = 1;
            } else if (n.at(j) == n.at(j+1)) {
                counter++;
            } else {
                counter = 1;
            }
            answer += n.at(j);
        }
        answer += n.at(n.size()-1);
        
        cout << "Case #" << i+1 << ": " << answer << endl;

    }
}
