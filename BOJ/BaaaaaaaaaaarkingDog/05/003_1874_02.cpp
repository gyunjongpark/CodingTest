#include<iostream>
#include<stack>
using namespace std;

int cnt = 1, n, t;
string ret;
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> t;

		while (cnt <= t) { // t가 될 때까지 + 추가
			stk.push(cnt++);
      
			ret += "+\n";
		}

		// t 이후에 나오는 수는 항상 t보다 작은 값이 스택에 남아야 한다. 그렇지 않다면 NO
		if (stk.top() != t) {
			cout << "NO";

			return 0;
		}

		stk.pop(); // t에 달성하면 pop하고 - 추가
    
		ret += "-\n";
	}

	cout << ret;

	return 0;
}
