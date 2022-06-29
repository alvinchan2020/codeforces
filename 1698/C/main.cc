#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int e, n_neg = 0, n_zero = 0, n_pos = 0;

        vector<int> a(0);
        for (int i = 0; i < n; i++)
        {
            cin >> e;

            if (e < 0)
            {
                n_neg++;
                if (n_neg <= 2)
                    a.push_back(e);
            }
            else if (e == 0)
            {
                n_zero++;
                if (n_zero <= 2)
                    a.push_back(e);
            }
            else if (e > 0)
            {
                n_pos++;
                if (n_pos <= 2)
                    a.push_back(e);
            }
        }

        if ((n_neg > 2) or (n_pos > 2))
        {
            cout << "NO" << endl;
            continue;
        }

        set<int> s(a.begin(), a.end());
        bool flag_closure = true;

        // brute force
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i + 1; j < a.size(); j++)
            {
                for (int k = j + 1; k < a.size(); k++)
                {
                    // cout << "(" << i << " " << j << " " << k << ")" << endl;
                    if (!s.contains(a[i] + a[j] + a[k]))
                    {
                        flag_closure = false;
                    }
                }
            }
        }

        if (flag_closure)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}