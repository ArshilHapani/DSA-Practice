#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs(unordered_map<string, vector<string>> graph, string source)
{
    stack<string> s;
    s.push(source);
    while (!s.empty())
    {
        string current = s.top();
        s.pop();
        cout << current << " ";
        for (string neighbor : graph[current])
        {
            s.push(neighbor);
        }
    }
    cout << endl;
}

void bfs(unordered_map<string, vector<string>> graph, string source)
{
    queue<string> q;
    q.push(source);
    while (!q.empty())
    {
        string current = q.front();
        q.pop();
        cout << current << " ";
        for (string neighbor : graph[current])
        {
            q.push(neighbor);
        }
    }
    cout << endl;
}

/*
    Implementation of dfs using recursive using function call stack approach
    @param graph - instance of map
    @param source - node from where you want to start traversal
*/
void dfsRec(unordered_map<string, vector<string>> graph, string source)
{
    cout << source << " ";
    // base case -> if the source has empty list then it never enters in for loop
    for (string neighbor : graph[source])
    {
        dfsRec(graph, neighbor);
    }
}

int main(int argc, char const *argv[])
{
    unordered_map<string, vector<string>> graph;

    graph["a"].push_back("b");
    graph["a"].push_back("c");

    graph["b"].push_back("d");
    graph["c"].push_back("e");

    graph["d"].push_back("f");
    graph["e"];
    graph["f"];

    // cout << "DFS using iterative approach:\n";
    // dfs(graph, "a");
    // cout << "DFS using recursive approach:\n";
    // dfsRec(graph, "a");
    // cout << endl;

    cout << "BFS using iterative approach:\n";
    bfs(graph, "a");

    // cout << "DFS using recursive approach:\n";
    // dfsRec(graph, "a");
    // cout << endl;

    return 0;
}