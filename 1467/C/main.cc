#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> a1(n1), a2(n2), a3(n3);
    for (int i = 0; i < n1; i++)
        cin >> a1[i];
    for (int i = 0; i < n2; i++)
        cin >> a2[i];
    for (int i = 0; i < n3; i++)
        cin >> a3[i];

    int min_a1, min_a2, min_a3;
    ull sum_a1, sum_a2, sum_a3;

    min_a1 = *min_element(a1.begin(), a1.end());
    min_a2 = *min_element(a2.begin(), a2.end());
    min_a3 = *min_element(a3.begin(), a3.end());

    sum_a1 = accumulate(a1.begin(), a1.end(), ull(0));
    sum_a2 = accumulate(a2.begin(), a2.end(), ull(0));
    sum_a3 = accumulate(a3.begin(), a3.end(), ull(0));

    ull result = sum_a1 + sum_a2 + sum_a3 - 2 * min({(ull)(min_a1 + min_a2), (ull)(min_a1 + min_a3), (ull)(min_a2 + min_a3), sum_a1, sum_a2, sum_a3});

    cout << result << endl;

    return 0;
}