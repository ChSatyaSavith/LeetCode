class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        freq = {}

        for i in nums:
            if i in freq.keys():
                freq[i] += 1
            else:
                freq[i] = 1
        
        el = []
        f = []
        for key,value in freq.items():
            el.append(key)
            f.append(value)
        
        for i in range(len(f)-1):
            for j in range(0,len(f)-i-1):
                if f[j] < f[j + 1]:
                    f[j], f[j + 1] = f[j + 1], f[j]
                    el[j], el[j + 1] = el[j + 1], el[j]
        
        toreturn = []
        for i in range(k):
            toreturn.append(el[i])
        return toreturn
