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
interface ComponentInterface {
  graph: Record<string, string[]>;
  maximumComponent: () => number;
  countNodes: (current: string, visited: Set<string>) => number;
  shortestPath: (source: string, destination: string) => number;
}
class ComponentTests implements ComponentInterface {
  graph: Record<string, string[]>;
  constructor(graph: Record<string, string[]>) {
    this.graph = graph;
  }
  maximumComponent() {
    let max: number = 0;
    for (let ls in this.graph) {
      let count = this.countNodes(ls, new Set());
      if (count > max) max = count;
    }
    return max;
  }
  countNodes(current: string, visited: Set<string>) {
    if (visited.has(current)) return 0;
    visited.add(current);
    let size = 1;
    for (let neighbor of this.graph[current]) {
      size += this.countNodes(neighbor, visited);
    }
    return size;
  }

  shortestPath(source: string, destination: string) {
    let visited = new Set<string>([source]);
    let queue = [[source, 0]];

    while (queue.length > 0) {
      const node = queue.shift() ?? [];

      if (node[0] === destination) return parseInt(node[1].toString());
      console.log(node);
      for (let neighbor of this.graph[node[0]]) {
        if (!visited.has(neighbor)) {
          visited.add(neighbor);
          queue.push([neighbor, parseInt(node[1].toString()) + 1]);
        }
      }
    }
    return -1;
  }
}

// const g: Record<string, string[]> = {
//   f: ["i", "g"],
//   g: ["h"],
//   h: [],
//   i: ["k", "g"],
//   j: ["i"],
//   k: [],
// };

// const edges = [
//   ["i", "j"],
//   ["i", "k"],
//   ["j", "i"],
//   ["j", "k"],
//   ["k", "i"],
//   ["k", "j"],
//   ["k", "l"],
//   ["l", "k"],
//   ["k", "m"],
//   ["m", "k"],
//   ["o", "n"],
//   ["n", "o"],
// ];

const edges = [
  ["x", "y"],
  ["y", "z"],
  ["z", "v"],
  ["v", "w"],
  ["w", "x"],
];

const g = buildGraph(edges);

// dfs(g, "m");

let component = new ComponentTests(g);
console.log(component.shortestPath("w", "z"));
