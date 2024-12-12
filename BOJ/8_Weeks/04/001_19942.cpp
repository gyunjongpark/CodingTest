#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

struct info {
	int p, f, s, v, c;
};
vector<info> ingre;

int n;
int mp, mf, ms, mv;
int p, f, s, v, c;
int ret = INT_MAX;
vector<int> temp_combi, best_combi;

void recur(int idx, int p, int f, int s, int v, int c) {
	if (p >= mp && f >= mf && s >= ms && v >= mv) {
		if (ret > c) {
			ret = c;
			best_combi = temp_combi;

			return;
		}
	}

	if (idx == n) return;

	//해당 인덱스의 식재료를 포함 후 recur 진행
	temp_combi.push_back(idx + 1);

	recur(idx + 1, p + ingre[idx].p, f + ingre[idx].f, s
		+ ingre[idx].s, v + ingre[idx].v, c + ingre[idx].c);

	temp_combi.pop_back(); //원상 복구

	//해당 인덱스의 식재료를 무시하고 recur 진행
	recur(idx + 1, p, f, s, v, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> p >> f >> s >> v >> c;
		ingre.push_back({ p,f,s,v,c });
	}

	recur(0, 0, 0, 0, 0, 0); //idx, p, f, s, v, c

	if (ret == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ret << '\n';

		for (int i : best_combi) {
			cout << i << ' ';
		}
	}

	return 0;
}
