
#ifndef GRAPH_H

#define GRAPH_H

#include <unordered_map>
#include <set>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
/**
 * DFS function which supports both directed and undirected graph
 */
void dfs(unordered_map<string, vector<string>> &graph, string source)
{
    stack<string> s;
    set<string> visited;
    s.push(source);
    visited.insert(source);

    while (!s.empty())
    {
        string current = s.top();
        s.pop();
        cout << current << " ";
        vector<string> neighbors = graph[current];
        for (string neighbor : neighbors)
        {
            if (visited.find(neighbor) == visited.end())
            {
                // neighbor is not visited and current is not present in set
                s.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    cout << endl;
}

#endif