# rmcli
rmcli  is a register machine simulator for the commandline, written in C++. For now, it
has a basic featureset and can process instructions in two different modes,
`interactive` and `fileinput`.

## Installation
[insert install instructions later]

## Usage
To use it, simply run `rmcli` in the terminal, with either the `-f` or the `-i` option,
depending on which mode you want to choose. Running the program without arguments will
print a help menu instead.

### Modes
Processing instructions can be done in two different ways, depending on what the user
intends to achieve.

If it is desired to process an entire file at once, one can use the **file input mode**:
```
rmcli --file <path>
```
Hereby, the file should be a plain text one, and include only one instruction per line.
Writing anything on the line after the instruction is safe, as the program ignores any
input beyond the expected register machine functions. Leaving empty lines for clarity is
also possible, although discouraged (line will be considered by the internal counter).
Therefore, a correct file should look something like this:
```
DLOAD 5
STORE 1 // text can safely be put here (slashes not necesary)
MUL 1
END
```
If an instruction which normally expects an argument is called without one, a placeholder
in the form of `0` will be used instead.
After the file has been processed, a table showing the accumulator and the first ten 
registers including their values will be printed to the terminal. If a register has not
been set to a value, it will instead show `undefined`.

If the user instead wants a sandbox-like environment, **interactive mode** can be used:
```
rmcli -i
```
Upon executing this command, the user can interface with the program by simply entering
register machine instructions, which get evaluated one at a time. Therefore, any 
instruction utilizing the line counter like `JMP`, `JEQ`, etc. will still be accepted, 
but won't have any effect. If the user wishes to reset the register machine, `END` can be
executed, which will print the register table like in file input mode, and revent the
machines state to its default.

To exit, one can simply type `exit`, `quit` or press `CTRL-D`.

### Register machine instructions
In the following, all instructions which the register machine accepts will be outlined.
If you feel like an instruction is missing, 
[open an issue](https://github.com/itsyunaya/rmcli/issues/new) and explain what it should
do and how exactly it functions.

```
DLOAD <NUM>     Loads a number into the accumulator
LOAD <NUM>      Loads the number stored in register <NUM> into the accumulator
STORE <NUM>     Stores the number present in the accumulator into register <NUM>
INC             Increases the number in the accumulator by one
DEC             Decreases the number in the accumulator by one
ADD <NUM>       Adds the number stored in the register <NUM> to the accumulator
ADDI <NUM>      Adds the number <NUM> to the accumulator
SUB <NUM>       Subtracts the number stored in the register <NUM> from the accumulator
SUBI <NUM>      Subtracts the number <NUM> from the accumulator
MUL <NUM>       Multiplies the number stored in the register <NUM> with the one in the accumulator
MULI <NUM>      Multiplies the number <NUM> with the one in the accumulator
DIV <NUM>       Divides the number stored in the accumulator by the number stored in register <NUM>
DIVI <NUM>      Divides the number stored in the accumulator by the number <NUM>
MOD <NUM>       Gets the modulo of dividing the accumulator by the number stored in register <NUM>
JMP <NUM>       Jumps to line <NUM>
JEQ <NUM>       If the accumulator's value equals 0, jump to line <NUM>
JNE <NUM>       If the accumulator's value does not equal 0, jump to line <NUM>
JGE <NUM>       If the accumulator's value is greater or equal to 0, jump to line <NUM>
JGT <NUM>       If the accumulator's value is greater than 0, jump to line <NUM>
JLE <NUM>       If the accumulator's value is equal or less than 0, jump to line <NUM>
JLT <NUM>       If the accumulator's value is less  than zero, jump to line <NUM>
END             Stops execution and prints a table with the values of the first ten registers & accumulator
```

## Afterword
Since this is my first project in C++, expect some bugs and quirks to be present.
Incase you encounter one, please 
[report it](https://github.com/itsyunaya/rmcli/issues/new). Other kinds of feedback are
also appreciated.