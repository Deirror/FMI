# Намерете всички файлове в /etc, които съдържат "00" в името си и изключете директориите /etc/ssl и /etc/grub като опции 

 find /etc -type f -name "*00*" ! \( -path "/etc/ssl/*" -o -path "/etc/grub.d/*" \)

# or

 find /etc -type f -name "*00*" ! -path "/etc/ssl/*" ! -path "/etc/grub.d/*"
