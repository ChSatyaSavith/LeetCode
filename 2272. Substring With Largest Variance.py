class Solution:
    def largestVariance(self, s: str) -> int:
        f1 = 0;
        f2 = 0
        var = 0

        pairs = [(l1,l2) for l1 in set(s) for l2 in set(s) if l1!=l2]

        for i in range(2):
            for pair in pairs:
                f1 = f2 = 0

                for letter in s:
                    if letter not in pair:
                        continue
                    if letter==pair[0]:
                         f1+=1

                    elif letter==pair[1]:
                         f2+=1

                    if f1<f2:
                        f1=f2=0
                        
                    elif f1>0 and f2>0:
                        var = max(var,f1-f2)
            s = s[::-1]

        return var