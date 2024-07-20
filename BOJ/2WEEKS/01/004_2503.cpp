#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> v;
string number, s, b;
int n, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number >> s >> b;
		v.push_back({ number,s,b });
	}

	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			for (int c = 1; c <= 9; c++) {
				
				// 같은 숫자 제외
				if (a == b || b == c || c == a) continue;

				int count = 0;
				for (int i = 0; i < n; i++) {
					string num = v[i][0]; //number
					
					// 문자열 숫자를 정수형으로 변환. atoi(s.c_str())
					int strike = atoi(v[i][1].c_str()); //s
					int ball = atoi(v[i][2].c_str()); //b

					int strike_cnt = 0; //init
					int ball_cnt = 0; //init

					// strike count
					if (a == num[0] - '0') strike_cnt++;
					if (b == num[1] - '0') strike_cnt++;
					if (c == num[2] - '0') strike_cnt++;
					
					// ball count
					if (a == num[1] - '0' || a == num[2] - '0') ball_cnt++;
					if (b == num[0] - '0' || b == num[2] - '0') ball_cnt++;
					if (c == num[0] - '0' || c == num[1] - '0') ball_cnt++;

					
					if (strike == strike_cnt && ball == ball_cnt) count++;
				}
				
				// n번 모두 만족한다면 현재 a, b, c는 정답일 가능성이 있다
				if (count == n) ret++;
			}
		}
	}
	cout << ret;

	return 0;
}
