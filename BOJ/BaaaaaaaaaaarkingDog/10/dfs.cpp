void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (a[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return;
}
