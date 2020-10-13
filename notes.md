Step 1
```
python3 -m pip install --user https://github.com/purduesigbots/pros-cli/releases/download/3.1.4/pros_cli_v5-3.1.4-py3-none-any.whl
```

Step 2
```
prosv5 c new-project .
```

**NOTE**: I had to install the `arm-none-eabi-g++` toolchain in order to compile my project. Directions on how to do this for your particular platform can be found here: https://pros.cs.purdue.edu/v5/getting-started/index.html
