package code.stack.parenthesisMatching;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        String s = "[a + b * {c] - (d / e)}";
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter parenthesis string: ");
        s = sc.nextLine();
        Matching m = new Matching(s);
        System.out.println("Character matching for string " + s + " is " + m.checkMatching());
        sc.close();
    }
}

class Matching {
    private String str;
    private int top;
    private Character stack[];

    Matching(String s) {
        this.str = s;
        this.top = -1;
        this.stack = new Character[s.length()];
    }

    private boolean isEmpty() {
        return this.top == -1;
    }

    private boolean isFull() {
        return this.top == this.stack.length - 1;
    }

    private void push(Character c) {
        if (isFull()) {
            return;
        }
        this.top++;
        this.stack[this.top] = c;
    }

    private Character pop() {
        if (isEmpty()) {
            return (char) 0;
        }
        Character currentChar = this.stack[top];
        this.stack[this.top] = null;
        this.top--;
        return currentChar;
    }

    public boolean checkMatching() {
        for (int i = 0; i < this.str.length(); i++) {
            Character c = this.str.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                this.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (this.isEmpty()) {
                    return false;
                }
                Character opening = this.pop();
                if ((c == ')' && opening != '(') ||
                        (c == ']' && opening != '[') ||
                        (c == '}' && opening != '{')) {
                    return false;
                }
            }
        }
        if (isEmpty()) {
            return true;
        }
        return false;
    }
}