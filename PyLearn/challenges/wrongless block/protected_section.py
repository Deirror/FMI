class ProtectedSection:
    def __init__(self, log=(), suppress=()):
        self.log = log
        self.suppress = suppress
        self.exception = None

    def __enter__(self):
        self.exception = None  # reset state
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        if exc_type is None:
            return False

        if exc_type in self.log:
            self.exception = exc_value
            return True
        if exc_type in self.suppress:
            return True
        return False

with ProtectedSection(log=(ZeroDivisionError, IndexError), suppress=(TypeError, ZeroDivisionError, Exception)) as err:
    x = 1 / 0

print(err.exception)
# division by zero
print(type(err.exception))
# <class 'ZeroDivisionError'>

