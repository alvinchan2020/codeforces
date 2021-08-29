#include <iostream>

using namespace std;

int solve(int l, int r)
// r >= a >= b >= l
{
    int a, b, b1;
    a = r;
    b1 = a / 2 + 1;
    b = max(l, b1);

    return a % b;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = solve(l, r);

        cout << ans << endl;
    }
    return 0;
}