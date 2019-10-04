package kakao2020;

/*
https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/

https://programmers.co.kr/learn/courses/30/lessons/60057

Accepted
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Kakao2020N1 {
    public List<String> cutStr(String str, int size) {
        List<String> cutStrs = new ArrayList<>();
        int start = 0;
        while (start < str.length()) {
            if (start + size <= str.length()) {
                cutStrs.add(str.substring(start, start + size));
                start += size;
            } else {
                cutStrs.add(str.substring(start, str.length()));
                start += size;
            }
        }
        return cutStrs;
    }

    public String compress(List<String> cutStrs) {
        StringBuilder compressed = new StringBuilder("");

        int start = 0;
        int count = 0;
        while (start < cutStrs.size()) {

            int end = start + 1;
            int jump = 1;
            while (end < cutStrs.size()) {
                if (cutStrs.get(start).equals(cutStrs.get(end))) {
                    jump++;
                    end++;
                } else {
                    break;
                }
            }
            if (jump == 1) {
                compressed.append(cutStrs.get(start));
            } else {
                compressed.append(jump + cutStrs.get(start));
            }
            start += jump;
        }
        return compressed.toString();

//        Map<String, Integer> strCount = new HashMap<>();
//        for (String str : cutStrs) {
//            if (strCount.containsKey(str)) {
//                strCount.put(str, strCount.get(str) + 1);
//            } else {
//                strCount.put((str), 1);
//            }
//        }
//        StringBuilder compressed = new StringBuilder("");
//        for (String key : strCount.keySet()) {
//            if (strCount.get(key) == 1) {
//                compressed.append(key);
//            } else {
//                compressed.append(strCount.get(key) + key);
//            }
//        }
//        return compressed.toString();
    }

    public int solution(String s) {
        int answer = s.length();

        for (int i = 1; i <= s.length(); i++) {
            List<String> cutStrs = this.cutStr(s, i);
            String compressed = this.compress(cutStrs);
            answer = Integer.min(answer, compressed.length());
        }
        return answer;
    }
}
