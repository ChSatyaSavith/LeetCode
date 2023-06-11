class SnapshotArray(object):

    def __init__(self, length):
       self.arr = [[(0,0)] for i in range(length)]
       self.snap_id = 0;
        

    def set(self, index, val):
        self.arr[index].append((self.snap_id,val))
        

    def snap(self):
        self.snap_id+=1
        return self.snap_id-1
        

    def get(self, index, snap_id):
        history = self.arr[index]
        left = 0
        right = len(history) - 1
        
        while(left<=right):
            mid = (left+right)//2
            
            if(history[mid][0]<=snap_id):
                left = mid+1
            else:
                right = mid-1
        return history[right][1];
        


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)