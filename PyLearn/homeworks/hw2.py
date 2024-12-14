MAX_COST = 42.00
UNIQUE_WORDS = ('храст', 'shrub', 'bush')

def dict_examine(my_dict):
    if type(my_dict) is not dict:
        return None
    else:
        key = my_dict.get('name')
        if key is None:
            return None

        if key.lower() in UNIQUE_WORDS:
            if len(my_dict) == 2:
                cost = my_dict.get('cost')
                if cost is not None:
                    return cost
                else:
                    return None
            elif len(my_dict) == 1:
                return 0
        else:
            return None

def function_that_says_ni(*args, **kwargs):
    price = 0.0
    unique_letter = set()

    if args:
        for value in args:
            result = dict_examine(value)
            if result is not None:
                price += result

    if kwargs:
        for key, value in kwargs.items():
            result = dict_examine(value)
            if result is not None:
                price += result
                unique_letter.update(set(key))

    if price == 0 or len(unique_letter) % int(price) != 0 or price > MAX_COST:
        return "Ni!"
    else:
        return f"{price:.2f}лв"
