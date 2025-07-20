# Madlibs

A C++ terminal-based Madlibs game, built using CMake for portability and automation.

---

## Overview

This is a terminal-based implementation of a classic Madlibs game, written in C++. It prompts users to fill in various parts of speech (nouns, verbs, adjectives, etc.) to generate humorous or nonsensical stories. The program reads story templates from text files and replaces placeholders with user input.

---

## Highlights

- Built with CMake (cross-platform)
- Easily extendable with new stories via text files
- Token recognition supports natural-language punctuation (`<verb>.`, `<noun>,`, etc.)

---

## File Structure
madlibs/
├── build/ # CMake build folder (not versioned)
├── stories/ # Folder containing story templates (1.txt, 2.txt, etc.)
├── madlibs.cpp # Main C++ source file
├── CMakeLists.txt # Build instructions for CMake


---

## Installation & Running

```bash
git clone https://github.com/tickymaster/Madlibs.git
cd Madlibs
mkdir build && cd build
cmake ..
cmake --build .
./madlibs

## Creating Your Own Stories
Just add text files to the stories/ folder using placeholder tags like:

    <noun>, <verb>, <adjective>, <place>, etc.

Example:
"Today I saw a <adjective> <noun> who loved to <verb> at the <place>."
