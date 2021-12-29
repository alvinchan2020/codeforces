#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui t;

    cin >> t;
    while (t--)
    {
        ui n;
        ll k, sum_a;
        cin >> n >> k;

        vector<ui> a = vector<ui>(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sum_a = accumulate(a.begin(), a.end(), (ll)(0));

        // if sum is already less than k
        if (sum_a <= k)
        {
            cout << 0 << endl;
            continue;
        }

        // if only one member
        if (n == 1)
        {
            cout << a[0] - k << endl;
            continue;
        }

        sort(a.begin(), a.end());

        vector<ll> acc = vector<ll>(n);
        acc[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            acc[i] = a[i] + acc[i + 1];
        }

        ll x, y; // -- x times, := y times
        ll min_steps = sum_a - k;

        // y > 0
        // at lease two members
        for (y = 1; y <= n - 1; y++)
        {
            x = (sum_a - acc[n - y] + a[0] * y - k) / (y + 1);
            if (x < 0)
                x = 0;
            else if ((sum_a - acc[n - y] + a[0] * y - k) % (y + 1) > 0)
                x += 1;
            if (x + y < min_steps)
                min_steps = x + y;
        }

        cout << min_steps << endl;
    }

    return 0;
}