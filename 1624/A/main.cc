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

        int min_e = *min_element(a.begin(), a.end());
        int max_e = *max_element(a.begin(), a.end());

        cout << max_e - min_e << endl;
    }
    return 0;
}