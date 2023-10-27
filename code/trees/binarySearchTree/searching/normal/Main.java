package code.trees.binarySearchTree.searching.normal;

import java.util.Optional;

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

        Optional<Node<Integer>> result = t.search(root, 2);
        if (result.isPresent()) {
            System.out.println("Found: " + result.get().data);
        } else {
            System.out.println("Not found");
        }
    }
}

class Node<T extends Comparable<T>> {
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

    public Optional<Node<T>> search(Node<T> node, T key) {
        if (node == null) {
            System.out.println(key + " does not exist in the tree");
            return Optional.empty();
        }

        int comparison = key.compareTo(node.data);
        if (comparison == 0) {
            return Optional.of(node);
        } else if (comparison < 0) {
            return search(node.left, key);
        } else {
            return search(node.right, key);
        }
    }
}
