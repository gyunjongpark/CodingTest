#include<iostream>
#include<vector>
#include<algorithm> //sort
#include<string> //to_string
using namespace std;

char oper[10];
bool chk_oper[10];
int n;
vector<string> ret;

bool isCorrect(char pre, char now, char oper) {
    if (pre < now && oper == '<') return true;
    if (pre > now && oper == '>') return true;

    return false;
}

void recur(int idx, string num) {
    if (idx == n + 1) {
        ret.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (chk_oper[i]) continue; //선택된 숫자는 모두 달라야 한다

        if (idx == 0 || isCorrect(num[idx - 1], i + '0', oper[idx - 1])) {
            chk_oper[i] = true;

            recur(idx + 1, num + to_string(i));

            chk_oper[i] = false;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> oper[i];
    }

    recur(0, "");

    sort(ret.begin(), ret.end());

    //모든 입력에 답은 항상 존재하며...
    //이 문제에서 ret.size()는 1 이상이 보장된다
    //size() - 1 연산 가능
    cout << ret[ret.size() - 1] << '\n' << ret[0];

    return 0;
}
