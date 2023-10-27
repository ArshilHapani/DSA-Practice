package code.stack.infixToPostFix;

import java.util.Stack;

class Main {
    public static void main(String[] args) {
        // String s = "{(a+b)*(c+d)}";
        String s = "k+l-m*n+(o^p)*w/u/v*t+q^j^a"; // kl+mn*-op^w*u/v/t*+qj^a^+
        int length = s.length();
        char[] infixString = s.toCharArray();
        char[] postFixExp = infixToPostfix(infixString, length);
        System.out.println("PostFix = " + new String(postFixExp));
    }

    static int precedence(char c) {
        if (c == '^') {
            return 3;
        } else if (c == '/' || c == '*') {
            return 2;
        } else if (c == '+' || c == '-') {
            return 1;
        }
        return 0;
    }

    static boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    static boolean isOpeningParenthesis(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    static boolean isClosingParenthesis(char c) {
        return c == ')' || c == '}' || c == ']';
    }

    static char[] infixToPostfix(char[] c, int len) {
        Stack<Character> newStack = new Stack<>();
        char[] postFixExp = new char[len];
        int i = 0, j = 0;
        while (i < len) {
            char currentChar = c[i];

            if (!isOperator(currentChar) && !isOpeningParenthesis(currentChar) && !isClosingParenthesis(currentChar)) {
                postFixExp[j] = currentChar;
                j++;
                i++;
            } else if (isOpeningParenthesis(currentChar)) {
                newStack.push(currentChar);
                i++;
            } else if (isClosingParenthesis(currentChar)) {
                while (!newStack.isEmpty() && !isOpeningParenthesis(newStack.peek())) {
                    postFixExp[j] = newStack.pop();
                    j++;
                }
                newStack.pop(); // Popping ),],} whatever
                i++;
            } else {
                if (newStack.isEmpty() || precedence(currentChar) > precedence(newStack.peek())) {
                    newStack.push(currentChar);
                    i++;
                } else {
                    postFixExp[j] = newStack.pop();
                    j++;
                }
            }
        }

        while (!newStack.isEmpty()) {
            postFixExp[j] = newStack.pop();
            j++;
        }
        return postFixExp;
    }
}
