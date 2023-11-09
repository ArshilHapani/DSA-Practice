function dfs(graph: Record<string, string[]>, src: string) {
  const stack = [src];
  const visitedNode = new Set();
  while (stack.length > 0) {
    const current = stack.pop();
    if (visitedNode.has(current?.toString())) continue;
    visitedNode.add(current?.toString());
    console.log(current);
    for (let neighbor of graph[current ?? ""]) {
      stack.push(neighbor);
    }
  }
}

function buildGraph(edges: string[][]): Record<string, string[]> {
  const graph: Record<string, string[]> = {};
  for (const edge of edges) {
    const [a, b] = edge;
    if (!(a in graph)) {
      graph[a] = [];
    }
    if (!(b in graph)) {
      graph[b] = [];
    }
    graph[a].push(b);
    graph[b].push(a);
  }
  return graph;
}

// const g: Record<string, string[]> = {
//   f: ["i", "g"],
//   g: ["h"],
//   h: [],
//   i: ["k", "g"],
//   j: ["i"],
//   k: [],
// };

const edges = [
  ["i", "j"],
  ["i", "k"],
  ["j", "i"],
  ["j", "k"],
  ["k", "i"],
  ["k", "j"],
  ["k", "l"],
  ["l", "k"],
  ["k", "m"],
  ["m", "k"],
  ["o", "n"],
  ["n", "o"],
];

const g = buildGraph(edges);

dfs(g, "m");
