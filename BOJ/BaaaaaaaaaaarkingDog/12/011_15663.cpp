#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m; //n개 중에서 m개를 뽑는다
int a[10];

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
        //현재 요소와 이전 요소가 같은 경우 continue
        if (a[i] == pre) continue;

        if (visited[i]) continue;

        pre = a[i];

        v.push_back(a[i]);
        visited[i] = true;

        combi(start, v, visited); //다음 수는 현재 수를 제외하고 처음부터 순회

        v.pop_back();
        visited[i] = false;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m; //1 ~ n까지의 수 중에서 m개를 뽑는다

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n); //오름차순 정렬하여 중복된 조합을 방지

    vector<int> v;
    vector<bool> visited(n + 1, false); //중복 방지를 위한 visited
    combi(-1, v, visited); //idx를 다루어야 하므로 start = -1

    return 0;
}
