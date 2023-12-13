#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Edge
{
public:
    string dest;
    int cost;

    Edge(string dest, int cost)
    {
        this->dest = dest;
        this->cost = cost;
    }
};

class WeightedGraph
{
    unordered_map<string, vector<Edge>> graph;

public:
    WeightedGraph(vector<pair<pair<string, string>, int>> edges)
    {
        for (pair<pair<string, string>, int> &edge : edges)
        {
            string a = edge.first.first;
            string b = edge.first.second;
            int cost = edge.second;

            if (this->graph.find(a) == graph.end())
            {
                this->graph[a] = vector<Edge>();
            }
            if (this->graph.find(b) == graph.end())
            {
                this->graph[b] = vector<Edge>();
            }

            this->graph[a].push_back(Edge(b, cost));
            this->graph[b].push_back(Edge(a, cost));
        }
    }

    void primsMST(string source)
    {
        // checking if source is present in graph or not
        if (this->graph.find(source) == this->graph.end())
            throw runtime_error("Source does not exist in graph");

        set<string> mstNodes = set<string>({source});
        int totalCost = 0;

        while (mstNodes.size() < this->graph.size())
        {
            int minCost = INT_MAX;
            string nextNode;
            string prevNode;

            for (string currentNode : mstNodes)
            {
                for (Edge &neighbor : this->graph[currentNode])
                {
                    if (mstNodes.find(neighbor.dest) == mstNodes.end() && neighbor.cost < minCost)
                    {
                        minCost = neighbor.cost;
                        nextNode = neighbor.dest;
                        prevNode = currentNode;
                    }
                }
            }

            if (!nextNode.empty())
            {
                mstNodes.insert(nextNode);
                totalCost += minCost;
                cout << "Added edge: " << prevNode << " - " << nextNode << " with cost " << minCost << endl;
            }
        }

        cout << "Total cost = " << totalCost << endl;
    }
};

int main()
{
    int numberOfNode = 10;
    vector<pair<pair<string, string>, int>> edges = {
        {{"f", "g"}, 5},
        {{"g", "i"}, 6},
        {{"g", "h"}, 4},
        {{"f", "i"}, 3},
        {{"i", "j"}, 4},
        {{"k", "i"}, 5},
        {{"f", "h"}, 5},
        {{"f", "j"}, 2},
        {{"g", "j"}, 1},
        {{"h", "j"}, 3},
        {{"h", "k"}, 2},
        {{"j", "k"}, 1},
    }; // for visual representation refer image
    WeightedGraph w(edges);

    w.primsMST("h");
    return 0;
}