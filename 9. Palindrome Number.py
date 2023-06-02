class Solution(object):
    def isPalindrome(self, x):
        if(x<0): return False

        div = 1
        while(x>=div*10): div*=10

        while(x):
            if(x%10 != x//div): return False
            x = (x%div) // 10
            div /= 100
        return True
        