#include <bits/stdc++.h>

using namespace std;

template <class T>
using Matrix = vector<vector<T>>;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        Matrix<int> land = Matrix<int>(2 * n, vector<int>(2 * n, 0));

        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                cin >> land[i][j];
            }
        }

        long long result = 0;

        for (int i = n; i < 2 * n; i++)
        {
            for (int j = n; j < 2 * n; j++)
            {
                result += land[i][j];
            }
        }

        int extra = min({land[0][n], land[0][2 * n - 1], land[n - 1][n], land[n - 1][2 * n - 1], land[n][0], land[n][n - 1], land[2 * n - 1][0], land[2 * n - 1][n - 1]});

        result += extra;

        cout << result << endl;
    }

    return 0;
}