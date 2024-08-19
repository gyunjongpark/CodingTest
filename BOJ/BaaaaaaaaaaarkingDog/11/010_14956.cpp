#include<iostream>
using namespace std;

int side, walk;

pair<int, int> philo(int side, int walk) {
	if (side == 2) {
		switch (walk) {
		case 1:
			return { 1, 1 };
		case 2:
			return { 1, 2 };
		case 3:
			return { 2, 2 };
		case 4:
			return { 2, 1 };
		}
	}

	int half = side / 2;
	int section = half * half;

	if (walk <= section) {
		pair<int, int> rv = philo(half, walk);
		return { rv.second, rv.first };
	}
	else if (walk <= 2 * section) {
		pair<int, int> rv = philo(half, walk - section);
		return { rv.first, half + rv.second };
	}
	else if (walk <= 3 * section) {
		pair<int, int> rv = philo(half, walk - 2 * section);
		return { half + rv.first, half + rv.second };
	}
	else {
		pair<int, int> rv = philo(half, walk - 3 * section);
		return { 2 * half - rv.second + 1, half - rv.first + 1 };
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> side >> walk;

	pair<int, int> ans = philo(side, walk);

	cout << ans.first << ' ' << ans.second;

	return 0;
}
