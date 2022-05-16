#include <bits/stdc++.h>
using namespace std;

vector<long long> nums;

void dfs(int *links, vector <int> tree[], int current) {
    if (tree[current+1].size() == 0) {
        return; //returns if leaf
    }
    for (int i = 0; i < tree[current+1].size(); i++) {
        dfs(links, tree, tree[current+1].at(i)); //traverse tree
    }

    //find smallest child
    int removeVal = nums[tree[current+1].at(0)];
    int removeIndex = tree[current+1].at(0);
    for (int i = 0; i < tree[current+1].size(); i++) {
        if (nums[tree[current+1].at(i)] < removeVal) {
            removeIndex = tree[current+1].at(i);
            removeVal = nums[tree[current+1].at(i)];
        }
    }

    //change node values
    if (current != -1) {
        if (removeVal > nums[current]) {
            nums[current] = removeVal;
            nums[removeIndex] = 0;
        }
        else {
            nums[removeIndex] = 0;
        }
    }
    return;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int links[n];
        vector <int> tree[n+1];
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        for (int j = 0; j < n; j++) {
            cin >> links[j];
            tree[links[j]].push_back(j);
        }
        long long answer = 0;
        dfs(links, tree, -1);
        for (int j = 0; j < nums.size(); j++) {
            answer += nums[j];
        }
        
        cout << "Case #" << i+1 << ": " << answer << endl;
        nums.clear();
    }
}
