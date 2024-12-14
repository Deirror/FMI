class Animal:
    alive = True

class Dog(Animal):
    def speak(self):
        print('WOOOOOOF!')
      
class Cat(Animal):
    def speak(self):
        print('MEOOOWWW!')

class Car: # !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! It looks like a duck and quacks like a duck, it must be a duck!
    def speak(self):
        print('BRRRRRMM!')

animals = [Dog(), Cat(), Car()]
for animal in animals:
    animal.speek() # perfectly fine
