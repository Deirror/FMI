class Library:
    def __init__(self, name):
        self.name = name
        self.books = []

    def add_book(self, book):
        self.books.append(book)

    def list_books(self):
        return [f'{book.title} by {book.author}' for book in self.books]

class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author

library = Library('Python')

library.add_book(Book('Python\'s A Strange Language', 'Too High, LOL'))
print(library.list_books())
