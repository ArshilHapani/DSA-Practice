#include <iostream>
#include <unordered_map>
#include <vector>
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
bool hasPath(unordered_map<string, vector<string>> graph, string source, string destination, set<string> visitedNodes)
{
    if (source == destination)
        return true;

    if (visitedNodes.count(source) > 0)
        return false;

    visitedNodes.insert(source);
    for (string neighbor : graph[source])
    {
        if (hasPath(graph, neighbor, destination, visitedNodes))
            return true;
    }
    return false;
}

bool undirectedPath(vector<vector<string>> edges, string nodeA, string nodeB)
{
    unordered_map<string, vector<string>> graph = buildGraph(edges);
    set<string> s;
    return hasPath(graph, nodeA, nodeB, s);
}

int main(int argc, char const *argv[])
{
    vector<vector<string>> edges = {
        {"i", "j"},
        {"k", "i"},
        {"m", "k"},
        {"k", "l"},
        {"o", "n"},
        {"j", "k"} // EXTRA specific

    };
    string source = "j";
    string destination = "o";
    cout << "Path between " << source << " to " << destination << " is " << undirectedPath(edges, source, destination) << endl;
    return 0;
}
