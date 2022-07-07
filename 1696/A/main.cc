#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, z;
        cin >> n >> z;

        int e, a_max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> e;
            if ((e | z) > a_max)
                a_max = e | z;
            // cout << (e | z) << " ";
        }

        cout << a_max << endl;
    }

    return 0;
}