# Library-less solution to check if an integer is a perfect square.

def is_square(n):
    if (n < 0):
        return False  # real squares only
    else:
        return binary_search_is_square(0,n,n)

def binary_search_is_square(min,max,n):
    # base case: [min,max] are adjacent integers
    if max - min == 1:
        return False
    
    midpoint = (min + max) // 2
    midpoint_squared = midpoint * midpoint
    
    if midpoint_squared < n:
        return binary_search_is_square(midpoint,max,n)
    elif midpoint_squared > n:
        return binary_search_is_square(min,midpoint,n)
    else:
        return True