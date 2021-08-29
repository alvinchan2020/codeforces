#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define unreachable -1

typedef unsigned long long ull;
typedef pair<int, int> point;

ull distance(point p1, point p2, int costs[])
{
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;

    if (x1 == x2 && y1 == y2)
        return 0;

    if (x1 == x2)
        if (y2 > y1)
            return costs[2 - 1] * ull(y2 - y1);
        else
            return costs[5 - 1] * ull(y1 - y2);

    if (y1 == y2)
        if (x2 > x1)
            return costs[6 - 1] * ull(x2 - x1);
        else
            return costs[3 - 1] * ull(x1 - x2);

    if ((x2 - x1) == (y2 - y1))
        if (x2 > x1)
            return costs[1 - 1] * ull(x2 - x1);
        else
            return costs[4 - 1] * ull(x1 - x2);

    return unreachable;
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int costs[6];
        for (int i = 0; i < 6; i++)
            cin >> costs[i];

        // 1. caclulate intersection points
        // 2. there are only 3 different paths
        ull path1 = distance(point(0, 0), point(a - b, 0), costs) + distance(point(a - b, 0), point(a, b), costs);
        ull path2 = distance(point(0, 0), point(0, b - a), costs) + distance(point(0, b - a), point(a, b), costs);
        ull path3 = distance(point(0, 0), point(a, 0), costs) + distance(point(a, 0), point(a, b), costs);

        ull min_path = min(path1, min(path2, path3));

        cout << min_path << endl;
    }

    return 0;
}
