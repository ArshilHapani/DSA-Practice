function dfs(graph: Record<string, string[]>, src: string) {
  const stack = [src];
  const visitedNode = new Set();
  while (stack.length > 0) {
    const current = stack.pop();
    if (visitedNode.has(current?.toString())) return;
    visitedNode.add(current?.toString());
    console.log(current);
    for (let neighbor of graph[current ?? ""]) {
      stack.push(neighbor);
    }
  }
}

const g: Record<string, string[]> = {
  f: ["i", "g"],
  g: ["h"],
  h: [],
  i: ["k", "g"],
  j: ["i"],
  k: [],
};

dfs(g, "f");
