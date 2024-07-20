#include<iostream>
#include<string> //getline
using namespace std;

int T;
string s;

int main() {
	cin >> T; // cin은 입력 버퍼에서 \n 직전까지 읽어들이기 때문에 개행이 남아있다
  
	string bufferflush;
	getline(cin, bufferflush); // 버퍼에 있는 값을 전부 읽어서 처리

	for (int i = 0; i < T; i++) {
		getline(cin, s); // 버퍼에 있는 값을 전부 읽어서 처리
		cout << s << "\n";
	}
	// 최종적인 버퍼는 비어있게 된다
  
	return 0;
}
