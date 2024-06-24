#include<iostream>
#include<cmath>
using namespace std;

string n;
int sum, b; //2~36

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> b;

	for (int i = 0; i < n.size(); i++) {
		if ('A' <= n[i] && n[i] <= 'Z') { //아스키 코드 참고
			sum += (int)pow(b, n.size() - 1 - i) * (n[i] - 55);
		}
		if ('0' <= n[i] && n[i] <= '9') { //문자-숫자=48
			sum += (int)pow(b, n.size() - 1 - i) * (n[i] - 48);
		}
	}
	cout << sum;

	return 0;
}
