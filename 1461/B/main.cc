#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int n, int m, vector<string> matrix)
{
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == n - 1)
            {
                if (matrix[i][j] == '*')
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }

            else
            {
                int minimum_spruce = dp[i + 1][j];
                for (int _j = j - 1; _j <= j + 1; _j++)
                {
                    if (!((0 <= _j) && (_j < m)))
                    {
                        minimum_spruce = 0;
                        break;
                    }
                    else if (dp[i + 1][_j] < minimum_spruce)
                        minimum_spruce = dp[i + 1][_j];
                }

                if (matrix[i][j] == '*')
                    dp[i][j] = minimum_spruce + 1;
                else
                    dp[i][j] = 0;
            }
        }
    }

    //debug
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }*/

    //sum dp
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result += dp[i][j];
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<string> matrix = vector<string>(n);

        for (int j = 0; j < n; j++)
        {
            string line;
            cin >> line;
            matrix[j] = line;
        }

        int result = solve(n, m, matrix);
        cout << result << endl;
    }

    return 0;
}
