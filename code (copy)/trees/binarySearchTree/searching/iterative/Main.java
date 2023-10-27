package code.trees.binarySearchTree.searching.iterative;

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

        Node result = t.searchIter(root, 12);

        if (result != null) {
            System.out.println("Node found " + result.data);
        } else {
            System.out.println("Node not found");
        }
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

    public Node searchIter(Node node, int key) {
        while (node != null) {
            if (key == root.data) {
                return root;
            } else if (key < root.data) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return null;
    }
}
