#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &charge_acc, int l, int r)
{
    int charge_sum = charge_acc[r] - charge_acc[l - 1];
    int n_rods = r - l + 1;

    if (charge_sum == 0)
        return 0;
    else if (n_rods % 2 == 0)
        return 2;
    else
        return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q, l, r, charge;
    string s;
    vector<int> charge_acc;

    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        cin >> s;

        charge_acc = vector<int>(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+')
                charge = 1 * pow(-1, i);
            else
                charge = -1 * pow(-1, i);

            charge_acc[i + 1] = charge_acc[i] + charge;
        }

        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            int ans = solve(charge_acc, l, r);
            cout << ans << endl;
        }
    }
    return 0;
}