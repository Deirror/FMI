# Bash Cheat Sheet

![bash](https://github.com/user-attachments/assets/35331d53-3afd-4dbe-b21f-b1a400b238d8)

> [!NOTE]
> **File**, **Dir**, **Symbol Link**, **Path** and etc. are considered just as a **File**, so when somewhere is written **File** it can be any of the listed

Navigation in Bash CLI
-

- **`↓ | ↑`** => iterates through command history
-  **`CTRL+R`** => searches in command history by typing character by character
-  **`TAB`** => autocompletes a command
-  **`CTRL+C`** => kills the current running process

> [!IMPORTANT]
> There are also other combo keys when you enter modes like **`man`**, **`vim`**, **`less`** and other, *Vim* motions - [checkout](https://github.com/Deirror/FMI/tree/main/OS/Vim) this for more

Clean Terminal Screen
-

- **`clear`** => clears the ternimal's screen
- **`reset`** => **`clear`** + resets command history

Help Commands
-

- **`man <theme> <cmd>`** => based on **`<theme>`**,which is just a number, opens a new window with useful info like **`help`** in *Windows*, where you can use *Vim* motions for navigation
- **`<cmd> -h/--help`** => prints *help* for the given command
- **`apropos <cmd>`** => prints a lot of information where this command can be used and for what purpose
- **`whatis <cmd>`** => prints general/short info for the command
- **`whereis <cmd>`** => prints the **absolute** path of the location of the command

> [!TIP]
> If you just want to briefly understand what the command does, use **`whatis`**. For more info like **`-flags`** or best practices, use **`man`** as it uses *Vim* motions and it's convenient to search text or navigate

Users
-

- **`whoami`** => prints your user name
- **`who`** => prints the users in your group
- **`id -(u/g) <username>`** => prints the id of the user/group

> [!NOTE]
> All info for the users is stored in **`/etc/passwd`**

> [!WARNING]
> **`sudo <cmd>`** executes **`cmd`** from the root, but must have permissions first to do so

Permissions
-

- **`chown <user>:<group> <file>`** => changes the user and the group
- **`chmod (<octal>/<perm>) <file>)`** => changes permissions
- **`unmask <mask> <file>`** => removes permissions

<img src="https://github.com/user-attachments/assets/9b309f4f-ea04-48fd-b42c-0e29e7cb6b97" width=150 height=140/>

Paths Related Commands
-

- **`pwd`** => prints your current dir **absolute** path
- **`ls -<char> <dir>`** => prints the content of the given dir
  - | **`-<char>`** | Description |
    | --- | --- |
    | **-d**| lists subdirectories names |
    | **-a** | lists all files, regardless of their type |  
    | **-i** | prints the index number of each file |
    | **-t** | sorts by time |
    | **-l** | shows info as permissions, time of creation |
    | **-1** | prints on new lines |
- **`tree`** => shows dir structure   
- **`realpath <path>`** => prints the **absolute** path of the file
- **`basename <path>`** => prints only the name of the file, excluding the path to it
- **`dirname <path>`** => prints the name of the dir, in which the file is located
- **`readlink <path>`** => dereferences a path
- **`cd <path>`** => navigates you to the given **absolute/relative** path
- **`find <path> <expr>`** => by default, prints **absolute** paths for the given dir and all files in it
  - **`<expr>`** can be *options*, *operators*, *actions* and *tests*
  - *options* are the commands **`-depth`**, **`-(min/max)depth`**
  - *operators* are from discrete math(!, not, or, and)
  - *actions* are the commands **`-delete`**, **`-print`**, **`-depth`**, **`-exec <cmd> {} \;`**, **`-type f/d/l`**, **`-name <filename>`**
  - *tests* can be **`-mmin`**, **`-perm`**, **`-size`**, **`-path`** and a lot more

Path Extentions
-

| Pattern | Desription |
| --- | --- |
| **`/dir`** | **Absolute** path |
| **`.`** | **Relative** path |
| **`..`** | One dir back |
| **`-`** | Previous visited dir |
| **`~`** | Home dir |

File Manip
-

- **`touch <path>`** => creates an empty file
- **`mkdir -<flag> <path>`** => creates an empty dir
  - | **`-<flag>`** | Desription |
    | --- | --- |
    | **`-m`** | sets permissions |
    | **`-p`** | creates all parent dirs if not existing |
    | **`-v`** | prints a message for each created dir |
- **`cp <path> <place_path>`** => copies a file and places it in the given dir
- **`mv <path> <move_path>`** => moves a file and places it in the given dir
- **`rmdir <place_path>`** => deletes an epmty dir
- **`rm -<flag> <place_path>`** => deletes a file
  - **`-<flag>`** can be **`-r`**, stands for *recursively*

> [!Warning]
> Use **`rm`**, **`mv`**, **`cp`** with the flag **`-i`** if you want to be asked before doing the chosen operation on each file one by one

Globbing
-

| Spec Shell Symbols | Description |
| --- | --- |
| **`?`** | corresponds to one random character |
| **`*`** | corresponds to many random characters |
| **`[...]`**| corresponds to a set of characters |
| **`{<args>}`**| does the command for each *args* |

> [!IMPORTANT]
> When these globbing symbols are in **`''\""`** they are just stringified, also called **escaping**

**`\`** => can be used for making commands on new lines 

Date
-

- **`date <flag><format>`** => prints current time in the given format and based on the flag, simply said, the date's padding is different
- **`date +'%s'`** => prints UNIX timestamp

> [!NOTE]
> *UNIX timestamp* is just how many seconds have passed since 1970-01-01 00:00 UTC 

Stats
-

- **`stat -<format> <file>`** => prints all info for the file like size, blocks, type, inode, access, last time modified/accessed/change, birthdate
  -  | **`-<format>`**| Description |
     | --- | --- |
     | **`-c '%s'`**| prints the size(bytes) of the file |
     | **`-c '%U'`**| prints the owner of the file |
     | **`-c '%Y'`**| prints the last time modification of the file |
- **`ls -l <file>`** => prints only the access info, owner name, birthdate
- **`wc -<opt> <file>`** => prints newline, word, and byte counts for the given file
  - | **`-<opt>`**| Description |
    | --- | --- |
    | **`-l`** | prints the count of the rows in the file |
    | **`-c`** | prints the number of bytes of the file |
    | **`-m`** | prints the characters of the file |
    | **`-w`** | prints the count of the words in the file | 

Read File
-

- **`cat -<opt> <file>`** => renders the content of the file
  - | **`-<opt>`** | Description |
    | --- | --- |
    | **`-n`** | adds numbers at the start of each line |
    | **`-e`** | adds **`$`** at thе end of each line |
- **`paste -<space> <files>`** => renders the files' contents in parallel
- **`tr -<flag> <to_replace> <with>`** => reads form *stdin* and replaces in text with the given format
- **`cut -<flag>`** => as the name suggests, cuts part of file and renders to the terminal screen
- **`sort -<flag>`** => sorts the content by a given **`-<flag>`**
  - | **`-<flag>`** | Description |
    | --- | --- |
    | **`-r`** | sorts the lines alphabetically and reverses |
    | **`-n`** | sorts the lines by the numbers at the start of each line |
    | **`-k <args>`** | sorts by columns, **`<args>`** are numbers of the columns |
    | **`-t <args>`** | sets separator(useful for csv files) |
- **`uniq -<flag>`** => renders only unique rows
  - | **`-<flag>`** | Description |
    | --- | --- |
    |**`-c`** | prints the occurence of each row and the row itself |
    |**`-d`** | prints only the duplicate rows |
- **`comm -<opt> <file1> <file2>`** => compares two sorted files line by line. **`-<opt>`** can be **`-1`**, **`-2`** or **`-3`**, meaning that you can exlucde the columns  
- **`head -n <N> <file>`** => if number is negative, then it doesn't render only the last abs(N) lines, else, renders the first N lines
- **`tail -n <N> <file>`** => same as **`head`**, but reverse, starts from the end
- **`less <file>`** => opens **`man`**-like, but renders the content itself
- **`xxd <file>`** => renders the content in hex code
- **`od -c <file>`** => renders ASCII content of the file 

Write File
-

- **`echo <text> (>/>>) <file>`** => disconnects and connects *stdout* to the file to append to/overwrite file
- **`printf <text> > <file>`** => same as **`echo >`**, but with formatted text
- **`cat (>/>>) <file>`** => you start writing text to the file and use **`CTRL+D`** to exit and save
- **`ls <path> (>/>>) <file>`** => overwrites **`<path>`** to the file
- **`exec > <file>`** => disconnects and connects *stdout* to the file for all running scripts, instead of the terminal screen itself

Compress/Archive File
-

- **`tar -<opt> -f <tarname>.tar <files>`** => (un)archives all files under the archive name **`<tarname>`**
  - | **`-<opt>`** | Description |
    | --- | --- |
    | **`-c`** | archives the files |
    | **`-x`** | unarchives the .tar |
- **`tar -cf <tarname>.tar <dir>`** => archives the whole dir and subcontent of the dir
- **`tar -tvf <tarname>.tar`** => lists the content of the archive
- **`(gzip/xz) -<opt> <file>`** => compresses the file
  - | **`-<opt>`** | Description |
    | --- | --- |
    | **`-k`** | keeps the original file |
    | **`-d`** | decompresses the .tar |
    | **`-l`** | shows compressed file info |
- **`tar -<compr> -<opt> <tarname>.tar.<compr> <dir>`** => compresses and archives the dir
- **`tar -caf <tarname>.tar.<compr> <dir>`** => compresses and archives the whole dir and subcontent of the dir
- **`tar -xf <tarname>.tar.<compr>`** => unarchives and decompresses the archive

File Descriptor
-

| File Descriptor | Description |
| --- | --- |
| 0> | refers to *stdin* |
| 1> | refers to *stdout* |
| 2> | refers to *stderr* |
| &> | refers to *stdout* and *stderr* |

> [!IMPORTANT]
> **`2>/dev/null`** is used to suppress errors like "*permission denied*"

> [!TIP]
> To see the exit code of your last executed command, type **`echo $?`**, **`?`** is a special variable
