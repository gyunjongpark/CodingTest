#include <iostream>
#include <vector>
using namespace std;

int n, m; //n개 중에서 m개를 뽑는다

void combi(int start, vector<int>& v) {
    if (v.size() == m) {
        for (int i : v) cout << i << ' ';
        cout << '\n';

        return;
    }

    for (int i = start + 1; i <= n; i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<int> v; //조합, 인덱스를 나열한 배열 v
    combi(0, v);

    return 0;
}
