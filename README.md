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