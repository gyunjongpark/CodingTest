#include<iostream>
#include<vector>
using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> result;

    int start = 0;
    int end = input.find(delimiter); //배열 번호(인덱스 반환)

    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }

    result.push_back(input.substr(start));

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s = "hello world! my name is park!";

    vector<string> v = split(s, " ");

    for (string s : v) cout << s << '\n';

    return 0;
}
