#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> affordable;
vector<vector<string>> v;
string number, s, b;
int n;

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == 3) { //3개의 숫자로 게임을 진행한다
        affordable.push_back(v);

        return;
    }

    for (int i = start + 1; i <= 9; i++) { //1~9까지의 수 중에서 중복을 제외하고 뽑는다
        if (visited[i]) continue;

        v.push_back(i);
        visited[i] = true;

        combi(start, v, visited);

        v.pop_back();
        visited[i] = false;
    }

    return;
}

void search() {
    vector<int> v;
    vector<bool> visited(9 + 1, false); //중복 방지

    combi(0, v, visited);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    search();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number >> s >> b;
		v.push_back({ number,s,b });
	}

	int ret = 0;
    for (vector<int> aff : affordable) {

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string num = v[i][0];
            int strike = atoi(v[i][1].c_str());
            int ball = atoi(v[i][2].c_str());
            int strike_cnt = 0;
            int ball_cnt = 0;

            if (num[0] - '0' == aff[0]) strike_cnt++;
            if (num[1] - '0' == aff[1]) strike_cnt++;
            if (num[2] - '0' == aff[2]) strike_cnt++;

            if (num[0] - '0' == aff[1] || num[0] - '0' == aff[2]) ball_cnt++;
            if (num[1] - '0' == aff[0] || num[1] - '0' == aff[2]) ball_cnt++;
            if (num[2] - '0' == aff[0] || num[2] - '0' == aff[1]) ball_cnt++;

            if (strike_cnt == strike && ball_cnt == ball) cnt++;
        }

        if (cnt == n) ret++;
    }
  	cout << ret;

    return 0;
}
