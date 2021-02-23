# challenge: count the number of bits equal to 1 in an integer's binary representation
# recursive lambda functions WOOOOOOO

def count_bits(n):
    f = lambda x: 0 if x == 0 else (x % 2) + f(x // 2) 
    return f(n)
