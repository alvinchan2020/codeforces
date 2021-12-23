#include <bits/stdc++.h>
using namespace std;

template <typename _Tp, size_t _Nm_R, size_t _Nm_C>
using array2d = array<array<_Tp, _Nm_C>, _Nm_R>;

template <typename _Tp, size_t _Nm_R, size_t _Nm_C, size_t _Nm_D>
using array3d = array<array<array<_Tp, _Nm_D>, _Nm_C>, _Nm_R>;

size_t n, m, k;

array2d<size_t, 500, 499> h_edges;
array2d<size_t, 499, 500> v_edges;
array3d<size_t, 500, 500, 10> memory;

size_t dp(size_t r, size_t c, size_t d)
{
    if (memory[r][c][d] != 0)
        return memory[r][c][d];

    size_t up = SIZE_MAX, down = SIZE_MAX, left = SIZE_MAX, right = SIZE_MAX;

    if (d == 0)
    {
        if (r > 0)
            up = v_edges[r - 1][c];
        if (r < n - 1)
            down = v_edges[r][c];
        if (c > 0)
            left = h_edges[r][c - 1];
        if (c < m - 1)
            right = h_edges[r][c];

        memory[r][c][d] = min({up, down, left, right});
        return memory[r][c][d];
    }
    else
    {
        if (r > 0)
            up = v_edges[r - 1][c] + dp(r - 1, c, d - 1);
        if (r < n - 1)
            down = v_edges[r][c] + dp(r + 1, c, d - 1);
        if (c > 0)
            left = h_edges[r][c - 1] + dp(r, c - 1, d - 1);
        if (c < m - 1)
            right = h_edges[r][c] + dp(r, c + 1, d - 1);

        memory[r][c][d] = min({up, down, left, right});
        return memory[r][c][d];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cin >> h_edges[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v_edges[i][j];
        }
    }

    if (k % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dp(i, j, k / 2 - 1) * 2 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}