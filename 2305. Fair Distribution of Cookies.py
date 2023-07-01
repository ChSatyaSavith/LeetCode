class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        unfairness = float('inf')
        dist = [0]*k

        def backtrack(i):
            nonlocal unfairness,dist

            if i==len(cookies):
                unfairness = min(unfairness,max(dist))
                return
            if unfairness<=max(dist):
                return

            for j in range(k):
                dist[j] += cookies[i]
                backtrack(i+1)
                dist[j] -= cookies[i]

        backtrack(0)
        return unfairness