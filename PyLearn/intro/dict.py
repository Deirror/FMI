
#dict - set, but has key(index) to access a value

my_dict = {"IT" : 1, 'USA': 66, 'GR':44}

print('Eric\'s last names is ' + str(my_dict['IT']))

my_dict['FR'] = -10000000

print(my_dict.get('UK','OMG no')) # error, don't have throw excpts
