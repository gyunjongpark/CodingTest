#include<iostream>
#include<vector>
#include<climits> //INT_MIN
using namespace std;

vector<int> num;
vector<char> oper;
string s;
int n;
int ret = INT_MIN;

int cal(char a, int b, int c) {
    if (a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
}

//단, 괄호 안에는 연산자가 하나만 들어 있어야 한다. O(2 ^ n)
void recur(int idx, int cur_num) {
    if (idx == num.size() - 1) {
        ret = max(ret, cur_num);
        return;
    }

    if (idx + 1 < num.size()) {
        recur(idx + 1, cal(oper[idx], cur_num, num[idx + 1]));
    }

    if (idx + 2 < num.size()) {
        //뒷 연산을 괄호로 묶어서 먼저 계산
        int temp = cal(oper[idx + 1], num[idx + 1], num[idx + 2]);

        //계산된 temp와 기존의 now를 나중에 연산
        recur(idx + 2, cal(oper[idx], cur_num, temp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num.push_back(s[i] - '0'); //숫자
        }
        else {
            oper.push_back(s[i]); //연산자
        }
    }

    recur(0, num[0]);

    cout << ret;

    return 0;
}
