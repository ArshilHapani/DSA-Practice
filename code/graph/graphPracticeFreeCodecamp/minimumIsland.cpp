#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;
int explore(vector<vector<char>> &island, int r, int c, set<pair<int, int>> &visited)
{
    bool rowInBounds = 0 <= r && r < island.size();
    bool columnInBounds = 0 <= c && c < island.at(0).size();

    if (!rowInBounds || !columnInBounds)
        return 0;

    if (island[r][c] == 'w')
        return 0;

    pair<int, int> p = {r, c};
    if (visited.count(p) > 0)
        return 0;

    visited.insert({r, c});

    int size = 1;
    // performing bfs
    size += explore(island, r - 1, c, visited); // up
    size += explore(island, r + 1, c, visited); // down
    size += explore(island, r, c - 1, visited); // left
    size += explore(island, r, c + 1, visited); // right

    return size;
}

int minimumIsland(vector<vector<char>> &island)
{
    int min = (int)INFINITY;
    set<pair<int, int>> visited;
    for (int r = 0; r < island.size(); r++)
    {
        for (int c = 0; c < island.at(0).size(); c++)
        {
            int size = explore(island, r, c, visited);
            if (size > 0 && size < min)
                min = size;
        }
    }
    return min;
}
int main()
{
    vector<vector<char>> island = {
        {'w', 'l', 'w', 'w', 'l', 'w'},
        {'l', 'l', 'w', 'w', 'l', 'w'},
        {'w', 'l', 'w', 'w', 'w', 'w'},
        {'w', 'w', 'w', 'l', 'l', 'w'},
        {'w', 'l', 'w', 'l', 'l', 'w'},
        {'w', 'w', 'w', 'w', 'w', 'w'},
    };
    cout << "Number of island in map is " << minimumIsland(island) << endl;
    return 0;
}