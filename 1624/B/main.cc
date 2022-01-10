#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int e_a, e_b, e_c;

        // try c
        e_c = b - a + b;
        if (e_c > 0 && e_c % c == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        //try b
        e_b = c - (c - a) / 2;
        if ((c - a) % 2 == 0 && e_b > 0 && e_b % b == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        //try a
        e_a = b - (c - b);
        if (e_a > 0 && e_a % a == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
        continue;
    }

    return 0;
}