#include<iostream>
#include<string> //getline
using namespace std;

int T;
string s;

int main() {
	// cin은 입력 버퍼에서 \n 직전까지 읽어들이기 때문에 버퍼에는 개행이 남아있다
	cin >> T;
  
	string bufferflush;
	getline(cin, bufferflush); // getline : 버퍼에 있는 값을 전부 읽어서 처리

	for (int i = 0; i < T; i++) {
		getline(cin, s); // getline : 버퍼에 있는 값을 전부 읽어서 처리
		cout << s << "\n";
	}
	// 최종적인 버퍼는 비어있게 된다
  
	return 0;
}
