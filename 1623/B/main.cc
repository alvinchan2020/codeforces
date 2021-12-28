#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui t;

    cin >> t;
    while (t--)
    {
        ui n;
        ui l, r;
        list<pair<ui, ui>> ranges_list;
        pair<ui, ui> p_range, c_range;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> l >> r;
            ranges_list.emplace_back(l, r);
        }

        struct sort_range
        {
            bool operator()(const pair<ui, ui> &left, const std::pair<ui, ui> &right)
            {
                return (left.second - left.first) > (right.second - right.first);
            }
        };
        ranges_list.sort(sort_range());

        while (!ranges_list.empty())
        {
            p_range = ranges_list.front();
            ranges_list.pop_front();

            if (p_range.first == p_range.second)
            {
                cout << p_range.first << ' ' << p_range.second << ' ' << p_range.second << endl;
                continue;
            }

            //find c_range
            c_range = pair<ui, ui>(0, 0);
            for (auto range : ranges_list)
            {
                if (((range.first == p_range.first) || (range.second == p_range.second)) && range.second - range.first >= c_range.second - c_range.first)
                {
                    c_range = range;
                }
            }

            if (c_range.first == p_range.first)
            {
                cout << p_range.first << ' ' << p_range.second << ' ' << c_range.second + 1 << endl;
            }
            else
            {
                cout << p_range.first << ' ' << p_range.second << ' ' << c_range.first - 1 << endl;
            }
        }
        cout << endl;
    }

    return 0;
}