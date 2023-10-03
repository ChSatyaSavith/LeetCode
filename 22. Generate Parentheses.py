class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        
        arr = []
        def recursion(string,left,right):
            if(left==n and right==n):
                arr.append(string)
            if(left<=n and right<=n):
                recursion(string+"(",left+1,right)
                recursion(string+")",left,right+1)
            return

        recursion("(",1,0)
        
        def valid(string):
            stack = []
            for i in string:
                if(i=="("):
                    stack.append(")")
                else:
                    if not stack:
                        return False
                    else:
                        stack.pop()
            if not stack:
                return True
        
        new_arr = []
        for i in arr:
            if(valid(i)):
                new_arr.append(i)

        return new_arr