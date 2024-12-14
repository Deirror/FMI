class BulgarianToEnglishInterpreter:
    BGEN_TRANSLATER = {
        'а': 'a',
        'б': 'b',
        'в': 'v',
        'г': 'g',
        'д': 'd',
        'е': 'e',
        'ж': 'j',
        'з': 'z',
        'и': 'i',
        'й': 'j',
        'к': 'k',
        'л': 'l',
        'м': 'm',
        'н': 'n',
        'о': 'o',
        'п': 'p',
        'р': 'r',
        'с': 's',
        'т': 't',
        'у': 'y',
        'ф': 'f',
        'х': 'h',
        'ц': 'ts',
        'ч': 'ch',
        'ш': 'sh',
        'щ': 'sht',
        'ъ': 'u',
        'ь': 'j',
        'ю': 'ju',
        'я': 'ja'
    }

    def __converter(self, word: str):
        if word.lower() in self.BGEN_TRANSLATER:
            return self.BGEN_TRANSLATER[word] if word.islower() else self.BGEN_TRANSLATER[word.lower()].capitalize()
        else:
            return word

    def __init__(self, text: str):
        self.bg_text = text
        self.en_text = ''.join([self.__converter(word) for word in text])

    def translated_en_text(self):
        return self.en_text

    def __repr__(self):
        return str({'bg_text': self.bg_text, 'en_text': self.en_text})

def main():
    translator = BulgarianToEnglishInterpreter(input('Въведи текст:\n'))
    print(translator.translated_en_text())

if __name__ == '__main__':
    main()
