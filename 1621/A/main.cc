#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        if ((n - 1) / 2 + 1 < k)
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k != 0 && i == j && i % 2 == 0 && j % 2 == 0)
                {
                    cout << 'R';
                    k--;
                }
                else
                {
                    cout << '.';
                }
            }
            cout << endl;
        }
    }
    return 0;
}