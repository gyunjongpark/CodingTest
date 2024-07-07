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

    for (int i = start + 1; i <= n; i++) {
        if (visited[i]) continue;

        v.push_back(i);
        visited[i] = true;

        combi(start, v, visited);

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
