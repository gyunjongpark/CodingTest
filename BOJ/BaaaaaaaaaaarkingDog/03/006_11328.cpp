#include<iostream>
#include<algorithm> //sort
using namespace std;

string a, b;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> a >> b;
		sort(a.begin(), a.begin() + a.size());
		sort(b.begin(), b.begin() + b.size());

		if (a == b) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	}

	return 0;
}
