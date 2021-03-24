# Determine if a string of brace characters is valid.
# e.g., '([{}])' is valid, but '}{' is not
# 
# This is pretty simple to solve with a makeshift pushdown automaton.
# I generally try to avoid piles of if/else's in Python, since usually
# there's some idiomatic way to do the same thing, but even after checking
# some other solutions for this challenge, I don't think there's a clever, 
# pythonic way to do this. Oh well, at least it's readable!

def validBraces(string):
    match = {'(':')', '[':']', '{':'}'}
    stack = []
    for b in string:
        if b in match:
            stack.append(b)
        else:
            if not stack:
                return False
            elif match[stack[-1]] == b:
                stack.pop()
            else:
                return False
    return not stack
