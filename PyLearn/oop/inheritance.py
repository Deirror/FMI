
class Animal:
    def __init__(self, name):
        self.name = name
        self.is_alive = True

    def eat(self):
        print(f'{self.name} eats')

    def sleep(self):
        print(f'{self.name} sleeps')

class Prey(Animal):
    pass

class Predator(Animal):
    pass

class Dog(Prey, Predator):
    def __init__(self, name):
        super().__init__(name) # !!!!
        # or Animal.__init__(self, name) also valid

    def speek(self):
        print(f'WOOFFFFFFFFFFFFFFFFFFFFFFFFHH')

dog = Dog('VulkEdinak1')
animal = Animal('VulkEdinak69')

dog.eat()
dog.sleep()

dog.speek()

