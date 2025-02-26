# Да се направят директории с имената на уникалните групи. За улеснение, имената от две думи да се напишат слято:
# Beatles, PinkFloyd, Madness

ls songs | cut -d '-' -f 1 | uniq | sed "s/ //g" | xargs -I{} mkdir -p ~/{}
