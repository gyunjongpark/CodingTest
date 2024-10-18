#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, m, a[10];

void print(vector<int>& v) {
    for (int i : v) {
        cout << i << ' ';
    }

    cout << '\n';

    return;
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == m) {
        print(v);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        if (visited[a[i]]) continue;

        v.push_back(a[i]);
        visited[a[i]] = true;

        combi(start, v, visited); //다음 수는 현재 수를 제외하고 처음부터 순회

        v.pop_back();
        visited[a[i]] = false;
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

    vector<int> v;
    vector<bool> visited(10001, false); //중복 방지를 위한 visited

    combi(-1, v, visited); //idx를 다루어야 하므로 start = -1

    return 0;
}
