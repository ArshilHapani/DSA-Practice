# Trees
### Terminologies for trees
![TreeTerminology](/assets/treesTerminology(CWH).png)

# Binary Tree

A binary tree is a type of tree which contains at most two node as child 
![BinaryTree](/assets/BinaryTree(CWH).png)

There are two types of Binary tree


## Full or strict binary tree
<br/>**Each node have either 0 or 2 child**
![strictBinaryTree](/assets/strictBinaryTree.png)
**Non full binary tree**

 ![non_full_binary_tree](/assets/non_full_binary_tree.jpg)
<br/>

## Perfect binary tree
<br/>
All internal node have exactly two children and all leaf nodes are on same level

![PerfectBinaryTree](/assets/fullBinaryTree.jpg)
Non perfect binary tree
 ![non_full_binary_tree](/assets/non_full_binary_tree.jpg)
<br/>

## Complete binary tree

- All levels are completely filled except possibly last level
- Last level if not filled then it must be left aligned nodes

![completeBinaryTree](/assets/completeBinaryTree.png)

## Degenerate tree

- Every Parent node has exactly one child
- it contains two sub type trees which are left skews and right skews
- left skews trees move on left side which shown in figure below the left side bottom green tree
- right skews trees move on right side which shown in figure below the right side bottom  green tree
![degenerateTree](/assets/degenerateTree.png)
  
# Traversal in binary tree

1) PreOrder (***root*** -> leftSubTree -> rightSubTree)
2) PostOrder (leftSubTree -> rightSubTree -> ***Root***)
3) InOrder (leftSubTree -> ***root*** -> rightSubTree)

## PreOrder Traversal
![perOrderTraversal](/assets/perOrderTraversal.png)

## PostOrder Traversal
![Alt text](/assets/postOrderTraversal.png)


## Tips to find preOrder,postOrder and inOrder
![Alt text](/assets/tipsToFindTreeTraversal.png)

#Binary search tree

It is a type of binary tree

Properties of BST

- All nodes of left sub tree are less than root node
- All nodes of right sub tree are greater than root node
- Left and right sub trees are also binary search trees
- There are no duplicate nodes 