#CONVETION -> UPPER CASE NAMES
MAX_SIZE = 1e6
ID = 1
#...and so on
ID = 2 # But you can do this!


from typing import Final

VERSION: Final[str] = '1.0.12'
VERSION = '0' # Compile Error! Cannot modify variable


from collections import namedtuple

Constants = namedtuple('Constants', ['SIZE', 'MAX_LIMIT'])
const = Constants(SIZE=10, MAX_LIMIT=100)
print(const.SIZE)  # 10


from dataclasses import dataclass

@dataclass(frozen=True)
class Constants:
    SIZE: int = 10
    MAX_LIMIT: int = 100

const = Constants()
print(const.SIZE)  # 10
# const.SIZE = 20  -> This would raise a FrozenInstanceError

#third-party library
from const import const

const.SIZE = 10
# const.SIZE = 20  # This raises an error
