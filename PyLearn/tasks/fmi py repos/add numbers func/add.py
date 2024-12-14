class Add:
    def __init__(self, value):
        self.value = value

    def __call__(self, other_value=0):
        return Add(self.value + other_value)

    def __int__(self):
        return self.value

    def __add__(self, other):
        return self.value + (int(other) if isinstance(other, Add) else other)

    def __repr__(self):
        return str(self.value)

def add(value):
    return Add(value)

print(add(1)(2))          # 3
print(add(1)(2)(3))       # 6
print(add(1)(2)(3)(4))    # 10
print(add(1))             # 1

add_two = add(2)
print(add_two)            # 2
print(add_two + 5)        # 7
print(add_two(3))         # 5
print(add_two(3)(5))      # 10
