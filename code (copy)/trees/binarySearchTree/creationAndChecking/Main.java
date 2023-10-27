package code.trees.binarySearchTree.creationAndChecking;

class Main {
    public static void main(String[] args) {
        /*
         * 4
         * /\
         * 2 10
         * /\
         * 1 3
         */
        Tree<Integer> t = new Tree<>();
        Node<Integer> root = t.createRoot(4);
        Node<Integer> l1 = t.appendLeft(root, 2);
        t.appendRight(root, 10);
        t.appendLeft(l1, 1);
        t.appendRight(l1, 3);
        t.inOrderTraversal(root);
        System.out.println();
        System.out.println(t.isBST(root));
    }
}

class Node<T> {
    public T data;
    public Node<T> left;
    public Node<T> right;

    public Node(T data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Tree<T extends Comparable<T>> {
    private Node<T> root;

    public Tree() {
        this.root = null;
    }

    public Node<T> createRoot(T data) {
        if (this.root == null) {
            this.root = new Node<>(data);
            return this.root;
        }
        System.out.println("Root is not null");
        return null;
    }

    public Node<T> appendLeft(Node<T> node, T data) {
        if (this.root == null) {
            System.out.println("Root is empty");
            return null;
        }
        if (node.left != null) {
            System.out.println("Left side of the provided node is not null");
            return null;
        }
        Node<T> newNode = new Node<>(data);
        node.left = newNode;
        return newNode;
    }

    public Node<T> appendRight(Node<T> node, T data) {
        if (this.root == null) {
            System.out.println("Root is empty");
            return null;
        }
        if (node.right != null) {
            System.out.println("Right side of the provided node is not null");
            return null;
        }
        Node<T> newNode = new Node<>(data);
        node.right = newNode;
        return newNode;
    }

    public void inOrderTraversal(Node<T> node) {
        if (node == null) {
            return;
        }
        if (node.left != null) {
            inOrderTraversal(node.left);
        }
        System.out.print(node.data + " ");
        if (node.right != null) {
            inOrderTraversal(node.right);
        }
    }

    public boolean isBST(Node<T> node) {
        return isBSTUtil(node, null, null);
    }

    private boolean isBSTUtil(Node<T> node, T min, T max) {
        if (node == null) {
            return true;
        }
        if ((min != null && node.data.compareTo(min) <= 0) || (max != null && node.data.compareTo(max) >= 0)) {
            return false;
        }
        return isBSTUtil(node.left, min, node.data) && isBSTUtil(node.right, node.data, max);
    }
}
