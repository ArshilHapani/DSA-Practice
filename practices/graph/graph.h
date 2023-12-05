
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
    stack<string> st({source});
    set<string> visited({source});

    while (!st.empty())
    {
        string current = st.top();
        st.pop();

        cout << current << " ";
        for (string neighbor : graph[current])
        {
            if (visited.find(neighbor) == visited.end())
            {
                // neighbor does not exist on visited set
                st.push(neighbor);
                visited.insert(neighbor);
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
    set<T> v({source});

    while (!q.empty())
    {
        T current = q.front();
        q.pop();
        cout << current << " ";
        for (T neighbor : graph[current])
        {
            if (v.find(neighbor) == v.end())
            {
                q.push(neighbor);
                v.insert(neighbor);
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
bool explore(unordered_map<string, vector<string>> &graph, string source, set<string> &visited)
{
    if (visited.count(source) > 0)
        return false;

    visited.insert(source);

    for (string neighbor : graph[source])
    {
        explore(graph, neighbor, visited);
    }
    return true;
}

int componentCount(unordered_map<string, vector<string>> graph)
{
    int count = 0;
    set<string> visited;

    for (pair<string, vector<string>> item : graph)
    {
        if (explore(graph, item.first, visited))
            count++;
    }
    return count;
}

#endif