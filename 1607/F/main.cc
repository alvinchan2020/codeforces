#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <unordered_set>

using namespace std;

template <class T>
using Matrix = vector<vector<T>>;

struct node
{
    node *prev = NULL;
    node *next = NULL;
    size_t max_depth = 0;
};

inline bool is_valid(size_t r, size_t c, size_t n, size_t m)
{
    return r >= 0 && c >= 0 && r < n && c < m;
}

array<size_t, 3> solve(size_t n, size_t m, Matrix<char> &commands)
{
    // build graph
    Matrix<node> nodes(n, vector<node>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            switch (commands[i][j])
            {
            case 'U':
                if (is_valid(i - 1, j, n, m))
                {
                    nodes[i][j].next = &nodes[i - 1][j];
                    nodes[i - 1][j].prev = &nodes[i][j];
                }
                break;
            case 'D':
                if (is_valid(i + 1, j, n, m))
                {
                    nodes[i][j].next = &nodes[i + 1][j];
                    nodes[i + 1][j].prev = &nodes[i][j];
                }
                break;
            case 'L':
                if (is_valid(i, j - 1, n, m))
                {
                    nodes[i][j].next = &nodes[i][j - 1];
                    nodes[i][j - 1].prev = &nodes[i][j];
                }
                break;
            case 'R':
                if (is_valid(i, j + 1, n, m))
                {
                    nodes[i][j].next = &nodes[i][j + 1];
                    nodes[i][j + 1].prev = &nodes[i][j];
                }
                break;
            default:
                throw commands[i][j];
            }
        }
    }

    // mark depth
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nodes[i][j].max_depth == 0)
            {
                // dfs
                // forward until end of path
                // then mark depth

                list<node *> steps_list;
                unordered_set<node *> steps_set;
                node *c_node = &nodes[i][j];

                while (true)
                {
                    steps_list.push_back(c_node);
                    steps_set.insert(c_node);

                    c_node = c_node->next;

                    if (c_node == NULL)
                        break;
                    if (steps_set.find(c_node) != steps_set.end())
                        break;
                    if (c_node->max_depth > 0)
                        break;
                }

                if (c_node == NULL)
                {
                    size_t depth = 0;

                    while (!steps_list.empty())
                    {
                        depth++;
                        steps_list.back()->max_depth = depth;
                        steps_list.pop_back();
                    }
                }
                else if (steps_set.find(c_node) != steps_set.end())
                {
                    size_t depth = 0;
                    list<node *> loop_nodes = list<node *>();
                    while (true)
                    {
                        node *temp_node = steps_list.back();
                        loop_nodes.push_back(temp_node);
                        steps_list.pop_back();
                        steps_set.erase(temp_node);
                        depth++;

                        if (temp_node == c_node)
                            break;
                    }
                    while (!loop_nodes.empty())
                    {
                        loop_nodes.back()->max_depth = depth;
                        loop_nodes.pop_back();
                    }
                    while (!steps_list.empty())
                    {
                        depth++;
                        steps_list.back()->max_depth = depth;
                        steps_list.pop_back();
                    }
                }
                else if (c_node->max_depth > 0)
                {
                    size_t depth = c_node->max_depth;

                    while (!steps_list.empty())
                    {
                        depth++;
                        steps_list.back()->max_depth = depth;
                        steps_list.pop_back();
                    }
                }
            }
        }
    }

    // max depth and start pos
    size_t max_r = 0, max_c = 0, max_d = nodes[0][0].max_depth;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nodes[i][j].max_depth > max_d)
            {
                max_r = i;
                max_c = j;
                max_d = nodes[i][j].max_depth;
            }
        }
    }

    return array<size_t, 3>({max_r, max_c, max_d});
}

int main()
{
    size_t t, n, m;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        Matrix<char> commands(n, vector<char>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> commands[i][j];
            }
        }

        array<size_t, 3> ans = solve(n, m, commands);

        cout << ans[0] + 1 << ' ' << ans[1] + 1 << ' ' << ans[2] << endl;
    }

    return 0;
}