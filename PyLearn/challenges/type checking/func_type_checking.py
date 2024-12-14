IOS_MESSAGE = {'in': 'input arguments', 'out': 'output values'}

def try_io(io, valid_types, *args):
    for arg in args:
        if not isinstance(arg, valid_types):
            print(f'Invalid {IOS_MESSAGE[io]}, expected {', '.join(str(x) for x in valid_types)}!')
            return

def type_check(io):
    def types(*valid_types):
        def wrapper(func):
            def power_wrapper(*args, **kwargs):
                variables = list(args) + list(kwargs.values())
                if io == 'in':
                    try_io(io, valid_types, *variables)
                result = func(*variables)
                if io == 'out':
                    try_io(io, valid_types, result)
                return result
            return power_wrapper
        return wrapper
    return types

@type_check('in')(int, float)
@type_check("out")(int, float)
def power(num, pwr):
    return num ** pwr

@type_check("in")(str)
def concatenate(*strings, separator=' beep boop '):
    return separator.join(strings)
