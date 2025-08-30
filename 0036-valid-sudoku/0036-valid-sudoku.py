class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for i in board:
            line = []
            for j in i:
                if j == '.':
                    continue
                elif j in line:
                    return False
                else:
                    line.append(j)
          

        for k in range(9):
            line = []
            for l in range(9):
                if board[l][k] == '.':
                    continue
                elif board[l][k] in line:
                    return False
                else:
                    line.append(board[l][k])
          

        for x in [1,4,7]:
            for y in [1,4,7]:
                box = []
                for h in [-1,0,1]:
                    for z in [-1,0,1]:
                        if board[x+h][y+z] == '.':
                            continue
                        elif board[x+h][y+z] in box:
                            return False
                        else:
                            box.append(board[x+h][y+z])
        
        return True    




                                     