#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, m, v[2000002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = n; i < n + m; i++) {
		cin >> v[i];
	}

	sort(v, v + n + m);

	for (int i = 0; i < n + m; i++) {
		cout << v[i] << ' ';
	}

	return 0;
}
