#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// using recursive approach
bool hasPath(unordered_map<string, vector<string>> graph, string source, string destination)
{
    if (source == destination)
        return true;

    for (string neighbor : graph[source])
    {
        if (hasPath(graph, neighbor, destination))
        {
            return true;
        }
    }
    return false;
}
// using bfs approach
bool bfsHasPath(unordered_map<string, vector<string>> graph, string source, string destination)
{
    queue<string> q;
    q.push(source);

    while (!q.empty())
    {
        string current = q.front();
        q.pop();
        if (current == destination)
            return true;

        for (string neighbor : graph[current])
        {
            q.push(neighbor);
        }
    }
    return false;
}

// using dfs approach

bool dfsHasPath(unordered_map<string, vector<string>> graph, string source, string destination)
{
    stack<string> s;
    s.push(source);
    while (!s.empty())
    {
        string current = s.top();
        s.pop();
        if (current == destination)
            return true;

        for (string neighbor : graph[current])
        {
            s.push(neighbor);
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    unordered_map<string, vector<string>> graph;

    graph["f"].push_back("g");
    graph["f"].push_back("i");

    graph["g"].push_back("h");

    graph["h"];

    graph["i"].push_back("g");
    graph["i"].push_back("k");

    graph["j"].push_back("i");

    graph["k"];

    string source = "j";
    string destination = "h";
    cout << "Path between " << source << " to " << destination << " is " << dfsHasPath(graph, source, destination) << endl;
    return 0;
}
