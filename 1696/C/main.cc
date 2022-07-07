#include <bits/stdc++.h>

using namespace std;

vector<pair<int, long long>> re_represent(vector<int> a, int m)
{
    vector<pair<int, long long>> a_rep;

    a_rep.push_back(make_pair(0, 0));

    while (!a.empty())
    {
        int a1 = a.back();
        a.pop_back();

        long long factor = 1;
        while ((a1 % m) == 0)
        {
            factor *= m;
            a1 /= m;
        }

        // pair<int, long long> a_rep_back = a_rep.back();
        if (a_rep.back().first == a1)
        {
            a_rep.back().second += factor;
        }
        else
        {
            a_rep.push_back(make_pair(a1, factor));
        }
    }

    return a_rep;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        while (n--)
            cin >> a[n];

        int k;
        cin >> k;
        vector<int> b(k);
        while (k--)
            cin >> b[k];

        auto a_rep = re_represent(a, m);
        auto b_rep = re_represent(b, m);

        if (a_rep == b_rep)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}