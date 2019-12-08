# Commander

<br>![Commander](https://raw.githubusercontent.com/AnselmoGPP/Commander/master/example/command.png)

This is a header only-library (see headers folder) that you can include to be able to use your terminal (command line) easily from your C++ code and for scripting from C++.

<b>Contents:</b>

- <ins>headers</ins>: The single commander.h file that you can use in your project for using your terminal from your C++ code

- <ins>example</ins>: Here you will find an example of a project that uses this library for different actions (checking current directory, moving to another directory, creating folders, copying and renaming files...). 

<b>First steps:</b>

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
