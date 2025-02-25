# Във file2 (inplace) подменете всички малки букви с главни

 sed -i "s/[[:lower:]]/\U&/g" ~/dir5/file2
