package code.trees.binaryTrees.preOrderTraversal;

class Main {
    public static void main(String[] args) {
        Tree<Integer> tree = new Tree<Integer>();
        Node<Integer> root = tree.createRoot(4);
        Node<Integer> lRoot = tree.appendLeft(root, 1);
        tree.appendRight(root, 6);
        tree.appendLeft(lRoot, 5);
        tree.appendRight(lRoot, 2);

        tree.display(0, root);
        System.out.println();
        tree.preOrderTraversal(root);
        System.out.println();
    }
}

class Node<T> {
    T data;
    Node<T> left;
    Node<T> right;

    public Node(T data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Tree<T1> {
    Node<T1> root;

    public Node<T1> createRoot(T1 data) {
        this.root = new Node<T1>(data);
        return this.root;
    }

    public Node<T1> appendLeft(Node<T1> node, T1 data) {
        Node<T1> newNode = new Node<T1>(data);
        node.left = newNode;
        return newNode;
    }

    public Node<T1> appendRight(Node<T1> node, T1 data) {
        Node<T1> newNode = new Node<T1>(data);
        node.right = newNode;
        return newNode;
    }

    public void display(int level, Node<T1> node) {
        if (node == null) {
            return;
        }

        display(level + 1, node.right);
        for (int i = 0; i < level; i++) {
            System.out.print("    ");
        }
        System.out.println(node.data);
        display(level + 1, node.left);
    }

    public void preOrderTraversal(Node<T1> root) {
        if (root == null) {
            System.out.println("Tree is empty");
            return;
        }
        System.out.print(root.data + " ");
        if (root.left != null) {
            this.preOrderTraversal(root.left);
        }
        if (root.right != null) {
            this.preOrderTraversal(root.right);
        }
    }
}