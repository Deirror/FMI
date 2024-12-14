#tuple - immutable, ordered as list

#has methods - index, count, sort...

args = ([1,'a']) # not a tuple
args = (2, args) # tuple OK

print(args)

# Immutable са числата, низовете, tuple-ите, True, False, None etc.

args[1][1] = 's'

print(args[1])
