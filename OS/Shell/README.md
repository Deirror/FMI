# Bash Cheat Sheet

![bash](https://github.com/user-attachments/assets/35331d53-3afd-4dbe-b21f-b1a400b238d8)

> [!NOTE]
> **File**, **Dir**, **Symbol Link**, **Path** and etc. are considered just as a **File**, so when somewhere is written **File** it can be any of the listed

Navigation in Bash CLI
-

- **`↓ | ↑`** => iterates through command history
-  **`CTRL+R`** => searches in command history by typing charachter by charachter
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

-  Todo

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
- **`rm -<flag> <place_path>`** => deletes a files
  - **`-<flag>`** can be **`-r`**, stands for *recursively*

> [!Warning]
> Use **`rm`**, **`mv`**, **`cp`** with the flag **`-i`** if you want to be asked before doing the chosen operation on each file one by one

Globbing
-

| Spec Shell Symbols | Description |
| --- | --- |
| **`?`** | corresponds to one random chararchter |
| **`*`** | corresponds to many random chararchter|
| **`[...]`**| corresponds to a set of charachters |
| **`{<args>}`**| does the command for each *args* |

> [!IMPORTANT]
> When these globbing symbols are in **`''\""`** they are just stringified, also called **escaping**

**`\`** => can be used for making commands on new lines 

Date
-

- **`date <flag><format>`** => prints current time in the given format and based on the flag, simply said, the date's padding is different
- **`date +'%s'`** => prints UNIX timestamp

> [!NOTE]
> Not quite sure if useful, but *UNIX timestamp* is just how many seconds have passed since 1970-01-01 00:00 UTC 

Stats
-

- **`stat -<format> <file>`** => prints all info for the file like size, blocks, type, inode, access, last time modified/accessed/change, birthdate
  -  | **`-<format>`**| Description |
     | --- | --- |
     | **`-c '%s'`**| prints the size(bytes) of the file |
     | **`-c '%U'`**| prints the owner of the file |
     | **`-c '%Y'`**| prints the last time modification of the file |
- **`ls -l <file>`** => prints only the access info, owner name, birthdate

Read File
-

- **`cat <opt> <file>`** => renders the content of the file
- **`head -n <N> <file>`** => if number is negative, then it doesn't render only the last abs(N) lines, else, renders the first N lines
- **`tail -n <N> <file>`** => same as **`head`**, but reverse, starts from the end
- **`less <file>`** => opens **`man`**, but renders the content itself
- **`xxd <file>`** => renders the content in hex code
- **`od -c <file>`** => renders ASCII content of the file 

Write File
-

- **`echo <text> (>/>>) <file>`** => disconnects and connects *stdout* to the file to append to/overwrite file
- **`echo <text> >> <file>`** => disconnects and connects *stdout* to the file to append to file
- **`printf <text> > <file>`** => same as **`echo >`**, but with formatted text
- **`cat (>/>>) <file>`** => you start writing text to the file and use **`CTRL+D`** to exit and save
- **`ls <path> (>/>>) <file>`** => overwrites **`<path>`** to the file
- **`exec > <file>`** => disconnects and connects *stdout* to the file for all running scripts, instead of the terminal screen itself

