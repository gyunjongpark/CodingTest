/* pseudo code
void dfs(int here) {
    visited[here] = true;

    for (int there : adj[here]) {
        if (!visited[there]) {
            dfs(there);
        }
    }

    return;
}
*/
