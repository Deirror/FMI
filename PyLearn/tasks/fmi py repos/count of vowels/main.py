def number_of_vowels_v1(text):
    return (text.count('a') +
            text.count('e') +
            text.count('i') +
            text.count('o') +
            text.count('u'))
    
VOWELS = 'aeiou'
def number_of_vowels_v2(text):
    count = 0
    for ch in text:
        if ch in VOWELS:
            count += 1
    return count
    
def number_of_vowels_v3(text):
    return sum(1 for ch in text if ch.lower() in VOWELS)

if __name__ == '__main__':
    print(number_of_vowels_v1("The quick brown fox jumps over the lazy dog."))
