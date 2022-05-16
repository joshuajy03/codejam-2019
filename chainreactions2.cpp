#include <bits/stdc++.h>
using namespace std;

typedef struct info {
    vector <int> temp;
    vector <int> values;
} info_t;


info_t dfs(info_t info, int *nums, int *links, vector <int> tree[], int current) {

    if (tree[current+1].size() == 0) {
        info.temp.push_back(nums[current]);
        return info;
    }
    for (int i = 0; i < tree[current+1].size(); i++) {
        info_t ans;
        ans = dfs(ans, nums, links, tree, tree[current+1].at(i));
        info.temp.reserve(ans.temp.size());
        info.temp.insert(info.temp.end(), ans.temp.begin(), ans.temp.end());
        info.values.reserve(ans.values.size());
        info.values.insert(info.values.end(), ans.values.begin(), ans.values.end());
    }
    int removeVal = nums[current];
    int removeIndex = -1;
    int removeVal2 = info.temp.at(0);
    int removeIndex2 = 0;
    for (int i = 0; i < info.temp.size(); i++) {
        if (info.temp.at(i) < removeVal) {
            removeVal = info.temp.at(i);
            removeIndex = i;
        }
        if (info.temp.at(i) < removeVal2) {
            removeVal2 = info.temp.at(i);
            removeIndex2 = i;
        }
    }
    if (removeIndex != -1) {
        info.temp.erase(info.temp.begin() + removeIndex);
        info.values.reserve(info.temp.size());
        info.values.insert(info.values.end(), info.temp.begin(), info.temp.end());
        info.temp.clear();
        info.temp.push_back(nums[current]);
    } else {
        info.temp.erase(info.temp.begin() + removeIndex2);
        info.values.reserve(info.temp.size());
        info.values.insert(info.values.end(), info.temp.begin(), info.temp.end());
        info.temp.clear();
        info.temp.push_back(removeVal2);
    }
    return info;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int nums[n];
        int links[n];
        vector <int> tree[n+1];
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
            tree[j].reserve(n);
        }

        for (int j = 0; j < n; j++) {
            cin >> links[j];
            tree[links[j]].push_back(j);
        }

        long long answer = 0;
        
        for (int j = 0; j < tree[0].size(); j++) {
            info_t info;
            info_t temp = dfs(info, nums, links, tree, tree[0].at(j));
            for (int k = 0; k < temp.values.size(); k++) {
                answer += temp.values.at(k);
            }
            for (int k = 0; k < temp.temp.size(); k++) {
                answer += temp.temp.at(k);
            }
        }
        
        cout << "Case #" << i+1 << ": " << answer << endl;

    }
}
