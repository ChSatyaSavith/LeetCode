class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """

        s = strip(s)
        s = s[::-1]
        for i in range(len(s)):
            if s[i]==" ":
                return i
        return len(s)