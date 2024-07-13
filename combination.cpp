#include <iostream>
#include <vector>
using namespace std;

int n, m; //n개 중에서 m개를 뽑는다

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == m) {
        for (int i : v) cout << i << ' ';
        cout << '\n';

        return;
    }

    //visited 주석 처리 여부에 따라서 순열(중복 포함)로도 만들 수 있다
    for (int i = start + 1; i <= n; i++) {
        if (visited[i]) continue;

        v.push_back(i);
        visited[i] = true;

        combi(start, v, visited); //첫 번째 인자에 따라서 조합의 성격이 결정된다. start? i? i - 1?

        v.pop_back();
        visited[i] = false;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<int> v;
    vector<bool> visited(n + 1, false); //중복 방지

    combi(0, v, visited);

    return 0;
}
