/*
https://leetcode.com/problems/valid-parentheses/

Accepted
time complexity O(N)
 */

import java.util.HashMap;
import java.util.Stack;

public class ValidParentheses {
    private HashMap<Character, Character> mappings;

    public ValidParentheses() {
        this.mappings = new HashMap<>();
        this.mappings.put(')', '(');
        this.mappings.put('}', '{');
        this.mappings.put(']', '[');
    }

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (this.mappings.containsKey(c)) {
                char topE = stack.empty() ? '#' : stack.pop();
                if (topE != this.mappings.get(c))
                    return false;
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
}


/*
public class ValidParentheses{
    private HashMap<Character,Character> mappings;

    public ValidParentheses(){
        this.mappings = new HashMap<>();
        this.mappings.put(')','(');
        this.mappings.put('}','{');
        this.mappings.put(']','[');
    }
    public boolean isValid(String s){
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(this.mappings.containsKey(c)){
                char topE = stack.empty()?'#':stack.pop();
                if(topE != this.mappings.get(c))
                    return false;
            }else{
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}
*/