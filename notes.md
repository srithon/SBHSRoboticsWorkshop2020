## Step 1 
```
python3 -m pip install --user https://github.com/purduesigbots/pros-cli/releases/download/3.1.4/pros_cli_v5-3.1.4-py3-none-any.whl
```

## Step 2 
```
prosv5 c new-project .
```

**NOTE**: I had to install the `arm-none-eabi-g++` toolchain in order to compile my project. Directions on how to do this for your particular platform can be found here: https://pros.cs.purdue.edu/v5/getting-started/index.html

## Optional Step - Autocomplete 
I recommend using [[https://clangd.llvm.org/|clangd]] for autocompletion.

Installation instructions for `clangd` can be found [[https://clangd.llvm.org/installation.html|here]]

In order for `clangd` to understand your code, it needs to have a `compile_commands.json` file at the root of your project.

This file tells `clangd` how to compile your code.

The `prosv5` CLI tool gives you a super convenient way of generating this file

To generate it, run `prosv5 build-compile-commands` from anywhere in your project.

After you do this, install the `clangd` plugin for whichever editor you are using.

If you have trouble with this and are not already using it, you can switch to [[https://code.visualstudio.com/|VSCode]] and install the `clangd` plugin there

## Step 3 
* setup headers 
  * `ports.hpp` 
  * `robot.hpp` 
