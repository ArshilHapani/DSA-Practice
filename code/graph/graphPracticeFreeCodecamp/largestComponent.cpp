#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

unordered_map<int, vector<int>> buildGraph(vector<vector<int>> edges)
{
    unordered_map<int, vector<int>> graph;
    for (vector<int> edge : edges)
    {
        int a = edge.at(0);
        int b = edge.at(1);

        if (graph.find(a) == graph.end())
        {
            graph[a] = vector<int>();
        }
        if (graph.find(b) == graph.end())
        {
            graph[b] = vector<int>();
        }

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}
int countNodes(unordered_map<int, vector<int>> graph)
{
    set<int> visitedNodes;
    // performing bfs
    stack<int> s;
    int count = 0;
    int source = graph.begin()->first;
    s.push(source);
    while (!s.empty())
    {
        int current = s.top();
        if (visitedNodes.count(current) > 0)
            continue;
        visitedNodes.insert(current);
        count++;
        cout << current << " ";
        s.pop();
        for (int neighbor : graph[current])
        {
            s.push(neighbor);
        }
    }
    cout << endl;
    return count;
}

int main()
{
    unordered_map<int, vector<int>> graph;
    vector<vector<int>> edges = {
        {5, 8},
        {5, 0},
        {8, 5},
        {8, 0},
        {0, 5},
        {0, 8},
        {0, 1},
        {1, 0},
        {4, 2},
        {4, 3},
        {2, 4},
        {2, 3},
        {3, 4},
        {3, 2},
    };
    graph = buildGraph(edges);
    cout << "Nodes in graph " << countNodes(graph) << endl;
    return 0;
}