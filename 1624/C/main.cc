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
        int n;
        cin >> n;

        vector<int> a = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        set<int> p_set = set<int>();
        list<int> np_list = list<int>();

        for (auto e : a)
        {
            if (e <= n && p_set.find(e) == p_set.end())
                p_set.insert(e);
            else
                np_list.push_back(e);
        }

        np_list.sort([](int a, int b)
                     { return a > b; });

        auto check_aval = [](int child, int parent)
        {
            while (child >= 1)
            {
                if (child == parent)
                    return true;
                else
                    child /= 2;
            }
            return false;
        };

        bool no_flag = false;

        for (int i = n; i >= 1; i--)
        {
            if (p_set.find(i) != p_set.end())
                continue;
            else
            {
                bool aval_flag = false;

                for (auto it = np_list.begin(); it != np_list.end(); it++)
                {
                    if (check_aval(*it, i))
                    {
                        np_list.erase(it);
                        aval_flag = true;
                        break;
                    }
                    else
                        continue;
                }

                if (aval_flag == true)
                    continue;
                else
                {

                    no_flag = true;
                    break;
                }
            }
        }

        if (no_flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}