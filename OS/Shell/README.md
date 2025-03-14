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
> **`sudo <cmd>`**(superuser do) executes **`cmd`** from the root, but must have permissions first to do so

Permissions
-

- **`chown <user>:<group> <file>`** => changes the user and the group
- **`chmod (<octal>/<perm>) <file>)`** => changes permissions
- **`umask <mask> <file>`** => removes permissions

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

> [!TIP]
> From *UNIX timestamp* to human readable conversion - **`date --date="@<seconds>"`**

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
- **`join`** => joins lines of two files on a common field
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
- **`sed (-i) 's/<to_replace>/<with>(/g) <file>'`** => With **`-i`**, modifies file's content. When using **`/g`**, then it replaces for all occurrences 

Search File
-

- **`grep -<flag> <regex> <file>`** => searches for **`<regex>`** in the file and prints the lines
  - | **`-<flag>`** | Description |
    | --- | --- |
    | **`-n`** | prints the numbers of the lines which contains the string |
    | **`-(A/B/C) <number>`** | prints the line itself and the previous/next/previous and next **`<number>`** line |
    | **`-i`** | ignores case(doesn't matter if upper or lower case) |
    | **`-v`** | prints all lines which don't contain the string |
    | **`-r`** | searches files, which contain the string, *recursively* |
    | **`-F`** | search for the **`<regex>`**, but it is treated as a plain string here |
    | **`-q`** | prevents result text from rendering onto the shell screen |

> [!TIP]
> If you want to remove these damn .(files/dirs) when searching in your ~ -> Just type this **`find ~/ | grep -v "/\.[.]*"`**

Compress/Archive File
-

### Archiving
- **`tar -<opt> -f <tarname>.tar <files>`** => (un)archives all files under the archive name **`<tarname>`**
  - | **`-<opt>`** | Description |
    | --- | --- |
    | **`-c`** | archives the files |
    | **`-x`** | unarchives the .tar |
- **`tar -cf <tarname>.tar <dir>`** => archives the whole dir and subcontent of the dir
- **`tar -tvf <tarname>.tar`** => lists the content of the archive

### Compressing
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

Regex
-

### Anchors
- **`$`** => means *end of line*
- **`^`** => means *beginning of line*
- **`\>`** => means *end of word*
- **`\<`** => means *beginning of word*

### Classes
- **`[<chars>]`** => matches one of the characters 
- **`[(^)<char1>-<char2>]`** => matches one of between the interval characters. When **`^`** is used, then it opposites the regex
- **`[:<opt>:]`** => matches special predefined intervals of characters
- **`(<atom1>|<atom2>|...)`** => matches one of the following atoms

### Quantifiers

- **`<atom>(*/+/?)`** => you can recall these easily from discrete math
- **`<atom>.{<start>,<end>}`** => how many occurrences are allowed for search

Arithmetic
-

- **`expr <expression>`** => calculates expression with integers
- **`bc`** => works well with **`echo "<expr>"`**. Accepts floats!
- **`((<varname>=<expr>))`** => calculates the fastest and saves result to **var**, but works only with integers
- **`seq <start> <end>`** => prints the numbers in the interval

Awk Scripting
-

> [!NOTE]
> Structure of awk script - **`'BEGIN{init_code} {main_code} END{final_code}'`**
> 
> If and For statements work like in a normal programming language

### Special varibles

- **`$<N>`** => specifies concrete column to be used
- **`NF`** => how many colums the row has
- **`NR`** => how many rows have been read so far
- **`awk -<flag> <scirpt>`** => runs the script in the programming language *awk*
  - | **`-<flag>`** | Description |
    | --- | --- |
    | **`-f`** | reads from file and scripts |
    | **`-F '<sep>'`** | allows to specify a separator |
    | **`-v <var>=<some_export_name>`** | allows us to include global variables |

> [!IMPORTANT]
> *Awk* allows regex by typing **`~`** before the regex itself
> 
> Commands can be run inside *awk* script - **`{... cmd="<cmd>"; cmd | getline <result> | close(cmd) ...}`**

Disk Usage
-

- **`df -<opt> <file>`** => shows usage of disk of the file
- **`du -<opt> <file>`** => same as **`df`**, but redners *recursevily*

> [!NOTE]
> For more info about **`-<opt>`**, type **`man (df|du)`** as the documentation is pretty well structured for these commands

Processes
-

- **`ps -<opt>`** => shows information for a given process
  - | **`-<opt>`** | Description |
    | --- | --- |
    | **`-e(f)`** | shows information for all processes. With *f*, much more information is rendered |
    | **`-u <user>`** | shows information for all processes based on the user |
    | **`-o <args>`** | shows specific information, based on **`<args>`**, for a given process |
- **`pstree`** => tree version of **`ps`**   
- **`top`** => same as **`ps`**, but more interactive

Signals
-

- **`kill -<signal> <PID>`** => changes behaviour/state of a process, based on the signal
- **`killall -<signal> <name>`** => changes behaviour/state of all processes with the same name, based on the signal

Jobs
-

- **`jobs`** => shows all processes of the current session
- **`(fg|bg) <jid>`** => starts the *foreground*|*background* process

Scripts
-

> [!IMPORTANT]
> I will use mostly the following ***Shebang*** - **`#!/bin/bash`** 

> [!NOTE]
> Use **`#`** for commenting a line, this implies also for ***Shebangs***

### Running Scripts

- **`<path> <args>...`** => to run a script with ***Shebang***, type the path to the script as a separate process
- **`<interpreter> <path>`** => runs a script based on the **`interpreter`**
- **`(.|source) <path>`** => as **`<path>`**, but runs the script in the current session

### Variables

> [!NOTE]
> There are 3 types of **vars** - **local**(shell func), **global**(shell script) and **env**(based on shell user, like $PATH, $HOME and etc.)

#### Defining

- **`(un)alias <name>=<cmd>`** => works like **#define** in C. Use *un* to unset the **`alias`**

#### Viewing

- **`set`** => shows all **variables**
- **`env`** => shows all **environment variables**

#### Creating

- **`export <name>=<string>...`** => creates **env vars** only for the current shell session
- **`env <name>=<string>...`** => creates **env vars** only for the current running command
- **`local <name>=<string>...`** => creates **vars** in the scope of a shell function
- **`<name>=<string>`** => creates a global **var** in the scope of a scirpt itself

#### Accessing

- **`${<varname>}`** => refers to the content of the **var**
  - | **`${<shrtcut>}`** | Description |
    | --- | --- |
    | **`${0}`** | returns the path to the script |
    | **`${#}`** | returns the count of the parameters |
    | **`${N}`** | returns the N-th argument, where N is natural |
    | **`${@/*}`** | returns all func arguments in the format - **`"${1}" "${2}" ... / "${1} ${2} ..."`** |
    | **`${?}`** | returns the exit status of the last run command |
    | **`${!}`** | returns the **PID** of the last run process |

#### Reading

> [!NOTE]
> **`IFS`** is the separator between the arguments in the **`read`** command

- **`read -<flag> <varnames>`** => reads from stdin user's input
  - | **`-<flag>`** | Description |
    | --- | --- |
    | **`-p`**| prints the *promt* and then asks for input |
    | **`-d`**| changes the stop char for reading(default one is **'\n'**) |
- **`IFS=<str>`** => sets **`IFS`** to new separator

### Exit Behaviour

- **`set -<flag>`** => changes the treatment of the conditions of the executed series of command whether they failed or succeeded
  - | **`-<flag>`** | Description |
    | --- | --- |
    | **`-o pipefail`**| exits with fail status even if just one command fails |
    | **`-e`**| exits immediately after a command fails |
    | **`-u`**| exits if a command doesn't exist |

> [!TIP]
> Good practice to add **`set-euo pipefail`** in the beginning of each shell script

### Waiting  

- **`wait <PID>`** => waits for the process to end

### Subshells

- **`{ cmd1; cmd2;... }`** => runs the commands in the **current** shell session
- **`( cmd1; cmd2; ... )`** => runs the commands in a **new** shell session
- **`bash -c <cmds>`** => same as **`(...)`**

### Process Substitution

- **`<|>( cmd1; cmd2; ...)`** => creates a *virtual* file, executes the commands and returns the name of the file to *stdin*|*stdout*

> [!IMPORTANT]
> **`|`**(or just a pipe) runs the commands in a subshell. On the other hand, **`< <(<cmds>)`** simulates a pipe but runs the commands in the current shell 

### Expressions

| **`<expr>`** | Description |
| --- | --- |
| **`!<cmd>`** | **NOT** |
| **`<cmd1> \|\| <cmd2>`** | **OR** |
| **`<cmd1> && <cmd2>`** | **AND** |

### Tests

- **`[[ -<flag> <expr> ]]`** => evaluates the expression
  - | **`-<flag> <expr>`**| Description |
    | --- | --- |
    | "numbers" | (-eq, -gt, -lt, -le, -ge) |
    | "strings/cmd output" | (==, <(=), >(=), !=) |
    | **`-(n\|z) <str>`**| checks if string is non-empty/empty |
    | **`-(f\|d) <str>`**| checks if a file/dir exists |
    | **`-(r\|w) <file>`**| checks if we can read/write |

### Constructions and Syntax

> [!IMPORTANT]
> To separate commands, by default, we can use **\n**, but in shell scripts we can also use **;**

| Construction | Syntax | 
| --- | --- |
| *if* | **`if <cmd>; then <block> else <block> fi`** |
| *case* | **`case <str> in <glob1>) <block>;; <glob2>) <block>;; ... esac`**, **`*)`** => defualt |
| *for* | **`for <var> in <args>; do <block>; done`** |
| *while* | **`while <cmd>; do <block>; done`** |
| *func* | **`function <name> { <cmds> }`** |
