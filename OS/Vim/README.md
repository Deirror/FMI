# Vim Motions in VS Code

--INSERT--
-

- Enter mode
  - **`i`** to insert at your position
  - **`I`** to insert at the beginning of the line
  - **`a`** to append at your position
  - **`A`** to append at the end of the line
  - **`o`** to start on new line
  - **`O`** to start on previous line
  - **`s`** to delete first char and then insert on your position
  - **`S`** to empty the line and start on fresh line
- Exit mode
  - Press **`Esc`** or **`Ctrl+[`**

---

- Utilities
  - **`Ctrl+d/t`** => indentying the given line backwards/forwards

--NORMAL--
-

- Enter mode
  - **`Esc`** or **`Ctrl+[`** from other modes
- Exit mode
  - Use the mentioned keys combinations to enter other modes

---

- Movements
  - **`j k`** => **↓** | **↑**
  - **`h l`** => **←** | **→** 
  - **`<integer> h/j/k/l`** => moving the corresponding direction "X" times
  - **`)`** => moving to the beginning og the line
  - **`w/W`** => spacing forwards to the beginning of a word
  - **`e/E`** => spacing forwards to the end of a word
  - **`b/B`** => spacing backwards to the end of a word
  - **`Shift+{/}`** => spacing through paragraphs(empty lines)
  - **`Shift+(/)`** => spacing through paragraphs and their beginning
  - **`Ctrl+F/B`** => spacing half through the page respectively **↓**  | **↑**
  - **`Ctrl+D/U`** => spacing increasingly through the page, starting from *10* lines, respectively **↓**  | **↑**
  - **`Shift+$/^`** => going respectively to the end and the beginning of the current line
  - **`Shift+#/n`** => iterating through all same words on the given position
  - **`f/t+<char>`** => going to the next charachter/one character before
  - **`Shift+g`** => going to the end of the file
  - **`gg`** => going to the beginning of the file

---

- Editing text
  - Deleting
    - **`dd`** => deleting the row
    - **`Shift+d`** => deleting everything after the given position on the row
    - **`<integer>+dd/Shift+d`** => deleting "X" rows/based on the position
    - **`cc`** => copying and deleting the row 
    - **`Shift+c`** => copying and deleting everything after the given position on the row
    - **`<integer>+cc/Shift+c`** => copying and deleting "X" rows/based on the position
