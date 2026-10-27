char** createGrid(int m, int n, int* returnSize) {
    *returnSize = m;

    char **grid = malloc(m * sizeof(*grid));

    for (int i = 0; i < m; i++) {
        grid[i] = malloc(n + 1);

        for (int j = 0; j < n; j++) {
            if (i == j || j == i + 1 ||
                (i == m - 1 && j > i) ||
                (j == n - 1 && i > j)) {
                grid[i][j] = '.';
            } else {
                grid[i][j] = '#';
            }
        }

        grid[i][n] = '\0';
    }

    return grid;
}
