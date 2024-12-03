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
int p, f, s, v, cost;
int ret = INT_MAX;
vector<int> temp_combi, best_combi;

void recur(int idx, int p, int f, int s, int v, int cost) {
	if (p >= mp && f >= mf && s >= ms && v >= mv) {
		if (ret > cost) {
			ret = cost;
			best_combi = temp_combi;

			return;
		}
	}

	if (idx == n) return;

	temp_combi.push_back(idx + 1);
	recur(idx + 1, p + ingre[idx].p, f + ingre[idx].f, s + ingre[idx].s, v + ingre[idx].v, cost + ingre[idx].c);

	temp_combi.pop_back(); //원상 복구

	recur(idx + 1, p, f, s, v, cost); //변하지 않은 temp_combi인 채로 idx 증가
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> p >> f >> s >> v >> cost;
		ingre.push_back({ p,f,s,v,cost });
	}

	recur(0, 0, 0, 0, 0, 0); //idx, p, f, s, v, cost

	if (ret == INT_MAX) cout << -1;
	else {
		cout << ret << '\n';

		for (int i : best_combi) {
			cout << i << ' ';
		}
	}

	return 0;
}
