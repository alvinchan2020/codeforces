#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui t;
    ui n, m, rb, cb, rd, cd;
    ui time;
    int dr, dc;

    cin >> t;
    while (t--)
    {

        cin >> n >> m >> rb >> cb >> rd >> cd;
        dr = 1;
        dc = 1;
        time = 0;

        while (!(rb == rd || cb == cd))
        {
            if (rb + dr < 1 || rb + dr > n)
                dr *= -1;
            if (cb + dc < 1 || cb + dc > m)
                dc *= -1;
            rb = rb + dr;
            cb = cb + dc;
            time++;
        }

        cout << time << endl;
    }

    return 0;
}