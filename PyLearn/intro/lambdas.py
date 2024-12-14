from secrets import choice
from string import ascii_letters, digits, punctuation

pass_gen = lambda x: ''.join(choice(ascii_letters + digits + punctuation) for _ in range(x))

def func(*args, **kwargs):
    return list(map(lambda x: ('', x), args)) + list(kwargs.items())

print(pass_gen(100))
