# wlcrack
Solves Word Ladder Puzzles by Brute-force

## About Word Ladders
The Word Ladder is a word game and was created by Lewis Carroll in 1877. It is defined like so:

    Given the first and last words of a chain of 5 4-letter words, fill in the missing 3 words.
    For any two adjacent words, there must be a difference of only one letter.

### Example
**BARK -> BARE -> BANE -> LANE -> LAND**

[More information on Word Ladders (Wikipedia)](https://en.wikipedia.org/wiki/Word_ladder).

## About This Program
This program will find the solution for a Word Ladder puzzle given any two four-letter English words (providing a solution exists).

### Build
In order to obtain an executable version of the program, it needs to be compiled. You will need **v3** or greater of [CMake](https://cmake.org/) to do this.

These are the commands needed to build the project on unix-like systems:

```sh
cmake .
make
```

And to install the program (optional but recommended):

```sh
make install
```

> Installing may require super-user priveleges

### Why?
I'm aware that Word Ladder solving programs already exist, but I created this anyway as a re-implementation of a much earlier project I wrote which achieved the same aim.
I don't recommend using that version but for curiosity's sake, it can be found on my Github profile [here](https://github.com/saxbophone/wlc).
