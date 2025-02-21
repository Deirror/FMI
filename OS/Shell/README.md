# Bash Cheat Sheet

![bash](https://github.com/user-attachments/assets/35331d53-3afd-4dbe-b21f-b1a400b238d8)

> [!NOTE]
> **File**, **Dir**, **Symbol Links** and etc. are considered just as a **File**, so when somewhere is written **File** it can be any of the listed

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
- **`apropos <cmd>`** => prints a lot information where this command can be used and for what purpose
- **`whatis <cmd>`** => prints general/short info for the command
- **`whereis <cmd>`** => prints the absolute path of the location of the command

Users
-

- **`whoami`** => prints your user name
- **`who`** => prints the users in your group

Paths Related
-

- **`pwd`** => prints your current dir **absolute** path
- **`ls -<char> <dir>`** => prints the content of the given dir
  - | **`-<char>`** | Description |
    |---|---|
    | **-d**| lists subdirectories names |
    | **-a** | lists all files, regardless of their type |  
    | **-i** | prints the index number of each file |
    | **-t** | sorts by time |
    | **-1** | prints on new lines |
- **`tree`** => shows dir structure   
- **`realpath <file>`** => prints the **absolute** path of the file
- **`basename <file>`** => prints only the name of the file, excluding the path to it
- **`dirname <file>`** => prints the name of the dir, in which the file is located
- **`cd <path>`** => navigates you to the given **absolute/relative** path
- **`find <path> <expr>`** => by default, prints **absolute** paths for the given dir and all files in it
  - **`<expr>`** can be *options*, *operators*, *actions* and *tests*
  - *options* are the commands **`-depth`**, **`-(min/max)depth`**
  - *operators* are from discrete math(!, not, or, and)
  - *actions* are the commands **`-delete`**, **`-print`**, **`-depth`**, **`-exec <cmd> {} \;`**
  - *tests* can be **`-mmin`**, **`-perm`**, **`-size`**, **`-path`** and a lot more 
