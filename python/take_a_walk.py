# Determine if a series of cardinal, unit directions (n,s,e,w) 
# results in a circular, 10-minute walk (1 direction = 1min).
#
# While Python makes this easy with list.count(), we could implement
# this at a lower level by creating two stacks (one for each coordinate),
# and verifying that after a scan through the list, our final position 
# is the same as our initial position, kind of like a pushdown automaton.

def is_valid_walk(walk):
    return (len(walk) == 10 
        and walk.count('n') == walk.count('s')
        and walk.count('w') == walk.count('e')
    )
