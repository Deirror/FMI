class Engine:
    def __init__(self, horse_power):
        self.horse_power = horse_power

    def __str__(self):
        return f'Engine({self.horse_power})'

class Wheel:
    def __init__(self, size):
        self.size = size

    def __str__(self):
        return f'Wheel size: {self.size}'

class Car:
    def __init__(self, color, model, year, horse_power, wheel_size):
        self.color = color
        self.model = model
        self.year = year
        self.engine = Engine(horse_power)
        self.wheels = [Wheel(wheel_size) for _ in range(4)]

    def __str__(self):
        return f'{self.color.capitalize()} {self.model.capitalize()}, made in {self.year} -> {self.engine}, {self.wheels[0]}'

car = Car('red', 'porsche', '1992', 350, 5)

print(car)

# BONUS - Nested classes
class Company:
    class Employee:
        pass 
        """Logic here for Employee"""

    def __init__(self):
        pass
        """Here inner class Employee can be used"""
