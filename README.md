# rmcli
rmcli  is a register machine simulator for the commandline, written in C++. For now, it
has a basic featureset and can process instructions in two different modes,
`interactive` and `fileinput`.

## Building
1. Clone the repository and `cd` into it
``` 
git clone https://github.com/itsyunaya/rmcli.git
cd rmcli 
```
2. Build the project
``` 
mkdir build && cd build
cmake ..
make
```
The executable will be located in `rmcli/build/bin`.

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
DLOAD i     Loads a number into the accumulator
LOAD i      Loads the number stored in register i into the accumulator
STORE i     Stores the number present in the accumulator into register i
INC         Increases the number in the accumulator by one
DEC         Decreases the number in the accumulator by one
ADD i       Adds the number stored in the register i to the accumulator
ADDI i      Adds the number i to the accumulator
SUB i       Subtracts the number stored in the register i from the accumulator
SUBI i      Subtracts the number i from the accumulator
MUL i       Multiplies the number stored in the register i with the one in the accumulator
MULI i      Multiplies the number i with the one in the accumulator
DIV i       Divides the number stored in the accumulator by the number stored in register i
DIVI i      Divides the number stored in the accumulator by the number i
MOD i       Gets the modulo of dividing the accumulator by the number stored in register i
JMP i       Jumps to line i
JEQ i       If the accumulator's value equals 0, jump to line i
JNE i       If the accumulator's value does not equal 0, jump to line i
JGE i       If the accumulator's value is greater or equal to 0, jump to line i
JGT i       If the accumulator's value is greater than 0, jump to line i
JLE i       If the accumulator's value is equal or less than 0, jump to line i
JLT i       If the accumulator's value is less  than zero, jump to line i
END         Stops execution and prints a table with the values of the first ten registers & accumulator
```

## Afterword
Since this is my first project in C++, expect some bugs and quirks to be present.
Incase you encounter one, please 
[report it](https://github.com/itsyunaya/rmcli/issues/new). Other kinds of feedback are
also appreciated.