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

void go(int here, int now) {
    if (here == num.size() - 1) {
        ret = max(ret, now);
        return;
    }

    go(here + 1, cal(oper[here], now, num[here + 1]));

    if (here + 2 <= num.size() - 1) {
        //뒷 연산을 괄호로 묶어서 먼저 계산
        int temp = cal(oper[here + 1], num[here + 1], num[here + 2]);
        
        //계산된 temp와 기존의 now를 연산
        go(here + 2, cal(oper[here], now, temp));
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

    go(0, num[0]);

    cout << ret;

    return 0;
}
