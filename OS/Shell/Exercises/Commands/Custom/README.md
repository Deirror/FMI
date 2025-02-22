# Custom Task

Description
-

Here are stored some custom tasks designed and made by me, ***Deirror***

Description of the tasks will be written in Bulgarian, as they are intended for ***FMI*** students

Tasks
-

- Task 1
  - Намерете всички файлове в /etc, които съдържат "00" в името си и изключете директориите /etc/ssl и /etc/grub като опции
<details>
  <summary>Click to reveal</summary>
  
  ```bash
  find /etc -type f -name "*00*" ! \( -path "/etc/ssl/*" -o -path "/etc/grub.d/*" \)

  # or

  find /etc -type f -name "*00*" ! -path "/etc/ssl/*" ! -path "/etc/grub.d/*"
  ```
</details>
