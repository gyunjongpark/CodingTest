#include<iostream>
#include<vector>
using namespace std;

vector<string> split(const string& input, string delimiter) {
	vector<string> result;
	int start = 0; int end = input.find(delimiter);

	while (end != string::npos) {
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start)); // 마지막 문자열 저장

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "hello world! i'm gyunjongpark", d = " ";

	vector<string> a = split(s, d);

	for (string b : a) cout << b << "\n";

	/* 출력 형태
	
	hello
	world!
	i'm
	gyunjongpark

	*/

	return 0;
}
