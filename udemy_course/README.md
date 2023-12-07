### Why we don't measure time complexity in seconds for algorithms

We measures time complexity in notations and not in seconds because seconds is the relative unit which depends on the device hardware and specifications. Same algorithm takes different time on different machines in terms of seconds if

### Different parameters in notation cannot be dropped only same parameters can be dropped

e.g.

$ O(n^2 + 2n) $
here we can drop the term `2n` as $n^2$ is dominant term and always greater than $2n$

$ O(n^2 + m) $
here we cannot drop the term `m` as it may be **possible that `m` is greater than $n^2$\*\*
