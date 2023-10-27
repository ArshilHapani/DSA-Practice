package code.trees.binaryTrees.linkedRepresentationOfBT;

class Main {
    public static void main(String[] args) {
        Tree<String> tree = new Tree<String>();
        Node<String> root = tree.createRoot("Arshil");
        Node<String> lRoot = tree.appendLeft(root, "Nami");
        Node<String> rRoot = tree.appendRight(root, "Robin");
        tree.appendLeft(lRoot, "Sanji");
        tree.appendRight(lRoot, "Pudding");

        tree.appendLeft(rRoot, "Zoro");
        tree.appendRight(rRoot, "Chopper");

        tree.display(0, root);

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
}