#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

float solve(vector<int> permutation, vector<pair<int, float>> experiments)
{
    int unsorted_length = 0;
    for (int i = permutation.size() - 1; i >= 0; i--)
    {
        if (permutation[i] == i + 1)
            continue;
        else
        {
            unsorted_length = i + 1;
            break;
        }
    }

    float probability;
    if (unsorted_length == 0)
        probability = 1;
    else
        probability = 0;

    for (int i = 0; i < experiments.size(); i++)
    {
        int r;
        float p;
        r = experiments[i].first;
        p = experiments[i].second;

        if (r < unsorted_length)
            continue;
        else
        {
            probability = probability + (1 - probability) * p;
        }

        //cout << i << ":" << probability << endl;
    }
    return probability;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<int> permutation(n);
        for (int j = 0; j < n; j++)
        {
            cin >> permutation[j];
        }

        //experiments
        vector<pair<int, float>> experiments(m);
        for (int k = 0; k < m; k++)
        {
            int r;
            float p;
            cin >> r >> p;
            experiments[k] = pair<int, float>(r, p);
        }

        float result = solve(permutation, experiments);
        cout << result << endl;
    }
    return 0;
}
