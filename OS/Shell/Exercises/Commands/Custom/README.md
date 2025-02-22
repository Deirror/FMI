# Custom Task

Description
-

Here are stored some custom tasks designed and made by me, ***Deirror***

Task
-

<details>
  <p></p>
  <summary>Click to reveal</summary>

  ```bash
  find /etc -type f -name "*00*" ! \( -path "/etc/ssl/*" -o -path "/etc/grub.d/*" \)

  # or

  find /etc -type f -name "*00*" ! -path "/etc/ssl/*" ! -path "/etc/grub.d/*"
  ```

</details>
