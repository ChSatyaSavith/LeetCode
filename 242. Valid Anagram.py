class Solution(object):
    def isAnagram(self, s, t):
        #First Method
        if(len(s)!=len(t)):
            return False
        
        c_s = {}
        c_t = {}

        for i in range(len(s)):
            c_s[s[i]] = c_s.get(s[i],0) + 1
            c_t[t[i]] = c_t.get(t[i],0) + 1
        return c_s == c_t
        
        #Second Method
        return ''.join(sorted(s)) == ''.join(sorted(t))
        