# Learn Git

<img src="https://github.com/user-attachments/assets/77027bd7-c948-4a58-84c4-4f7460d984fa" width=220 height=100/>

> [!NOTE]
> Here are explained most used commands in **git** and some unique concepts
>
> Most of the commands here will be high-level - **`Porcelain`**, as they are more widely used then the low-level ones - **`Plumbing`**
>  

> [!IMPORTANT]
> The syntax of the commands is **`command <required> [optional]`**

Configurations
-

- **Git** has to know your information (name, email and etc.) so that it can track your changes

- **`git config <cmd> <vartype>`** => starts working with **`.git/config`**
- | **`<cmd>`** | Description |
  | --- | --- |
  | **`--add <vartype> <section>.<keyname> <str>`** | adds a **`vartype`** var |
  | **`--unset(-all) <section>.<keyname>`** | removes variable(s) based on the **`<keyname>`** |
  | **`--remove-section <section>`** | removes a section |  
  | **`--list --<vartype>`** | shows all **`vartype`** vars |
  | **`--get <key>`** | shows the var's value based on the **`<key>`** |

- **`<vartype>`** => can be **`--local`** or **`--gloabl`**

> [!NOTE]
> **`~/.gitconfig`** stores your *global* configurations

> [!WARNING]
> The *hidden* directory **`.git`** stores absolutely all the information for the project

Repos
-

- Simply said, *repo* is just a **SINGLE** project. One **`git init`** per one project
- **`git init`** => initializes an empty project/repo

Status
-

| State | Description |
| --- | --- |
| **`untracked`** | Not being tracked by Git. If you delete an *untracked* file, you lose it forever |
| **`staged`** | Marked for inclusion in the next commit |
| **`committed`** | Saved to the repository's history |

- **`git status`** => shows you the current state of your repo

Staging
-

- **`git add <path-to-file | pattern>`** => sets an index to the file (getting ready the file for saving the current state in history - *staging*). It is used before committing it

Commits
-

- **`git commit <flags> <message>`** => saves the state of the repository, a snapshot of the repository at a given point in time

- In order to optimize **git**
  - compresses and packs files to store them more efficiently
  - deduplicates files that are the same across different commits. If a file doesn't change between commits, **Git** will only store it once  

Logs
-

- **`git log <flags>`** => shows a history of the commits in a repository
- | **`<flag>`** | Description |
  | --- | --- |
  | **`--oneline`** | shows super brief info of the commits (Most used flag) |
  | **`--decorate <type>`** | renders much nicer outlook. **`<type>`** can be *full*, *short* or *no* |
  | **`--graph`** | shows a graph of the tree commits |
  
- It is useful, when you want to know
  - who made a commit
  - when the commit was made
  - what was changed

- *commit hash* => represents a unique identifier for each commit. Only the first 7 characters of the hash are important

> [!NOTE]
> **Git** uses *SHA-1* for hashing commits

- **`git cat-file -p <hash>`** => allows to see the contents of a commit without needing to search in **`.git/objects`** to manually read a file

- **`tree`** => git's way of storing a directory
- **`blob`** => git's way of storing a file

- **`git diff <state>`** => shows the new and the old content, highlighting the differences

Branches
-

- A *branch* is just a named lightweight pointer to a specific commit

- **`git branch`** => shows your current branch
- **`git branch <name>`** => creates a new branch
- **`git branch -m <oldname> <newname>`** => renames the branch's name
- **`git branch -d <name>`** => deletes a branch
- **`git switch -c <name>`** => switches to the branch and if nonexistant, creates a new branch

Merges
-

> [!WARNING]
> Conflicts in **git** - lines which have been modified twice in two different commits which are from two different branches 

- **`git merge <subbranch>`** => merges the the branches into one branch, but with applied changes
- **`git rebase <branch>`** => moves the merge base of the subbranch to the merge tip

Reset
-

- **`git reset --soft <COMMITHASH>`** => undoes the last commit(s) or any changes in the index (staged but not committed changes) and the worktree (unstaged and not committed changes)
- **`git reset --hard <COMMITHASH>`** => goes back to a previous commit and discard all the changes

# Github

Remote
-

- **`git remote add <name> <uri>`** => creates another *repo* ( a reference to a *repo* that is hosted on another location)
- **`git fetch`** => downloads copies of all the contents of the .git/objects directory (and other book-keeping information) from the remote repository into your current one
- **`git log <remote>/<branch>`** => shows the commits from the repo **`<remote>`**
- **`git merge <remote>/<branch>`** => merges the commits from the repo **`<remote>`** to your current branch

Push/Pull
-

- **`git push <localbranch>:<remotebranch>`** => sends local changes to any "remote"
- **`git pull [<remote>/<branch>]`** => gets the actual file changes from a remote repo, not just the metadata

Fork
-

- It is a copy of a *repo*
