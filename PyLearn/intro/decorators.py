#1
def start(x):
    def increment(y):
        return x + y
    return increment

#2
def my_start(func):
    def wrapper(x, y):
        return func(x, y)
    return wrapper

@my_start
def my_increment(x, y):
    return x + y

first_inc = start(0)
second_inc = start(8)

print(first_inc(3))
print(second_inc(3))

print(my_increment(0, 3))
print(my_increment(8,3))

#other exmp
def served_by(server):
    def decorator(func):
       def cached_server(n):
            return "{}, dear {}".format(func(n), server)
       return cached_server
    return decorator
    
def thank_you(func):
    def with_thanks(n):
        return "{}. Thank you very much!".format(func(n))
    return with_thanks

@served_by("sir")
def spam(n):
 spams = ("spam", ) * (n - 1)
 return "I would like {} and spam".format(", ".join(spams))


@thank_you
@served_by("sir")
def eggs(n):
 return "I would like {} eggs".format(n)

print(eggs(3))
