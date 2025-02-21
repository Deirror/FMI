# Bash Cheat Sheet

![bash](https://github.com/user-attachments/assets/35331d53-3afd-4dbe-b21f-b1a400b238d8)

Navigation in Bash CLI
-

- **`↓ | ↑`** => iterates through command history
-  **`CTRL+R`** => searches in command history by typing charachter by charachter
-  **`TAB`** => autocompletes a command
-  **`CTRL+C`** => kills the current running process

Clean Terminal Screen
-

- **`clear`** => clears the ternimal's screen
- **`reset`** => **`clear`** and resets command history

Help Commands
-

- **`man <theme> <cmd>`** => based on **`<theme>`**,which is just a number, opens a new window with useful info like **`help`** in *Windows*, where you can use *Vim* motions for navigation
- **`<cmd> -h/--help`** => prints *help* for the given command
- **`apropos <cmd>`** => prints a lot information where this command can be used and for what purpose
- **`whatis <cmd>`** => prints general/short info for the command
- **`whereis <cmd>`** => prints the absolute path of the location of the command

Users
-

- Todo

Paths Related
-

- **`ls -<char> <dir>`** => prints the content of the given dir
  - | **`-<char>`** | Description |
    |---|---|
    | **-d**| lists subdirectories names |
    | **-a** | lists all files, regardless of their type |  
    | **-i** | prints the index number of each file |
    | **-t** | sorts by time |
    | **-1** | prints on new lines |
-  **`realpath <file>`** => prints the **absolute** path of the file
-  **``** =>
-  **``** =>
