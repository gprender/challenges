# Convert a sequence of 10 integers into a phone number string.
# e.g., (0 1 2 3 4 5 6 7 8 9) => '(012) 345-6789'

def create_phone_number(n):
    nstring = ''.join([str(i) for i in n])
    return f'({nstring[:3]}) {nstring[3:6]}-{nstring[6:]}'
