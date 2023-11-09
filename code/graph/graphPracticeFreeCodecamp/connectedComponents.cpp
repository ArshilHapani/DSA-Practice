#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>

using namespace std;

// for visualizing graph
void graphDisplay(unordered_map<string, vector<string>> graph)
{
    for (pair<string, vector<string>> ls : graph)
    {
        cout << "Key: " << ls.first << " value: [ ";
        for (string item : ls.second)
        {
            cout << item << " ";
        }
        cout << "]\n";
    }
}

// for building undirected graph from provided set of edges
unordered_map<string, vector<string>> buildGraph(vector<vector<string>> edges)
{
    unordered_map<string, vector<string>> graph;

    for (vector<string> edge : edges)
    {
        string a = edge.at(0);
        string b = edge.at(1);
        // Check if 'a' already exists in the graph
        if (graph.find(a) == graph.end())
        {
            graph[a] = vector<string>();
        }

        // Check if 'b' already exists in the graph
        if (graph.find(b) == graph.end())
        {
            graph[b] = vector<string>();
        }

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}
bool explore(unordered_map<string, vector<string>> graph, string current, set<string> &visited)
{
    if (visited.count(current) > 0)
        return false;

    visited.insert(current);
    for (string neighbor : graph[current])
    {
        explore(graph, neighbor, visited);
    }
    return true;
}

int countComponent(unordered_map<string, vector<string>> graph)
{
    int count = 0;
    set<string> visitedNodes;

    for (pair<string, vector<string>> item : graph)
    {
        if (explore(graph, item.first, visitedNodes))
            count++;
    }
    return count;
}

int main()
{
    vector<vector<string>> edges = {
        {"6", "8"},
        {"6", "7"},
        {"6", "5"},
        {"6", "4"},

        {"3", "3"},
        {"1", "2"}

    };
    unordered_map<string, vector<string>> graph;
    graph = buildGraph(edges);

    // graphDisplay(graph);
    cout << countComponent(graph) << endl;
    return 0;
}
