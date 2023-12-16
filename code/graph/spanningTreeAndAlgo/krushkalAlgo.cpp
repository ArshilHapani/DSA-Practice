#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

// Edge class used to define the source destination and weight between two nodes
class Edge
{
public:
    string src, dest;
    int weight;

    Edge(string s, string d, int w) : src(s), dest(d), weight(w){};
};

// disjointSet used to manage the node sets
class DisjointSet
{
    unordered_map<string, string> parent;

public:
    // initializing the empty set
    void makeSet(string v)
    {
        parent[v] = v;
    }
    string findSet(string v)
    {
        while (v != parent[v])
            v = parent[v];
        return v;
    }
    void unionSet(string a, string b)
    {
        a = findSet(a);
        b = findSet(b);
        parent[a] = b;
    }
};

class WeightedGraph
{
    vector<Edge> edges;

public:
    void addEdge(string src, string dest, int cost)
    {
        this->edges.push_back(Edge(src, dest, cost));
    }

    void kruskalMST()
    {
        int totalCost = 0;
        DisjointSet disjointSet;
        for (Edge &edge : this->edges)
        {
            disjointSet.makeSet(edge.src);
            disjointSet.makeSet(edge.dest);
        }
        sort(this->edges.begin(), this->edges.end(),
             [](Edge &a, Edge &b)
             { return a.weight < b.weight; });

        set<string> mstNodes;

        for (Edge &edge : this->edges)
        {
            string srcParent = disjointSet.findSet(edge.src);
            string destParent = disjointSet.findSet(edge.dest);

            if (srcParent != destParent)
            {
                mstNodes.insert(edge.src);
                mstNodes.insert(edge.dest);
                disjointSet.unionSet(srcParent, destParent);

                cout << "Added edge " << edge.src << " - cost " << edge.weight << endl;
                totalCost += edge.weight;
            }
        }
        cout << "Total cost: " << totalCost << endl;
    }
};

int main()
{
    WeightedGraph w;

    w.addEdge("f", "g", 5);
    w.addEdge("g", "i", 6);
    w.addEdge("g", "h", 4);
    w.addEdge("f", "i", 3);
    w.addEdge("i", "j", 4);
    w.addEdge("k", "i", 5);
    w.addEdge("f", "h", 5);
    w.addEdge("f", "j", 2);
    w.addEdge("g", "j", 1);
    w.addEdge("h", "j", 3);
    w.addEdge("h", "k", 2);
    w.addEdge("j", "k", 1);

    w.kruskalMST();

    return 0;
}