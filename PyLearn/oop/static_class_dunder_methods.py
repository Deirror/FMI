@dataclass # Automatically implements dunder methods for you
class Surprise:
    pass

class Car:
    count = 0
    unknown = 0
    def __init__(self):
        Car.count += 1
        self.year = -1000
        self._pr_var = None # Private Convention
        
    @property
    def year(self):
        pass

    @year.setter
    def year(self, year):
        self.year = year

    @year.deleter
    def year(self):
        del self.year

    @staticmethod
    def get_count():
        return Car.count

    @classmethod
    def get_unknown(cls):
        return cls.unknown
    
    def __str__(self):
        pass
    
    def __repr__(self):
        pass
    
    def __eq__(self, other):
        pass
    
    def __ne__(self, other):
        pass
    
    def __gt__(self, other):
        pass
    
    def __ge__(self, other):
        pass
    
    def __lt__(self, other):
        return self.year < other.year
    
    def __le__(self, other):
        pass

car = Car()
print(Car.get_unknown())
