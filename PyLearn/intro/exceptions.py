try:
 # бǾȁǽ
except ИǻǾǿючǹȁǼǹ, ǼǿǼ tuple ȂȆ ИǻǾǿючǹȁǼя:
 # бǾȁǽ за хващаȀе и ȁбȃабȁȅǽа Ȁа Ȁяǽȁе ȁȅ ȁȂиȄаȀиȅе изǽǾючеȀия
except ДȄȇǷȂИǻǾǿючǹȁǼǹ:
 # бǾȁǽ за хващаȀе и ȁбȃабȁȅǽа Ȁа Ȁяǽȁе ȁȅ ȁȂиȄаȀиȅе изǽǾючеȀия
except:
 # бǾȁǽ за хващаȀе и ȁбȃабȁȅǽа Ȁа ǽȁеȅȁ и да е изǽǾючеȀие(без BaseException)
else:
 # бǾȁǽ, изȂъǾȀяващ Ȅе, аǽȁ Ȁе е възȀиǽȀаǾа изǽǾючиȅеǾȀа ȄиȅȆация
finally:
 # бǾȁǽ, изȂъǾȀяващ Ȅе виȀаги

class MadWifeError(Exception):
 """Exception raised by a mad wife."""
 def __init__(self, message='ЯǸȂȅǴȁǴ ȅъȀ Ǽ ȆǼ ȅǼ ǻȁǴǹш ǻǴщȂ.'):
 self._message = message
 super().__init__(self._message)
raise MadWifeError() # MadWifeError: ЯдȁȄаȀа Ȅъǿ и ȅи Ȅи зȀаеш защȁ.
raise MadWifeError('Вǹчǹ ȁǹ Ȁǹ ȂǵǼчǴш!') # MadWifeError: Вече Ȁе ǿе ȁбичаш!


try:
 me.go_outside()
except MadWifeError:
 me.log('ДǴ ȅǹ ǻȁǴǹ - Ǹȁǹȅ ȁǹ ǵях ȃȇȅȁǴȆ ǸǴ ǼǻǿǼǻǴȀ.')
 raise


try:
 with open(src) as source_file:
 buffer = source_file.readlines()
 with open(target) as target_file:
 for line in reversed(buffer):
 target_file.write(line)
except IOError:
 print("НǹщȂ ȅǹ ȅчȇȃǼ.")
