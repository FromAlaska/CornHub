# CornHub
This project is for Assembly Language "Project 2". 
CornHub uses SFML, CUDA, a CMake Library and any operating system. 
It is a simple game created using simple mathematics, objects, and sprites.

Created by:

* Jim Samson (jasamson@alaska.edu)
* Samuel Grenon
* Cameron K. Titus
* Kim Fairbanks

Assembly Language Project 2

---

## Specifications
What can I run this on?
* Windows 7, 8, 10
* Mac OSX 10.10 to 10.16
* Ubuntu 16.x (Recommended)

---
Required packages/software
* C++14 compiler
* [SFML](https://www.sfml-dev.org/download/sfml/2.4.2/) 2.x.x
* [CMake](https://cmake.org/download/) 2.6.x or newer
* GNU Make 4.x
---

This project can be built using a terminal:
* Clone the repo from [GitHub](https://github.com) 
  ```
  $ git clone https://github.com/FromAlaska/CornHub.git
  ```
* Change the directory to cloned git repository and create a build folder, then change the directory in it.
  ```
  $ cd CornHub
  $ mkdir build
  $ cd build/
  ```
* Let CMake generate the MakeFile for you:
  ```
  $ cmake ..
  ```
* If all the packages are correctly installed, run the MakeFile to create the executable.
  ```
  $ make
  ```
* === Notice! === If you really like this project, you can install it on this computer
  ```
  $ sudo make install
  ```
* Now, you may able to run the application by using the following command:
  ```
  $ ./CornHub
  ```
* Thank You!

* Controls for the game:
  * A - Move left
  * L - Move right
  * Ctrl - Move row down
  * Shift - move row up
  * Space - EAT
---

### License
This project is protected under the Unlicense License. You're free to use our code. Please review the license in the Git Repository.
