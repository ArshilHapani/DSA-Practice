#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

unordered_map<string, vector<string>> buildGraph(vector<vector<string>> edges)
{
    unordered_map<string, vector<string>> graph;
    for (vector<string> edge : edges)
    {
        string a = edge.at(0);
        string b = edge.at(1);

        if (graph.count(a) == 0)
        {
            graph[a] = vector<string>();
        }
        if (graph.count(b) == 0)
        {
            graph[b] = vector<string>();
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}
int shortestPath(vector<vector<string>> edges, string source, string destination)
{
    unordered_map<string, vector<string>> graph = buildGraph(edges);
    unordered_set<string> visited({source});
    pair<string, int> p = {source, 0};
    queue<pair<string, int>> q({p});

    while (!q.empty())
    {
        pair<string, int> current = q.front();
        q.pop();
        string node = current.first;
        int distance = current.second;

        if (node == destination)
            return distance;

        for (string neighbor : graph[node])
        {
            if (!(visited.count(neighbor) > 0))
            {
                visited.insert(neighbor);
                q.push({neighbor, distance + 1});
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<string>> edges = {
        {"x", "y"},
        {"y", "z"},
        {"z", "v"},
        {"v", "w"},
        {"w", "x"},
    };
    cout << shortestPath(edges, "w", "z") << endl;

    return 0;
}