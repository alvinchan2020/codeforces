#include <bits/stdc++.h>

using namespace std;

void solve(int l, int r, vector<int> &charge_acc, map<pair<int, int>, vector<int>> &charge_map)
{
    int charge_sum;
    if (l == 0)
        charge_sum = charge_acc[r];
    else
        charge_sum = charge_acc[r] - charge_acc[l - 1];

    int n_rods = r - l + 1;

    if (charge_sum == 0)
    {
        cout << 0 << endl;
        return;
    }

    if (n_rods % 2 == 0)
    {
        cout << 2 << endl;
        cout << l + 1 << ' ';
        l++;

        charge_sum = charge_acc[r] - charge_acc[l - 1];
    }
    else
    {
        cout << 1 << endl;
    }

    pair<int, int> p;

    p = make_pair(1, charge_acc[r] - (charge_sum - 1) / 2);
    for (int index : charge_map[p])
    {
        if (index >= l)
        {
            cout << index + 1 << endl;
            return;
        }
    }

    p = make_pair(-1, charge_acc[r] - (charge_sum + 1) / 2);
    for (int index : charge_map[p])
    {
        if (index >= l)
        {
            cout << index + 1 << endl;
            return;
        }
    }

    throw p;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t, n, q, l, r;
    char c;
    vector<int> charge;
    vector<int> charge_acc;
    map<pair<int, int>, vector<int>> charge_map;

    cin >> t;
    while (t--)
    {
        cin >> n >> q;

        charge = vector<int>(n, 0);
        charge_acc = vector<int>(n, 0);
        charge_map = map<pair<int, int>, vector<int>>();

        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (c == '+')
                charge[i] = 1 * pow(-1, i);
            else
                charge[i] = -1 * pow(-1, i);

            if (i == 0)
                charge_acc[i] = charge[i];
            else
                charge_acc[i] = charge_acc[i - 1] + charge[i];

            if (charge_map.find(make_pair(charge[i], charge_acc[i])) == charge_map.end())
                charge_map[make_pair(charge[i], charge_acc[i])] = vector<int>();
            charge_map[make_pair(charge[i], charge_acc[i])].push_back(i);
        }

        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            solve(l - 1, r - 1, charge_acc, charge_map);
        }
    }
    return 0;
}