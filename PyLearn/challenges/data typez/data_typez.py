class DataTypes:
    VALID_TYPES = {
        'int': int,
        'float': float,
        'str': str,
        'list_str': list[str],
        'list_int': list[int],
        'dict_str_any': dict[str],
    }

    def __init__(self, input_type: str):
        if input_type not in DataTypes.VALID_TYPES:
            raise TypeError('Not supported input type')
        self.input_type = DataTypes.VALID_TYPES[input_type]

    def typify(self, input_value):
        try:
            if self.input_type == list[str]:
                return [str(x) for x in eval(input_value)]
            elif self.input_type == list[int]:
                return [int(x) for x in eval(input_value)]
            elif self.input_type == dict[str]:
                return dict(eval(input_value))
            else:
                return self.input_type(input_value)
        except (ValueError, SyntaxError, TypeError) as e:
            print(f"Error in converting input: {e}")
            return None


validator = DataTypes(input('Enter type (e.g., int, float, str, list_str, list_int, dict_str_any): '))
print(validator.typify(input('Enter argument(s): ')))
