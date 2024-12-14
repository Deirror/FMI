def can_convert_to_float(s):
    try:
        return '.' in s and float(s)
    except ValueError:
        return False

class FloatPartsSpliter:
    def __init__(self, str_float_number):
        # checks if the given stringed number is of type float
        if can_convert_to_float(str_float_number):
            self.whole_part, self.dec_part = [int(x) for x in str_float_number.split('.')]
        else:
            raise ValueError('Not a float')

    def __repr__(self):
        return str({'whole_part': self.whole_part, 'dec_part': self.dec_part})

def main():
    print(FloatPartsSpliter(input('Въведи число:')))

if __name__ == '__main__':
    main()
