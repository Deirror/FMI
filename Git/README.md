# Learn Git

<img src="https://github.com/user-attachments/assets/77027bd7-c948-4a58-84c4-4f7460d984fa" width=220 height=100/>

> [!NOTE]
> Here are explained most used commands in **git** and some unique concepts
>
> Most of the commands here will be high-level - **`Porcelain`**, as they are more widely used then the low-level ones - **`Plumbing`**
>  

> [!IMPORTANT]
> The syntax of the commands is **`command <required> [optional]`**

# Configurations

- **Git** has to know your information (name, email and etc.) so that it can track your changes

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

- **`git commit <flags> <message>`** => saves the state of the repository, snapshot of the repository at a given point in time

Git Logs
-

- **`git log <flags>`** => shows a history of the commits in a repository
- It is useful for
  - Who made a commit
  - When the commit was made
  - What was changed 
