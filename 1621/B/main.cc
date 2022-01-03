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

        vector<array<int, 3>> segments = vector<array<int, 3>>(n);

        int i_left = 0, i_right = 0, i_single = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> segments[i][0] >> segments[i][1] >> segments[i][2];

            //solution for each i
            if (i == 0)
            {
                cout << segments[0][2] << endl;
                continue;
            }

            // update i_left, i_right
            if (segments[i][0] < segments[i_left][0])
            {
                i_left = i;
            }
            else if (segments[i][0] == segments[i_left][0] && segments[i][2] < segments[i_left][2])
            {
                i_left = i;
            }

            if (segments[i][1] > segments[i_right][1])
            {
                i_right = i;
            }
            else if (segments[i][1] == segments[i_right][1] && segments[i][2] < segments[i_right][2])
            {
                i_right = i;
            }

            // update i_single
            if (segments[i][0] < segments[i_single][0] && segments[i][1] >= segments[i_single][1])
            {
                i_single = i;
            }
            else if (segments[i][0] <= segments[i_single][0] && segments[i][1] > segments[i_single][1])
            {
                i_single = i;
            }
            else if (segments[i][0] == segments[i_single][0] && segments[i][1] == segments[i_single][1] && segments[i][2] < segments[i_single][2])
            {
                i_single = i;
            }

            // buy two or one
            if (segments[i_single][0] == segments[i_left][0] && segments[i_single][1] == segments[i_right][1] && segments[i_single][2] < segments[i_left][2] + segments[i_right][2])
                cout << segments[i_single][2] << endl;
            else
                cout << segments[i_left][2] + segments[i_right][2] << endl;
        }
    }

    return 0;
}