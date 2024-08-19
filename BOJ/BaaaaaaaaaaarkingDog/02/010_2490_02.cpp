#include<iostream>
using namespace std;

int input;
string ret = "DCBAE";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        int result = 0;
	    
        for (int j = 0; j < 4; j++) {
            cin >> input;
            result += input;
        }
	    
        cout << ret[result] << '\n';
    }
	
	return 0;
}
