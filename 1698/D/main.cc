#include <bits/stdc++.h>

using namespace std;

void bin_search(int l, int r)
{
    if (l == r)
    {
        cout << "! " << l << endl;
        return;
    }

    int mid = (l + r) / 2;
    int length_l, length_r, e, n_valid_l = 0, n_valid_r = 0;

    // query left
    cout << "? " << l << " " << mid << endl;

    length_l = mid - l + 1;
    for (int i = 0; i < length_l; i++)
    {
        cin >> e;
        if ((l <= e) & (e <= mid))
            n_valid_l++;
    }

    if (n_valid_l % 2 == 1)
    {
        bin_search(l, mid);
        return;
    }
    else
    {
        bin_search(mid + 1, r);
        return;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        bin_search(1, n);
    }

    return 0;
}
