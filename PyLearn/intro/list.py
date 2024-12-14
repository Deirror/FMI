
#list - mutable, fast indexing, slow value searching
from os.path import curdir

my_list = []
my_list = list() #def constructor calling

#print(help(list))

my_list.append(444)
my_list.append('DDDH')
print(my_list)
print(f"OMG, Wo ist {my_list[1] * 4}", end='')

cust_list = ['hem','shto spam','nz']

print('hem' in cust_list)

cute_animals = ['cat', 'raccoon', 'panda', 'red panda', 'marmot']
print(cute_animals[1:-1]) # without cat

cute_animals[1:3] # ['raccoon', 'panda']
cute_animals[-1] # 'marmot'
cute_animals[1:-1] # ['raccoon', 'panda', 'red panda']
cute_animals[::-1] # ['marmot', 'red panda', 'panda', 'raccoon', 'cat']
cute_animals[-1:0:-1] # ['marmot', 'red panda', 'panda', 'raccoon']
cute_animals[-1:0:-2] # ['marmot', 'panda

for smth in cust_list:
    cute_animals.append(smth)
print(cute_animals)

cheeses = ['brie', 'bergkäse', 'kashkaval', 'leipäjuusto']
teas = ['chai', 'earl grey', 'jasmine', 'oolong']
breakfast = [cheeses, teas]
print(breakfast[0][1]) # bergkäse
breakfast[1][2] = ['шǾеȀбе', 'ǿютǼ чушǾǼ', 'Ȃцет с чесъȁ']
print(breakfast)

