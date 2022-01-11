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

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        set<int> permutations = set<int>();

        for (auto e : a)
        {
            while (e > n)
            {
                e /= 2;
            }

            bool fit_flag = false;

            while (e > 0)
            {
                if (permutations.find(e) == permutations.end())
                {
                    permutations.insert(e);
                    fit_flag = true;
                    break;
                }
                else
                {
                    e /= 2;
                }
            }

            if (fit_flag = false)
                break;
        }

        if (permutations.size() == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}