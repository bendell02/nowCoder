class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (NULL == needle || NULL == haystack) { return NULL; }

        int lenHaystack = strlen(haystack);
        int lenNeedle = strlen(needle);
        if (0 == lenNeedle) { return haystack; }

        for (int i = 0; i <= (lenHaystack - lenNeedle); ++i) {
            for (int j = 0; j < lenNeedle; ++j) {
                if (haystack[i + j] != needle[j]) { break; }

                if (lenNeedle - 1 == j) {
                    return &haystack[i];
                }
            }
        }

        return NULL;
    }
};
