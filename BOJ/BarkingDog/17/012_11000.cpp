#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, s, t;
vector<pair<int, int>> debate;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> t;

        debate.push_back({ s, 1 });
        debate.push_back({ t, -1 });
    }

    sort(debate.begin(), debate.end());

    int ans = 0; //필요한 강의실의 최대 개수
    int curtime = debate[0].first; //현재 시간
    int cur = 0; //현재 시간에 열려있는 강의실의 개수
    int idx = 0; //현재 보고있는 event에서의 인덱스

    while (true) {
        while (idx < 2 * n && debate[idx].first == curtime) {
            cur += debate[idx].second;
            idx++;
        }

        ans = max(ans, cur);

        if (idx == 2 * n) break;

        curtime = debate[idx].first;
    }

    cout << ans << '\n';

    return 0;
}
