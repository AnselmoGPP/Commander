# Commander

<br>![Commander](https://raw.githubusercontent.com/AnselmoGPP/Commander/master/example/command.png)

This is a header-only library (see headers folder) that you can include to be able to use your terminal (command line) easily from your C++ code and for scripting from C++.

<b>Contents:</b>

- <ins>headers</ins>: The single commander.h file that you can use in your project for using your terminal from your C++ code

- <ins>example</ins>: Here you will find an example of a project that uses this library for different actions (checking current directory, moving to another directory, creating folders, copying and renaming files...). It creates a new folder called "labels" and does all his work there.

<b>First steps:</b>

First, you have to create an object of type commander. 
```p
#include "commander.h"
commander terminal_1;
```
You issue one or more orders by using the exec() function:
```cp
terminal_1.exec("cd /home/username/dev");
terminal_1.exec("mkdir new_project");
```
The exec function returns the output of the terminal:
```cp
std::string dir = terminal_1.exec("pwd");
```
Convert a string with sets of characters separated by <code>'\n'</code> in a set of strings:
```cp
std::string list = terminal_1.exec("ls ../some/directory");
std::vector<std::string> files;
terminal_1.extract_elements(list, files);
```
<bold>Links:</bold>

- [**Linux scripting**](https://sciencesoftcode.wordpress.com/2019/10/27/linux-scripting/)
