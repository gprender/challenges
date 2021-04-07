# Given a 9x9 list representing a sudoku board, decide if it is a valid solution.
# 
# The 3 cases of 'groups' (rows/columns/blocks) on a sudoku board 
# get progressively harder to express, and thus require increasingly
# complicated list comprehensions. 
#
# There were some super-verbose solutions for this challenge done in 
# a few lines, but I like my code to be readable, so I did this! 
# Maybe it'd be a good idea to split the cases into 3 functions, too.

def valid_solution(board):
    for row in board:
        if not valid_group(row): 
            return False
        
    cols = [[row[i] for row in board] for i in range(9)]
    for col in cols:
        if not valid_group(col): 
            return False
        
    for i in range(0,9,3):
        for j in range(0,9,3):
            block = [row[j:j+3] for row in board[i:i+3]]  # 2d block
            block = [e for sublist in block for e in sublist]  # flattened block
            if not valid_group(block):
                return False
        
    return True
    
def valid_group(g):
    return (0 not in g) and (len(set(g)) == 9)
