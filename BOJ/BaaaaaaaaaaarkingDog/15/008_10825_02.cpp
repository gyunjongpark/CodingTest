#include<iostream>
#include<tuple> //tuple
#include<algorithm> //sort
using namespace std;

tuple<int, int, int, string> sts[100001];
int n, a, b, c;
string name;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> name >> a >> b >> c;
        sts[i] = { -a, b, -c, name }; //문제를 읽고 감소, 증가, 감소, 증가에 따라 부호를 매김
    }

    sort(sts, sts + n);

    for (int i = 0; i < n; ++i) {
        cout << get<string>(sts[i]) << '\n';
    }

	return 0;
}
