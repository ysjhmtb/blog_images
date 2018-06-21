> 535. [Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/description/)
>
> > Note: This is a companion problem to the [System Design](https://leetcode.com/problemset/system-design/) problem: [Design TinyURL](https://leetcode.com/problems/design-tinyurl/).
>
> TinyURL is a URL shortening service where you enter a URL such as `https://leetcode.com/problems/design-tinyurl` and it returns a short URL such as `http://tinyurl.com/4e9iAk`.
>
> Design the `encode` and `decode` methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

<br>

[Easy solution in java, 5 line code.](https://leetcode.com/problems/encode-and-decode-tinyurl/discuss/100276/Easy-solution-in-java-5-line-code.) 의 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Codec ref = new Codec();

        String input = "https://leetcode.com/problems/design-tinyurl";
        String output = ref.encode(input);
        System.out.println(output);

        String test = ref.decode(output);
        System.out.println(test);
        System.out.println(input.equals(test));
    }
}

class Codec {

    List<String> urls = new ArrayList<String>();

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        urls.add(longUrl);
        return String.valueOf(urls.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        int index = Integer.valueOf(shortUrl);
        return (index < urls.size()) ? urls.get(index) : "";
    }
}
```

