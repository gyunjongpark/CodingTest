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
	//idx가 n에 도달하지 않아도 영앙소를 만족한다면 재귀 함수 종료
	//idx가 늘어날수록 c가 증가하므로 최솟값이 아니다
	if (p >= mp && f >= mf && s >= ms && v >= mv) {
		if (ret > c) { //ret = min(ret, c)를 사용하지 않는 이유? combi 값을 읽기 위해 조건문 활용
			ret = c;
			best_combi = temp_combi;

			return; //최솟값을 찾았다면 재귀 함수 종료
		}
	}

	if (idx == n) return; //최솟값에 관계없이 n번째 idx라면 재귀 함수 종료

	temp_combi.push_back(idx + 1);
	recur(idx + 1, p + ingre[idx].p, f + ingre[idx].f, s + ingre[idx].s, v + ingre[idx].v, c + ingre[idx].c);
	temp_combi.pop_back();

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

	if (ret == INT_MAX) cout << -1;
	else {
		cout << ret << '\n';

		for (int i : best_combi) {
			cout << i << ' ';
		}
	}

	return 0;
}
