#include<iostream>
#include<string> //to_string
using namespace std;

int n, team, asum, bsum, team_a, team_b;
string t, pre;

string print(int sum) {
	string d = "00" + to_string(sum / 60); // 0일 때 00 출력
	string e = "00" + to_string(sum % 60); // 0일 때 00 출력

	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int string_to_int(string t) {
	return atoi(t.substr(0, 2).c_str()) * 60 + atoi(t.substr(3, 2).c_str());
}

void calculate_time(int& sum, string t, string pre) {
	sum += string_to_int(t) - string_to_int(pre);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> team >> t;

		if (team_a > team_b) calculate_time(asum, t, pre);
		else if (team_a < team_b) calculate_time(bsum, t, pre);

		// 동점일 때 이전 시간 setting
		team == 1 ? team_a++ : team_b++;
		pre = t;
	}
	
	// 마지막 check
	if (team_a > team_b) calculate_time(asum, "48:00", pre);
	else if (team_a < team_b) calculate_time(bsum, "48:00", pre);

	cout << print(asum)<<'\n';
	cout << print(bsum);

	return 0;
}
