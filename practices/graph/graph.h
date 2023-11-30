
#ifndef GRAPH_H

#define GRAPH_H

#include <unordered_map>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
/**
 * DFS function which supports both directed and undirected graph
 */
void dfs(unordered_map<string, vector<string>> graph, string source)
{
    stack<string> stack({source}); // pushing source node to stack and set
    set<string> visited({source});

    while (!stack.empty())
    {
        string current = stack.top();
        stack.pop();
        cout << current << " ";
        for (string neighbor : graph[current])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                stack.push(neighbor);
            }
        }
    }
    cout << endl;
}
/**
 * BDS function which supports both directed and undirected graph
 */
template <typename T>
void bfs(unordered_map<T, vector<T>> &graph, T source)
{
    queue<T> q({source});
    set<T> visited({source});

    while (!q.empty())
    {
        T current = q.front();
        q.pop();

        cout << current << " ";
        for (T neighbor : graph[current])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
unordered_map<string, vector<string>> buildGraph(vector<vector<string>> &edges)
{
    unordered_map<string, vector<string>> graph;

    for (vector<string> edge : edges)
    {
        string a = edge.at(0);
        string b = edge.at(1);

        if (graph.find(a) == graph.end())
        {
            graph[a] = vector<string>();
        }
        if (graph.find(b) == graph.end())
        {
            graph[b] = vector<string>();
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}

int componentCount(unordered_map<string, vector<string>> graph)
{
}

#endif