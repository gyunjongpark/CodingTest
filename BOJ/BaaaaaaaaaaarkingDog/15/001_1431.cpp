#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n;
string temp;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    else {
        int a_cnt = 0, b_cnt = 0;

        for (char i : a) {
            if ('0' <= i && i <= '9') a_cnt += i - '0';
        }

        for (char i : b) {
            if ('0' <= i && i <= '9') b_cnt += i - '0';
        }

        if (a_cnt != b_cnt) {
            return a_cnt < b_cnt;
        }
        else {
            return a < b;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    while (n--) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);

    for (string s : v) {
        cout << s << '\n';
    }

    return 0;
}
