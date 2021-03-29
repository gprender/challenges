# Find the one integer in a list that has a different parity than the rest.
# i.e., if the list contains n-1 even numbers, find the odd, and visa versa.
# 
# I know this solution looks a bit clunky (by Python standards anyway), but
# I wanted the function to do the least amount of work possible for large n.
#
# We're given that n >= 3, so we can conclude which parity is the outlier by
# examining the first 3 elements of the list. Then, we do a non-modifying
# scan to find the element which has the outlier parity. This avoids making
# a copy of a potentially very large list, and finds the outlier in n/2 time 
# on average.

def find_outlier(integers):
    goal_rem = 0 if (sum([(i % 2) for i in integers[:3]]) > 1) else 1
    for i in integers:
        if (i % 2) == goal_rem:
            return i
