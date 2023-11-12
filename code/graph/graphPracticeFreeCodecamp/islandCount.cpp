#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool explore(vector<vector<char>> &grid, int row, int column, set<pair<int, int>> &visited)
{
    bool rowInBound = 0 <= row && row < grid.size();
    bool columnInBound = 0 <= column && column < grid.at(0).size();
    if (!rowInBound || !columnInBound)
        return false;

    if (grid[row][column] == 'w')
        return false;

    pair<int, int> p = {row, column};
    if (visited.count(p) > 0)
        return false;

    visited.insert(p);

    // performing bfs
    explore(grid, row - 1, column, visited); // up
    explore(grid, row + 1, column, visited); // down
    explore(grid, row, column - 1, visited); // right
    explore(grid, row, column + 1, visited); // left

    return true;
}

int countIsland(vector<vector<char>> &island)
{
    int count = 0;
    set<pair<int, int>> visited;
    for (int r = 0; r < island.size(); r++)
    {
        for (int c = 0; c < island.at(0).size(); c++)
        {
            if (explore(island, r, c, visited))
                count += 1;
        }
    }

    return count;
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
    cout << "Number of island in map is " << countIsland(island) << endl;
    return 0;
}