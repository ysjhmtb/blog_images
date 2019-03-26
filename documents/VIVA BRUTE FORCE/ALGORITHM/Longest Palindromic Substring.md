```c
/*
https://leetcode.com/problems/longest-palindromic-substring/

Longest Palindromic Substring

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char *s)
{
    int flag = 1;
    int start = 0;
    int end = strlen(s) - 1;

    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            flag = 0;
            return flag;
        }
    }

    return flag;
}

char *getSubstr(char *from, int start, int len)
{

    int mallocSize = strlen(from) - start;
    char *to = (char *)malloc(mallocSize);

    strncpy(to, from + start, len);
    return to;
}

char *copyStr(char *from)
{
    int size = strlen(from);
    char *to = (char *)malloc(size);
    strcpy(to, from);
    return to;
}

char *longestPalindrome(char *s)
{
    int max = 0;
    char *result = NULL;

    for (int i = 0; i < strlen(s); i++)
    {

        int searchLen = strlen(s) - i;
        int len = 1;

        while (len <= searchLen)
        {
            char *temp = getSubstr(s, i, len);

            int flag = isPalindrome(temp);

            if (flag != 0 && max < strlen(temp))
            {

                max = strlen(temp);
                result = copyStr(temp);
            }
            else
            {
                len++;
                continue;
            }
            len++;
        }
    }

    return result;
}

int main()
{
    printf("%s \n", longestPalindrome("babad"));
    printf("%s \n", longestPalindrome("cbbd"));

    return 0;
}
```

