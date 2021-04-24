# Given two objects, determine if they have the same nested structure.
# e.g., (1,2) => True, ([1,[1,1]], [2,[2,2]]) => True, ([1,[1]], [2,2]) => False
# 
# This was a weird kind of language problem with a number of arbitrary rules,
# e.g., string are not to be treated as containers, and a list is not structurally
# the same as the corresponding tuple.
# 
# Explicit type-checking generally makes me cringe, but there's no way to get
# around it for this problem. At least we can use a starmap, which is fun.

from itertools import starmap

def same_structure_as(original,other):
    if is_container(original) and is_container(other):
        return (
            type(original) == type(other) 
            and len(original) == len(other) 
            and all(starmap(
                same_structure_as, 
                [(a,b) for (a,b) in zip(original,other)]
            ))
        )
    elif is_container(original) or is_container(other):
        return False
    else:
        return True

def is_container(x):
    try:
        it = iter(x)
    except:
        return False
    return not isinstance(x, str)
