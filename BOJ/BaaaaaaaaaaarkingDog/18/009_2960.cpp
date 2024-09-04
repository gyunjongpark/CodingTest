#include<iostream>
using namespace std;

bool chae[1001];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		if (chae[i]) continue; //이미 지워졌다면 continue

		for (int j = i; j <= n; j += i) {
			if (chae[j]) continue; //이미 지워졌다면 continue

			chae[j] = true;
			cnt++;

			if (cnt == k) {
				cout << j;
        
				return 0;
			}
		}
	}

	return 0;
}
