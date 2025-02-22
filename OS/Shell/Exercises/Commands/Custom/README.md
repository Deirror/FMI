# Custom Task

Description
-

Here are stored some custom tasks designed and made by me, ***Deirror***

Description of the tasks will be written in Bulgarian, as they are intended for ***FMI*** students

Tasks
-

### ❓ Намерете всички файлове в /etc, които съдържат "00" в името си и изключете директориите /etc/ssl и /etc/grub като опции

<details>
  <summary>Click to reveal</summary>

  ```bash
  #тук използваме escaping, за да използваме математическа логика
  find /etc -type f -name "*00*" ! \( -path "/etc/ssl/*" -o -path "/etc/grub.d/*" \) 

  # или

  # тук просто изреждаме и по default се добавя неявно -a(AND) между всички изредени израз
  find /etc -type f -name "*00*" ! -path "/etc/ssl/*" ! -path "/etc/grub.d/*"
  ```
</details>
