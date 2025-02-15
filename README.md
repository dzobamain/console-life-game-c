# Life Game - Console Implementation in C

## Installation Guide

1. Windows
    + Download and install [MinGW](https://www.mingw-w64.org/downloads/).
    + Add `gcc` to the `PATH` environment variable.
    + Verify the installation by running:
    + ```sh 
      gcc --version
      ```
1. macOS
   + Install Xcode Command Line Tools.  
   + ```sh
     xcode-select --install
     ```
   + Or install `gcc` via Homebrew.  
   + ```sh
     brew install gcc
     ```
   + Verify the installation by running:  
   + ```sh
     gcc --version
     ```

2. Linux
   + Install `gcc` using your package manager.  
   + **Ubuntu/Debian**  
   + ```sh
     sudo apt update && sudo apt install gcc -y
     ```
   + **Arch Linux**  
   + ```sh
     sudo pacman -S gcc
     ```
   + **Fedora**  
   + ```sh
     sudo dnf install gcc
     ```
   + Verify the installation by running:  
   + ```sh
     gcc --version
     ```

### Install the Project

   + Open a terminal and run the following command to clone the repository:
   + ```sh
     git clone https://github.com/Dzobamain/console-life-game-c.git
     cd console-life-game-c
     ```

## How to Run

   + Open a terminal and navigate to the project folder:
   + ```sh
     cd console-life-game-c
     ```
   + Compile the program using `gcc`:
   + ```sh
     gcc -o lifeGame main.c
     ```
   + Run
   + ```sh 
     ./lifeGame
     ```

    