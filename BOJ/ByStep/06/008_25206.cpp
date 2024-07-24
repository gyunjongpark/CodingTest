#include<iostream>
using namespace std;

string majorName, input;
double sum, avg, grade[20], score[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	for (int i = 0; i < 20; ++i) {
		cin >> majorName >> grade[i] >> input;

		if (input == "A+") score[i] = 4.5;
		else if (input == "A0") score[i] = 4.0;
		else if (input == "B+") score[i] = 3.5;
		else if (input == "B0") score[i] = 3.0;
		else if (input == "C+") score[i] = 2.5;
		else if (input == "C0") score[i] = 2.0;
		else if (input == "D+") score[i] = 1.5;
		else if (input == "D0") score[i] = 1.0;
		else if (input == "F") score[i] = 0.0;
		else if (input == "P") {
			score[i] = 0.0;
			grade[i] = 0;
		}

		avg += (score[i] * grade[i]);
		sum += grade[i];
	}
	avg = avg / sum;

	// printf("%0.4f",avg); 의 경우 cin, cout tie 사용 금지

	// 평점은 최대 4.5점이므로 정수1자리 + 소수 4자리 = precision(5)
	cout.precision(5);
	cout << avg;

	return 0;
}
