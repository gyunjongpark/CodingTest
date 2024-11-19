#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[1004];
bool visited[1004];

void postOrder(int here) {
	if (!visited[here]) {
		if (adj[here].size() == 2) {
			postOrder(adj[here][0]);
			postOrder(adj[here][1]);

			visited[here] = true;
			cout << here << ' ';
		}
		else if (adj[here].size() == 1) {
			postOrder(adj[here][0]);

			visited[here] = true;
			cout << here << ' ';			
		}
		else if (adj[here].size() == 0) {
			visited[here] = true;
			cout << here << ' ';
		}
	}

	return;
}

void preOrder(int here) {
	if (!visited[here]) {
		if (adj[here].size() == 2) {
			visited[here] = true;
			cout << here << ' ';

			preOrder(adj[here][0]);
			preOrder(adj[here][1]);
		}
		else if (adj[here].size() == 1) {
			visited[here] = true;
			cout << here << ' ';

			preOrder(adj[here][0]);
		}
		else if (adj[here].size() == 0) {
			visited[here] = true;
			cout << here << ' ';
		}
	}

	return;
}

void inOrder(int here) {
	if (!visited[here]) {
		if (adj[here].size() == 2) {
			inOrder(adj[here][0]);

			visited[here] = true;
			cout << here << ' ';

			inOrder(adj[here][1]);
		}
		else if (adj[here].size() == 1) {
			inOrder(adj[here][0]);

			visited[here] = true;
			cout << here << ' ';
		}
		else if (adj[here].size() == 0) {
			visited[here] = true;
			cout << here << ' ';
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);

	int root = 1;

	cout << "트리순회 : postOrder \n";
	postOrder(root); memset(visited, 0, sizeof(visited));

	cout << "\n트리순회 : preOrder \n";
	preOrder(root); memset(visited, 0, sizeof(visited));

	cout << "\n트리순회 : inOrder \n";
	inOrder(root); memset(visited, 0, sizeof(visited));

	return 0;
}
