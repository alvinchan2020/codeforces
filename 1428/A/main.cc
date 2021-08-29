#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define ull unsigned long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ull steps = 0;
        steps += abs(x1 - x2) + abs(y1 - y2);

        if (x1 != x2 && y1 != y2)
            steps += 2;

        cout << steps << endl;
    }
    return 0;
}
