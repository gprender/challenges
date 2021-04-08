# liss.py - Longest Increasing Subsequence
# 
# I had a question come up in a technical interview for which I couldn't
# find a good solution. After a few days of chewing on it, I figured it
# could be reduced to the 'longest increasing subsequence' problem, so
# here's my own personal attempt at redemption!
# 
# The input to this problem is a list of integers, and the output is,
# you guessed it, the longest increasing subsequence therein, which
# might not be contiguous in the original list.
# 
# Sounds simple right? I found it to be deceptively difficult to solve
# in practice, and if you've never encountered this problem yourself, 
# I'd encourage you to take a look at it on your own.
# 
# Spoiler alert: dynamic programming!

def liss(v):
    len_liss = [0] * len(v)  # length of the liss up to a certain point
    pred = [0] * len(v)  # the predecessor in the liss up to that point

    for i in range(len(v)):
        best_pred = i 
        for j in range(i):  # pick the predecessor w/ the longest liss
            if v[i] > v[j] and len_liss[j] > len_liss[best_pred]:
                best_pred = j

        # extend that subsequence with the current element
        pred[i] = best_pred
        len_liss[i] = len_liss[best_pred] + 1

    # unravel our memoization process to find the actual liss
    sol = []
    max_liss = max(len_liss)
    idx = v.index(max_liss)
    while True:
        sol.insert(0, v[idx])
        if idx == pred[idx]:
            break
        else:
            idx = pred[idx]

    return sol
