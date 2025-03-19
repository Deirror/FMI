# Vim Motions in VS Code

<img src="https://github.com/user-attachments/assets/d55c5e5d-8128-49ec-80fd-c40f07e1a110" width="100" height="100">

--INSERT--
-

- **Enter mode**
  - **`i`** to insert at your position
  - **`I`** to insert at the beginning of the line
  - **`a`** to append at your position
  - **`A`** to append at the end of the line
  - **`o`** to start on new line
  - **`O`** to start on previous line
  - **`s`** to delete first char and then insert on your position
  - **`S`** to empty the line and start on fresh line
    
- **Exit mode**
  - Press **`Esc`** or **`Ctrl+[`**

- **Utilities**
  - **`Ctrl+d/t`** => indentying the given line backwards/forwards
 
--REPLACE--
-

- **Enter mode**
  - Press **`Shift+r`**
    
- **Exit mode**
  - Press **`Esc`** or **`Ctrl+[`**

--NORMAL--
-

- **Enter mode**
  - **`Esc`** or **`Ctrl+[`** from other modes
  
- **Exit mode**
  - Use the mentioned keys combinations to enter other modes
    
- **Movements**
  - **`j k`** => **↓** | **↑**
  - **`h l`** => **←** | **→** 
  - **`<integer> h/j/k/l`** => moving the corresponding direction "X" times
  - **`)`** => moving to the beginning of the line
  - **`w/W`** => spacing forwards to the beginning of a word
  - **`e/E`** => spacing forwards to the end of a word
  - **`ge`** => spacing backwards to the end of a word
  - **`b/B`** => spacing backwards to the end of a word
  - **`Shift+{/}`** => spacing through paragraphs(empty lines)
  - **`Shift+(/)`** => spacing through paragraphs and their beginning
  - **`Ctrl+F/B`** => spacing half through the page respectively **↓**  | **↑**
  - **`Ctrl+D/U`** => spacing increasingly through the page, starting from *10* lines, respectively **↓**  | **↑**
  - **`Shift+$/^`** => going respectively to the end and the beginning of the current line
  - **`Shift+#/n`** => iterating through all same words on the given position
  - **`f/t+<char>`** => going to the next charachter/one character before
  - **`Shift+=`** => **↓** in the beginning of the line
  - **`_`** => **↑** in the beginning of the line
  - **`Shift+%`** => going to the beginning/end of the given block
  - **`Shift+g`** => going to the end of the file
  - **`gg`** => going to the beginning of the file

- **Editing text**
  - **Deleting**
    - **`dd`** => deleting the row
    - **`Shift+d`** => deleting everything after the given position on the row
    - **`<integer>+dd/Shift+d`** => deleting "X" rows/based on the position
    - **`cc`** => coping and deleting the row 
    - **`Shift+c`** => coping and deleting everything after the given position on the row
    - **`<integer>+cc/Shift+c`** => coping and deleting "X" rows/based on the position
    - **`x`** => removes charachter by charachter
    - **`Shift+x`** => removes charachter by charachter and moves with backwards
    - **`da/i`** => getting ready to delete a section
    - **`da/i+w`** => deleting the word, the cursor pointing to
    - **`da/i+p`** => deleting the paragraph, the cursor pointing to
    - **`ca/i`** => getting ready to copy and delete a section
    - **`ca/i+w`** => copying and deleting the word, the cursor pointing to
    - **`ca/i+p`** => copying and deleting the paragraph, the cursor pointing to
  - **Coping/Pasting**
    - **`yy/YY`** => coping the line
    - **`p`** => pasting the copied line
    - **`Shift+p`** => pasting the copied line without moving the cursor
    - **`u`** => undoing changes
  - **Additional**
    - **`Ctrl+|`** => opening new window
    - **`Ctrl+/`** => commenting a line
    - **`Shift+<<`** => indenting a line to left
    - **`Shift+>>`** => indenting a line to right
    - **`Shift+zz`** => closing a window
    - **`:w`** => saving a file
    - **`:wq`** => saving and closing a file
    - **`:qa`** => closing all windows
    - **`:q`** => closing a window

--VISUAL--
-

- **Enter mode**
  - Press **`v`**
    
- **Exit mode**
  - Press **`Esc`** or **`Ctrl+[`**

- **Marking**
  - **`a/i+{/}/(/)/p/w`** => marking the given section
