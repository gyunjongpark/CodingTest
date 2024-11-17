#include<iostream>
#include<string> //getline
#include<vector>
using namespace std;

string s;

vector<string> split(const string& input, string delimiter) {
	vector<string> result;

	int start = 0;
	int end = input.find(delimiter, start); //문자열.find = 인덱스 반환

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
	
	getline(cin, s);

	vector<string> ret = split(s, " ");

	for (string s : ret) cout << s << '\n';

	return 0;
}
