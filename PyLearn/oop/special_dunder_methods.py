class Hand:
 def __init__(self):
 ...
 def __getitem__(self, index):
 return (self.thumb, self.index_finger, self.middle_finger,
 self.ring_finger, self.pinkie)[index]

  def __setitem__(self, index, value):
 if index == 0:
 self.thumb = value
 elif index == 1:
 self.index_finger = value

def __getattr__(self, name):
 return f"ТȂǶǴ ǹ ȄъǾǴ v1.0. Вȅǹ Ȃщǹ ȁяȀǴ {name} :(" # __getattr__ e fallback механизъм, който Python ще потърси само в случай, че няма
# дефиниран атрибут с търсеното име.

def __setattr__(self, name, value):
 print(f"НȂǶǴ ȅȆȂǽȁȂȅȆ ǻǴ {name} - {value}")
 object.__setattr__(self, name, value)

def __getattribute__(self, name):
 print(f"НяǾȂǽ ȀǼ ǵъȄǾǴ ȃȂ ȃȄъȅȆǼȆǹ Ǽ ǼȅǾǴ {name}")
 return object.__getattribute__(self, name)

hand = Hand()
print(hand.__dict__)
print(hand.__class__)
# {'thumb': 'ПаǾец', 'index_finger': 'ПȁǽаǺаǾец', ...}
# <class '__main__.Hand'>
