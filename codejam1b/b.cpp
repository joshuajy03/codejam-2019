#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, long long> mappa;
long long dfs(long long array[][2], long long prev, long long index, long long end) {
    if (index == end ){
        return 0;
    }
    map<pair<long long, long long>, long long>::iterator it;
    it = mappa.find(make_pair(prev, index));
    if (it != mappa.end()) {
        return it->second;
    }
    long long small = abs(prev-array[index][0]);
    long long big = abs(prev-array[index][1]);
    small += dfs(array, array[index][1], index+1, end);
    big += dfs(array, array[index][0], index+1, end);
    mappa.insert(make_pair(make_pair(prev, index), min(small, big)));
    return min(small, big);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    for (int  i = 0; i < t; i++) {
        long long n, p;
        cin >> n;
        cin >> p;
        long long answer = 0;
        long long array[n][p];
        long long array2[n][2];
        for (int j = 0; j < n; j++) {
            long long minV = 1000000000;
            long long maxV = 0;
            for (int k = 0; k < p; k++) {
                long long z;
                cin >> z;
                array[j][k] = z;
                minV = min(minV, z);
                maxV = max(maxV, z);
            }
            array2[j][0] = minV;
            array2[j][1] = maxV;
            answer += array2[j][1] - array2[j][0];
        }
        answer += array2[0][0];
        answer += dfs(array2, array2[0][1], 1, n); 
        cout << "Case #" << i+1 << ": "  << answer << "\n";
        mappa.clear();
    }
}
