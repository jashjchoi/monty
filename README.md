## monty C - Stacks, Queues - LIFO, FIFO

### Learning objectives
- What do LIFO and FIFO mean 
- What is a stack, and when to use it 
- What is a queue, and when to use it 
- What are the common implementations of stacks and queues 
- What are the most common use cases of stacks and queues 
- What is the proper way to use global variables

### Description

| File              | Description                                                                                                             |
|-------------------|-------------------------------------------------------------------------------------------------------------------------|
| bytecodes         | contains test files                                                                                                     |  
| `monty.c`         | the main function                                                                                                       |
| `execute_monty.c` | includes functions to split the input command into tokens and check if the input command is the one of builtin opcodes. |
| `monty.h`         | contains the list of prototypes, libraries and variables.                                                               |
| `helper_func.c`   | handles functionality of freeing the global variables and checking the command is a digit number.                       |
| `opcode_func.c`   | contains opcode functions. Implement of `push` , `pall`,  `pint`, `pop`, and `swap`                                     |
| `math_func.c`     | contains calculation functions: `add` , `sub`, `mul`, `div`,  and implement the `nop`                                   |
