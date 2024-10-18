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

    int pre = 0;
    
    for (int i = start + 1; i < n; i++) {
        if (visited[i]) continue;

        //현재 요소와 이전 요소가 같은 경우 continue
        if (a[i] == pre) continue;
        pre = a[i];

        v.push_back(a[i]);
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

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    vector<int> v;
    vector<bool> visited(n +1, false); //중복 방지를 위한 visited

    combi(-1, v, visited); //idx를 다루어야 하므로 start = -1

    return 0;
}
