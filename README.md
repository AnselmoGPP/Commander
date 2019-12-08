# Commander

This is a header only-library (see headers folder) that you can include to be able to use your terminal (command line) easily from your C++ code.

<bold>Contents:</bold>

- headers: The single commander.h file that you can use in your project for using your terminal from your C++ code

- src: Here you will find an example of a project that uses this library for different actions (checking current directory, moving to another directory, creating folders, moving and renaming files...). 

<bold>First steps:</bold>

First, you have to create an object of type commander. 

<code>
#include "commander.h"
commander terminal_1;
</code>

You issue one or more orders by using the exec() function:

<code>
terminal_1.exec("cd /home/username/dev");
terminal_1.exec("mkdir new_project");
</code>

<bold>Links:</bold>

- [**Linux scripting**](https://sciencesoftcode.wordpress.com/2019/10/27/linux-scripting/)
