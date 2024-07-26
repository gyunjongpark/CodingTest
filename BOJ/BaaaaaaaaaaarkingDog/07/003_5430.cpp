#include<iostream>
#include<deque>
#include<algorithm> //reverse
using namespace std;

int t, n;
string p, x;

deque<string> split(const string& input, string delimiter) {
	deque<string> result;
	int start = 0; int end = input.find(delimiter);

	while (end != string::npos) {
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start));
	
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> p >> n >> x;
		string test_str = "";
		deque<string> ret_str;
		bool flag = 0;
		bool reversed = 0;

		for (int i = 1; i < x.size() - 1; i++) {
			test_str += x[i]; //괄호 제거
		}

		if (test_str.size()) {
			ret_str = split(test_str, ",");
		}

		for (char c : p) {
			if (c == 'R') {
				reversed = !reversed;
			}
			else if (c == 'D') {
				if (ret_str.empty()) {
					flag = 1;
					break; // No need to continue if empty
				}
				else {
					if (reversed) {
						ret_str.pop_back();
					}
					else ret_str.pop_front();
				}
			}
		}
		if (reversed) reverse(ret_str.begin(), ret_str.end());

		if (flag) cout << "error" << '\n';
		else {
			if (ret_str.empty()) {
				cout << "[]" << '\n';
			}
			else {
				cout << '[';
				cout << ret_str.front();
				ret_str.pop_front();

				while (!ret_str.empty()) {
					cout << ',' << ret_str.front();
					ret_str.pop_front();
				}
				cout << ']' << '\n';
			}
		}
		
	}

	return 0;
}
