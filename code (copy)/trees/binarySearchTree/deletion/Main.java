package code.trees.binarySearchTree.deletion;

class Main {
    public static void main(String[] args) {
        /*
         * 4
         * /\
         * 2 10
         * /\
         * 1 3
         */
        Tree t = new Tree();
        Node root = t.createRoot(4);
        Node l1 = t.appendLeft(root, 2);
        t.appendRight(root, 10);
        t.appendLeft(l1, 1);
        t.appendRight(l1, 3);
        t.deleteNode(root, 3);
        t.deleteNode(root, 2);
        t.inOrderTraversal(root);
        System.out.println();

    }
}

class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Tree {
    private Node root;

    public Tree() {
        this.root = null;
    }

    public Node createRoot(int data) {
        if (this.root == null) {
            this.root = new Node(data);
            return this.root;
        }
        System.out.println("Root is not null");
        return null;
    }

    public Node appendLeft(Node node, int data) {
        if (this.root == null) {
            System.out.println("Root is empty");
            return null;
        }
        if (node.left != null) {
            System.out.println("Left side of the provided node is not null");
            return null;
        }
        Node newNode = new Node(data);
        node.left = newNode;
        return newNode;
    }

    public Node appendRight(Node node, int data) {
        if (this.root == null) {
            System.out.println("Root is empty");
            return null;
        }
        if (node.right != null) {
            System.out.println("Right side of the provided node is not null");
            return null;
        }
        Node newNode = new Node(data);
        node.right = newNode;
        return newNode;
    }

    public void inOrderTraversal(Node node) {
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

    private Node inOrderPredecessor(Node root) {
        root = root.left;
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }

    public Node deleteNode(Node root, int data) {
        Node prev;
        if (root == null) {
            return null;
        }
        if (root.left == null && root.right == null) {
            // node is deleted implicitly by gc
            return null;
        }
        if (data < root.data) {
            root.left = deleteNode(root.left, data);
        } else if (data > root.data) {
            root.right = deleteNode(root.right, data);
        } else {
            prev = inOrderPredecessor(root);
            root.data = prev.data;
            root.left = deleteNode(root.left, prev.data);
        }
        return root;
    }

}
