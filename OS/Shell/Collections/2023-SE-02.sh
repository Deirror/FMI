# Напишете серия от команди, намираща общия брой на срещанията на думата error във всички log файлове

find /var/log/my_log -type f -regex "./[a-zA-Z0-9_]+_[0-9]+\.log" | xargs -r -I{} cat {} | tr ' ' '\n' \
| sort | uniq -ic | grep "error" | cut -d ' ' -f 1
