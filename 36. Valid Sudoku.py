class Solution(object):
    def isValidSudoku(self, board):
        rows = {0:[],1:[],2:[],3:[],4:[],5:[],6:[],7:[],8:[]}
        columns = {0:[],1:[],2:[],3:[],4:[],5:[],6:[],7:[],8:[]}
        boxes = {(0,0):[],(0,1):[],(0,2):[],(1,0):[],(1,1):[],(1,2):[],(2,0):[],(2,1):[],(2,2):[]}

        r = len(board)
        c = len(board[0])

        for i in range(r):
            for j in range(c):
                if(board[i][j]=="."):
                    continue
                else:
                    if(board[i][j] not in rows[i] and board[i][j] not in columns[j] and board[i][j] not in boxes[(i//3,j//3)]):
                        rows[i].append(board[i][j])
                        columns[j].append(board[i][j])
                        boxes[(i//3,j//3)].append(board[i][j])
                    else:
                        return False
        return True
                