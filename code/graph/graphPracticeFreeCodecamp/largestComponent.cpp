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
int countNodes(unordered_map<int, vector<int>> graph, int node, set<int> &visited)
{
    if (visited.count(node) > 0)
        return 0;

    visited.insert(node);
    int size = 1;

    for (int neighbor : graph[node])
    {
        size += countNodes(graph, neighbor, visited);
    }
    return size;
}
int largestComponent(unordered_map<int, vector<int>> graph)
{
    int max = 0;
    set<int> visited;
    for (pair<int, vector<int>> ls : graph)
    {
        int size = countNodes(graph, ls.first, visited);
        if (size > max)
            max = size;
    }
    return max;
}
int main()
{
    unordered_map<int, vector<int>> graph;
    // vector<vector<int>> edges = {
    //     {5, 8},
    //     {5, 0},
    //     {8, 5},
    //     {8, 0},
    //     {0, 5},
    //     {0, 8},
    //     {0, 1},
    //     {1, 0},
    //     {4, 2},
    //     {4, 3},
    //     {2, 4},
    //     {2, 3},
    //     {3, 4},
    //     {3, 2},
    // };
    vector<vector<int>> edges = {
        {6, 8},
        {6, 7},
        {6, 5},
        {6, 4},
        {3, 3},
        {1, 2}

    };
    graph = buildGraph(edges);
    cout << "Nodes in largest graph " << largestComponent(graph) << endl;
    return 0;
}