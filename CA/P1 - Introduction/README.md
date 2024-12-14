# Introduction

Abstraction Layers
-

- Application
- Algorithm
- Programming Language
- Operating System/Virtual Machines
- Instruction Set Architecture(ISA)
- Microarchitecture
- Gates/Register-Transfer Level(RTL)
- Circuits
- Devices
- Physics

Performance Units
-

- MIPS(Million Instructions Per Second)
- FLOPS(Floating Point Operations Per Second)

Organization of CPU
-
 <img src="https://github.com/user-attachments/assets/b7b8be43-8a10-489d-9b5b-ece38734ab3b" width="450" height="290">

ISA Demo
-

- Basically Assembly Code

| Line | Command | Variables |
| --- | --- | --- |
| 0000 | MOV | #5, R03 |
| 0006 | MOV | R03, R01|
| 0011 | MOV | #0, R04|
| 0017 | MOV | R04, R02|
| 0022 | MOV | #5, R04|
| 0028 | CMP | R04, R02|

- Then the above code transforms into machine code ->  B8 22 11 00 | AF 0C | 31 FA | ...

CISC And RISC Differences
-

- CISC -> Complex Instruction Set Computer
  - MUL 2:3 5:2 (One Line, One Instruction, Little Memory, Slow)
- RISC -> Reduced Instruction Set Computer
  - ADD R1, R2 | SUB R2, 1 | ... | ADD R5, R2 (Multiple Lines, Many Instructions, Lot Of Memory, Fast)

SIMD(Single instruction, multiple data)
-

- Parallel Processing(simultaneously)
- Instruction Set Architecture
- Vectorized Operations

Multiprocessors
-

- HPC – High Performance Computing
- HTC - High Throughput Computing
