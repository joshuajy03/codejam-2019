#include <bits/stdc++.h>
using namespace std;

string Answer = "";
set<vector<int>> works;
vector<pair<string, int>> strings;
vector<int> in;
bool concat(string answer) {
    if (works.find(in) != works.end()) {
        return false;
    }
    if (strings.size() == 0) {
        set<char> contain;
        for (int i = 1; i < answer.size(); i++) {
            if (answer[i-1] != answer[i]){
                contain.insert(answer[i-1]);
            }
            if (contain.find(answer.at(i)) != contain.end()) {
                return false;
            }
        }
        Answer = answer;
        return true;
    }
    for (int i = 0; i < strings.size(); i++) {
        if (strings[i].first.at(strings[i].first.length()-1) == answer.at(0)) {
            pair<string, int> temp = strings[i];
            strings.erase(strings.begin()+i);
            in.insert(in.begin(), temp.second);
            if (concat(temp.first + answer)) {
                strings.insert(strings.begin()+i, temp);
                return true;
            } else {
                works.insert(in);
            }
            in.erase(in.begin());
            strings.insert(strings.begin()+i, temp);
        } else if (strings[i].first.at(0) == answer.at(answer.length()-1)) {
            pair<string, int> temp = strings[i];
            in.push_back(temp.second);
            strings.erase(strings.begin()+i);
            if (concat(answer + temp.first)) {
                strings.insert(strings.begin()+i, temp);
                return true;
            } else {
                works.insert(in);
            }
            in.pop_back();
            strings.insert(strings.begin()+i, temp);
        } else {
            pair<string, int> temp = strings[i];
            strings.erase(strings.begin()+i);
            bool found = false;
            for (int j = 0; j < temp.first.length(); j++) {
                if (answer.find(temp.first.at(j)) != std::string::npos) {
                    found = true;
                }
            }
            if (found == false) {
                in.push_back(temp.second);
                if (concat(answer + temp.first)) {
                    strings.insert(strings.begin()+i, temp);
                    return true;
                } else {
                    works.insert(in);
                }
                in.pop_back();
                in.insert(in.begin(), temp.second);
                if (concat(temp.first + answer)) {
                    strings.insert(strings.begin()+i, temp);
                    return true;
                } else {
                    works.insert(in);
                }
                in.erase(in.begin());
            }

            strings.insert(strings.begin()+i, temp);
        }
    }
    works.insert(in);
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int  i = 0; i < t; i++) {
        int n;
        cin >> n;
        Answer = "";
        for (int j = 0; j < n; j++) {
            string add;
            cin >> add;
            strings.push_back(make_pair(add, j));
        }
        vector<string> temp;
        for (int j = 0; j < strings.size(); j++) {
            string temp2 = strings.at(j).first;
            char temp3 = temp2.at(0);
            int k = 0;
            while(k < temp2.size()) {
                if (temp2.at(k) == temp3) {
                    temp2 = temp2.substr(1, temp2.length());
                }
                break;
            }
            
            temp3 = temp2.at(temp2.length()-1);
            while(true) {

            }
        }
        Answer = strings[0].first;
        strings.erase(strings.begin());
        bool poosible = true;
        
        if (concat(Answer)) {
            cout << "Case #" << i+1 << ": "  << Answer << "\n";
        } else {
            cout << "Case #" << i+1 << ": "  << "IMPOSSIBLE" << "\n";
        }
        in.clear();
        strings.clear();
        works.clear();
    }
}
