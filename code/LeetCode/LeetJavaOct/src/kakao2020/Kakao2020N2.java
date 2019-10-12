package kakao2020;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/*
https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/

https://programmers.co.kr/learn/courses/30/lessons/60058

 */
public class Kakao2020N2 {

    public boolean isBalancedBrackets(String str) {
        Map<Character, Integer> balance = new HashMap<>();
        char[] strChar = str.toCharArray();
        for (char e : strChar) {
            if (balance.containsKey(e)) {
                balance.put(e, balance.get(e) + 1);
            } else {
                balance.put(e, 1);
            }
        }
        return balance.get('(') == balance.get(')') ? true : false;
    }

    public boolean isRightBrackets(String str) {
        char[] strChar = str.toCharArray();
        Stack<Character> stack = new Stack<>();

        for (char e : strChar) {
            if (e == '(') {
                stack.push('(');
            } else if (!stack.empty()) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.size() == 0;
    }

    public String solution(String p) {

        if (p == null || p.equals("")) {
            return "";
        }

        String answer = "";

        int ustart = 0;
        int uend = 0;
        int vstart = 0;
        int vend = 0;

        for (int i = ustart + 2; i <= p.length(); i++) {
            if (this.isBalancedBrackets(p.substring(ustart, i))) {
                uend = i;
                vstart = i;
                vend = p.length();
                break;
            }
        }

        String u = p.substring(ustart, uend);
        String v = p.substring(vstart, vend);

        if (this.isRightBrackets(u)) {
            answer = u + this.solution(v);
        } else {
            answer = "(" + this.solution(v) + ")";

            String ucpy = u.substring(1, u.length() - 1);
            u = "";
            for (int i = 0; i < ucpy.length(); i++) {
                if (ucpy.charAt(i) == '(') {
                    u += ")";
                } else {
                    u += "(";
                }
            }
            answer += u;
        }
        return answer;
    }
}
