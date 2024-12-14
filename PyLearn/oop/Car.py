class Car:
    count_objects = 0 # static variable
    def __init__(self, model, year, color, for_sale):
        self.model = model
        self.year = year
        self.color = color
        self.for_sale = for_sale
        Car.count_objects += 1

    def __str__(self):
        return f'{self.color.capitalize()} {self.model.capitalize()}, made in {self.year} -> for sale? {'YESS' if self.for_sale else 'HECK NO'}'


car = Car('Porsha', 1939, 'red', False)
print(car)
