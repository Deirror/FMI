import random
from asyncio import exceptions, InvalidStateError


GAME_NAME = 'intg'
player_name = 'Unknown'
DIM = (2, 5, 10, 20)

def validate_name(name):
    if not name.isalpha():
        raise InvalidStateError('Name must contain only letters.')

def print_abbreviate(func):
    def wrapper(text, end='\n'):
        print(f'{GAME_NAME}>{func(text)}', end=end)
    return wrapper

def print_player_name(name):
    def decorator(func):
        def wrapper(text=''):
             print(f'{player_name}>', end='')
             return func(text)
        return wrapper
    return decorator

def validate_type_str(text):
    if isinstance(text, str):
        return text
    raise InvalidStateError('Text must be str')

@print_abbreviate
def custom_print(text, end='\n'):
    return validate_type_str(text)

@print_player_name(player_name)
def custom_input(text=''):
   return input(validate_type_str(text))

@print_abbreviate
def greet(name):
    return f'Hello {name}!'

@print_abbreviate
def print_interval(x):
    return f'|{' ' * x}|'

def introduction():
    global player_name
    custom_print('What is your name?', '')
    player_name = input(' -> ')

def validate_dim(dim):
    if dim.isdigit():
        if int(dim) not in DIM:
            raise InvalidStateError('Dimension must be in ' + str(DIM))
    else:
        raise InvalidStateError('Dimension must be a number')

def get_dim():
    dim = custom_input()
    try:
        validate_dim(dim)
    except InvalidStateError as error:
        custom_print(str(error))
    return dim

def gen_rand(dim):
    gen_list = [x for x in range(1, dim)]
    random.shuffle(gen_list)
    return random.choice(gen_list)

def loop_game():
    times = 22
    while True:
        custom_print('-' * times)
        custom_print(f'Choose an interval{DIM}')
        dim = int(get_dim())
        print_interval(dim)
        com_choice = int(gen_rand(dim))
        custom_print(f'Write your guess')
        guess = int(custom_input())
        if guess == com_choice:
            custom_print('Correct!')
        else:
            res = com_choice - guess
            custom_print(f'So close -> {str(res) + ' behind' if res > 0 else str(res*-1) + ' front'}')


def main():
    introduction()
    greet(player_name)
    try:
        validate_name(player_name)
    except InvalidStateError as error:
        custom_print(str(error))
    loop_game()

if __name__ == '__main__':
    main()
