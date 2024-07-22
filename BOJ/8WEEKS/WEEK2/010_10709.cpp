#include<iostream>
using namespace std;

char a[101][101];
int h, w, ret[101][101];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			a[i][j] = s[j];
			
			if (a[i][j] == 'c') ret[i][j] = 0; // init
			else if (a[i][j] == '.') ret[i][j] = -1; // init
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 'c') {
				int cnt = 1; // c를 만나면 다시 1부터 시작

				while (a[i][j+1]=='.') {
					ret[i][j + 1] = cnt;
					cnt++; j++;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
