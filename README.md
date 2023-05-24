# tickers

## Description
`tickers` will read in a text file of stock symbols and their company names. From there,
users are prompted to enter a symbol they would like to search for, and if it exists,
will print the symbol, company name, as well as write to a text file showing the 
results.

Users are permitted to continue entered stock symbols until typing `Q` to quit.

`tickers` will accept input in either upper, lower, or mixed-case:
`ba`, `bA`, or `BA` will return the same results.

## Installation
The entire project can be pulled from Git.

Developed with C18 and compiled with gcc-9.

### Build
To build and compile the program:
```sh
<project_root_dir>$ make
```
To create the executable, called `ticker`.

### Run
```sh
<project_root_dir>$ ./ticker
```

To build and run in one command:
```sh
<project_root_dir>$ make money
```

### Cleanup
After running the program, execute:
```sh
<project_root_dir>$ make clean
```
To delete object files as well as the `search_results` created in the `data/` directory.

## Support
Additional information can be found in the man page:
```sh
man ./docs/tickers.1
```