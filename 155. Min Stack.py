class MinStack(object):

    def __init__(self):
        self.stack = []
        self.min_arr = []
        self.min = 2**31
        self.min_arr.append(self.min)
    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if(val<=self.min):
            self.min = val
            self.min_arr.append(val)
        self.stack.append(val)

    def pop(self):
        """
        :rtype: None
        """
        top = self.stack[len(self.stack)-1]
        if(top==self.min):
            self.min_arr.pop()
            self.min = self.min_arr[len(self.min_arr)-1]
        return self.stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.stack[len(self.stack)-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        if not self.min_arr:
            return 0
        return self.min
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()