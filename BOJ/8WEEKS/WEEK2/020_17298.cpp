#include<iostream>
#include<stack>
using namespace std;

int n, a[1000001], ret[1000001];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	fill(&ret[0], &ret[0] + n, -1); // init

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		while (s.size() && a[s.top()] < a[i]) { // top부터 역으로 채우기
			ret[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}
