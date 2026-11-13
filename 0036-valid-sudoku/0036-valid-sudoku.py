class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        # checking in each row
        for i in range(9):
            s = set()
            for j in range(9):
                if board[i][j] != ".":
                    if board[i][j] in s:
                        return False
                    else:
                        s.add(board[i][j])
        
        # checking each column
        for i in range(9):
            s = set()
            for j in range(9):
                if board[j][i] != ".":
                    if board[j][i] in s:
                        return False
                    else:
                        s.add(board[j][i])

        # checking each box
        for i in range(0,9,3):
            for j in range(0,9,3):
                s = set()
                for k in range(i, i+ 3):
                    for l in range(j, j+3):
                        if board[k][l] != ".":
                            if board[k][l] in s:
                                return False
                            else:
                                s.add(board[k][l])

        return True
