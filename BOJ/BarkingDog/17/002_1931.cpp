#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, s, e, t, ret;
vector<pair<int, int>> debate;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        debate.push_back({ e,s });
    }

    //회의가 끝나는 시각을 기준으로 오름차순 정렬
    sort(debate.begin(), debate.end());

    for (int i = 0; i < n; i++) {
        if (t > debate[i].second) continue;

        t = debate[i].first;
        ret++;
    }

    cout << ret;

    return 0;
}