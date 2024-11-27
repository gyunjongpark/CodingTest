#include<iostream>
#include<vector>
#include<climits> //INT_MIN
using namespace std;

int n;
int ret = INT_MIN; //정답은 2 ^ 31보다 작고, -(2 ^ 31)보다 크다
string s;
vector<int> num;
vector<char> oper;

int cal(char c, int a, int b) {
    if (c == '+') return a + b;
    if (c == '*') return a * b;
    if (c == '-') return a - b;
}

void recur(int idx, int cur) {
    if (idx == num.size() - 1) { //첫째 줄에 수식의 길이 N(1 ≤ N ≤ 19)가 주어진다
        ret = max(ret, cur);
        return;
    }

    if (idx + 1 < num.size()) {
        recur(idx + 1, cal(oper[idx], cur, num[idx + 1]));
    }

    if (idx + 2 < num.size()) {
        int temp = cal(oper[idx + 1], num[idx + 1], num[idx + 2]);
        recur(idx + 2, cal(oper[idx], cur, temp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num.push_back(s[i] - '0');
        }
        else {
            oper.push_back(s[i]);
        }
    }

    recur(0, num[0]); //반드시 첫번째 숫자부터 연산 시작

    cout << ret;

    return 0;
}
