# Sum the digits of the input until the result is a single digit.
# Compound lambda functions! Just because I think lambdas are neat.

def digital_root(n):
    f = lambda x: x if x < 10 else (x % 10) + f(x // 10)
    g = lambda x: x if x < 10 else g(f(x))
    return g(n)
