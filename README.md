## Step 1 
```
python3 -m pip install --user pros-cli
```

## Step 2 
```
prosv5 c new-project .
```

**NOTE**: I had to install the `arm-none-eabi-g++` toolchain in order to compile my project. Directions on how to do this for your particular platform can be found here: https://pros.cs.purdue.edu/v5/getting-started/index.html

## Optional Step - Autocomplete 
I recommend using [clangd](https://clangd.llvm.org/) for autocompletion.

Installation instructions for `clangd` can be found [here](https://clangd.llvm.org/installation.html)

In order for `clangd` to understand your code, it needs to have a `compile_commands.json` file at the root of your project.

This file tells `clangd` how to compile your code.

The `prosv5` CLI gives you a super convenient way of generating this file

To generate it, run `prosv5 build-compile-commands` from anywhere in your project.

After you do this, install the `clangd` plugin for whichever editor you are using.

If you have trouble with this and are not already using it, you can switch to [VSCode](https://code.visualstudio.com/) and install the `clangd` plugin there
