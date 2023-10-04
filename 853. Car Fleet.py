class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        time = [(position[i],speed[i]) for i in range(len(speed))]
        time.sort(reverse=True)
        stack = [time[0],]

        for i in range(1,len(speed)):
            if(float((target-time[i][0]))/time[i][1]<=float((target-stack[-1][0]))/stack[-1][1]): #basically checking if back car ka time <= front car ka time
                continue
            else:
                stack.append(time[i])
        return len(stack)