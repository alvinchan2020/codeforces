#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui t, n;
    vector<ui> p;
    string s;

    cin >> t;
    while (t--)
    {
        cin >> n;
        p = vector<ui>(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        cin >> s;

        vector<array<ui, 4>> index_p_s_q = vector<array<ui, 4>>();
        for (ui i = 0; i < n; i++)
        {
            index_p_s_q.push_back(array<ui, 4>({i, p[i], (ui)(s[i] - '0'), 0}));
        }

        stable_sort(index_p_s_q.begin(), index_p_s_q.end(), [](const auto &a, const auto &b) -> bool
                    {
                        if (a[2] != b[2])
                            return a[2] < b[2];
                        else
                            return a[1] < b[1];
                    });

        for (int i = 0; i < index_p_s_q.size(); i++)
        {
            index_p_s_q[i][3] = i + 1;
        }

        stable_sort(index_p_s_q.begin(), index_p_s_q.end(), [](const auto &a, const auto &b) -> bool
                    { return a[0] < b[0]; });

        for (int i = 0; i < index_p_s_q.size(); i++)
        {
            cout << index_p_s_q[i][3] << ' ';
        }
        cout << endl;
    }

    return 0;
}