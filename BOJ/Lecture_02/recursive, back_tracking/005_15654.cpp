#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10004
using namespace std;

int a[8], n, m; //n개 중에서 m개를 뽑는다

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == m) {
        for (int i : v) cout << i << ' ';
        cout << '\n';

        return;
    }

    for (int i = start + 1; i < n; i++) {
        if (visited[a[i]]) continue;

        visited[a[i]] = true;
        v.push_back(a[i]);

        combi(start, v, visited);

        visited[a[i]] = false;
        v.pop_back();
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    vector<int> v; //조합, 인덱스를 나열한 배열 v
    vector<bool> visited(MAX, false); //중복 방지를 위한 visited
    combi(-1, v, visited);

    return 0;
}
