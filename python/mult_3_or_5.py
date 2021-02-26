# Return the sum of the unique multiples of 3 or 5 between 0 and 'number'
# Kind of a weird problem, but a good opportunity to use list comprehensions.

def solution(number):
    multiples_of_3 = [i for i in range(3, number, 3)]
    multiples_of_5 = [i for i in range(5, number, 5) if (i % 3) != 0]
    return sum(multiples_of_3) + sum(multiples_of_5)
