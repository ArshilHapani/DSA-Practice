#include "graph.h"

using namespace std;

int main()
{
    unordered_map<string, vector<string>> graph;

    // directed graph
    graph["a"].push_back("b");
    graph["a"].push_back("c");

    graph["b"].push_back("d");
    graph["c"] = {"e"};

    graph["d"] = {"f"};
    graph["e"] = {};
    graph["f"] = {};

    unordered_map<string, vector<string>> undirectedGraph;

    undirectedGraph["i"].push_back("j");
    undirectedGraph["i"].push_back("k");
    undirectedGraph["j"].push_back("k");
    undirectedGraph["k"].push_back("l");
    undirectedGraph["k"].push_back("m");
    undirectedGraph["l"];
    undirectedGraph["m"];

    // dfs(graph, "a");
    // bfs<string>(graph, "a");

    vector<vector<string>> edges = {
        {"i", "j"},
        {"i", "k"},
        {"j", "k"},
        {"k", "l"},
        {"k", "m"}};

    graph = buildGraph(edges);
    dfs(graph, "i");

    return 0;
}