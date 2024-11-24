#include<iostream>
#include<vector>
#include<algorithm> //sort
#include<string> //to_string
using namespace std;

int n, check[10];
char a[20];
vector<string> ret;

bool isCorrect(char a, char b, char op) {
    if (a < b && op == '<') return true;
    if (a > b && op == '>') return true;

    return false;
}

void recur(int idx, string num) {
    if (idx == n + 1) {
        ret.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue; //선택된 숫자는 모두 달라야 한다

        if (idx == 0 || isCorrect(num[idx - 1], i + '0', a[idx - 1])) {
            check[i] = 1;

            recur(idx + 1, num + to_string(i));

            check[i] = 0;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    recur(0, "");

    sort(ret.begin(), ret.end());

    //모든 입력에 답은 항상 존재하며, 출력 정수는 하나의 문자열이 되도록 해야 한다
    cout << ret[ret.size() - 1] << '\n' << ret[0]; //ret.size() >= 1

    return 0;
}
