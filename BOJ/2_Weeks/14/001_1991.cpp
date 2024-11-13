#include<iostream>
using namespace std;

int n;
char parent, l, r;
pair<char, char> node[28];

void preorder(char here) {
	if (here == '.') return;

	cout << here;
	preorder(node[here - 'A'].first);
	preorder(node[here - 'A'].second);

	return;
}

void inorder(char here) {
	if (here == '.') return;

	inorder(node[here - 'A'].first);
	cout << here;
	inorder(node[here - 'A'].second);

	return;
}

void postorder(char here) {
	if (here == '.') return;

	postorder(node[here - 'A'].first);
	postorder(node[here - 'A'].second);
	cout << here;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent >> l >> r;

		node[parent - 'A'].first = l;
		node[parent - 'A'].second = r;
	}

	preorder('A'); cout << '\n';
	inorder('A'); cout << '\n';
	postorder('A');

	return 0;
}
