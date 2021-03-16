# Translate a text string into pig latin, leaving punctuation unaffected.
# 
# This is a fun opportunity for a one line compound list comprehension.
# I'll be honest that while fancy one-liners are considered the most Pythonic solutions,
# I don't think they're the best practices, just because of their poor readability.

def pig_it(text):
    return " ".join([f'{x[1:]}{x[0]}ay' if x not in {'.',',','?','!'} else x for x in text.split()])
