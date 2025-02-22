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
- **`whereis <cmd>`** => prints the absolute path of the location of the command

Users
-

- **`whoami`** => prints your user name
- **`who`** => prints the users in your group

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
> Use **`rm`**, **`mv`**, **`cp`** with the flag **`-i`** if you want to be asked before deleting each file one by one

Globbing
-

- | Spec Shell Symbols | Description |
  | --- | --- |
  | **`?`** | corresponds to one random chararchter |
  | **`*`** | corresponds to many random chararchter|
  | **`[...]`**| corresponds to to a set of charachters |
  | **`{<args>}`**| does the command for each *args* |

> [!IMPORTANT]
> When these globbing symbols are in **`''\""`** they are just stringified, also called **escaping**

- **`\`** => can be used for making commands on new lines 

Read File
-

- Todo

Write File
-

- Todo

Serach Text
-

- grep ... Todo

