#include<iostream>
#include<vector>
using namespace std;

int n, a, b, c, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<vector<string>> numbers(n);

	for (int i = 0; i < n; i++) {
		string num, s, b; //인덱스로 자리수 비교를 위해 string type
		cin >> num >> s >> b;
		numbers[i] = { num,s,b };
	}
	
	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			for (int c = 1; c < 10; c++) {
				if (a == b || b == c || c == a) continue;

				int cnt = 0;
				for (int i = 0; i < n; i++) {
					string check = numbers[i][0];
					int strike = atoi(numbers[i][1].c_str()); //atoi(s.c_str())
					int ball = atoi(numbers[i][2].c_str());

					int strike_cnt = 0;
					int ball_cnt = 0;

					//strike counting
					if (a == check[0] - '0') strike_cnt++;
					if (b == check[1] - '0') strike_cnt++;
					if (c == check[2] - '0') strike_cnt++;

					//ball counting
					if (a == (check[1] - '0') || a == (check[2] - '0')) ball_cnt++;
					if (b == (check[0] - '0') || b == (check[2] - '0')) ball_cnt++;
					if (c == (check[0] - '0') || c == (check[1] - '0')) ball_cnt++;

					if (strike_cnt != strike) break;
					if (ball_cnt != ball) break;

					cnt++;
				}

				if (cnt == n) ret++;
			}
		}
	}
	cout << ret;
	
	return 0;
}
