#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t t;
    array<int, 3> l;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> l[0] >> l[1] >> l[2];

        sort(l.begin(), l.end());

        if (l[2] == l[0] + l[1])
        {
            cout << "YES" << endl;
        }

        else
        {
            if ((l[0] == l[1] && l[2] % 2 == 0) || (l[1] == l[2] && l[0] % 2 == 0))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}