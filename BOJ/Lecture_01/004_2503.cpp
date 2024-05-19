#include<iostream>
#include<vector>
using namespace std;

int n, ret;
vector<vector<string>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; // n<=100

	for (int i = 0; i < n; i++) {
		string number, s, b;
		cin >> number >> s >> b; //input number,strike,ball in string
		v.push_back({ number,s,b });
	}

	//O(10^5)
	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			for (int c = 1; c < 10; c++) {
				if (a == b || b == c || c == a) continue;

				int cnt = 0;
				for (int i = 0; i < n; i++) {
					string num = v[i][0];
					int strike = atoi(v[i][1].c_str());
					int ball = atoi(v[i][2].c_str());

					int strike_cnt = 0;
					int ball_cnt = 0;

					//strike counting
					if (a == num[0] - '0') strike_cnt++;
					if (b == num[1] - '0') strike_cnt++;
					if (c == num[2] - '0') strike_cnt++;

					//ball counting
					if (a == num[1] - '0' || a == num[2] - '0') ball_cnt++;
					if (b == num[0] - '0' || b == num[2] - '0') ball_cnt++;
					if (c == num[0] - '0' || c == num[1] - '0') ball_cnt++;

					if (ball_cnt == ball && strike_cnt == strike) cnt++;
				}
				if (cnt == n) ret++;
			}
		}
	}
	cout << ret;

	return 0;
}
