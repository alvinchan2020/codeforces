#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        char str[n + 1];
        cin >> str;

        vector<int> losings;

        // statistic
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'L')
            {
                counter++;
            }
            else
            {
                if (counter != 0)
                {
                    losings.push_back(counter);
                    counter = 0;
                }
            }
        }
        if (counter != 0)
            losings.push_back(counter);

        int losing_at_begin = 0;
        int losing_at_end = 0;

        if (str[0] == 'L')
        {
            losing_at_begin = losings.front();
            losings.erase(losings.begin());
        }

        if (str[n - 1] == 'L' && losings.size() != 0)
        {
            losing_at_end = losings.back();
            losings.erase(prev(losings.end()));
        }

        // start elimelate loses
        sort(losings.begin(), losings.end());
        reverse(losings.begin(), losings.end());

        while (k != 0 && losings.size() != 0)
        {
            k--;
            losings[losings.size() - 1]--;

            if (losings[losings.size() - 1] == 0)
                losings.pop_back();
        }

        if (k > 0 && losing_at_begin > 0)
        {
            int eli = min(k, losing_at_begin);
            k -= eli;
            losing_at_begin -= eli;
        }

        if (k > 0 && losing_at_end > 0)
        {
            int eli = min(k, losing_at_end);
            k -= eli;
            losing_at_end -= eli;
        }

        // calculate score
        int total_score = 2 * n - 1;
        int losing_score = 2 * (losing_at_begin + losing_at_end);
        for (auto it = losings.begin(); it != losings.end(); it++)
        {
            losing_score += *it * 2 + 1;
        }
        int winning_score = total_score - losing_score;
        if (winning_score < 0)
            winning_score = 0;

        cout << winning_score << endl;
    }

    return 0;
}