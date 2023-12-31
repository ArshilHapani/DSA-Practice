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

    // unordered_map<string, vector<string>> undirectedGraph;

    // undirectedGraph["i"].push_back("k");
    // undirectedGraph["i"].push_back("j");
    // undirectedGraph["j"].push_back("k");
    // undirectedGraph["k"].push_back("m");
    // undirectedGraph["k"].push_back("l");
    // undirectedGraph["l"];
    // undirectedGraph["m"];

    // // dfs(undirectedGraph, "i");
    // // bfs<string>(undirectedGraph, "i");

    // vector<vector<string>> edges = {
    //     {"i", "k"},
    //     {"i", "j"},
    //     {"j", "k"},
    //     {"k", "m"},
    //     {"k", "l"}};

    // edges = {
    //     {"o", "n"},
    //     {"n", "o"},
    //     {"n", "n"},
    //     {"o", "o"}};

    // graph = buildGraph(edges);
    // dfs(graph, "o");

    cout << componentCount(graph) << endl;

    return 0;
}