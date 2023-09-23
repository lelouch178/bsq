```
 /$$$$$$$   /$$$$$$   /$$$$$$ 
| $$__  $$ /$$__  $$ /$$__  $$
| $$  \ $$| $$  \__/| $$  \ $$
| $$$$$$$ |  $$$$$$ | $$  | $$
| $$__  $$ \____  $$| $$  | $$
| $$  \ $$ /$$  \ $$| $$/$$ $$
| $$$$$$$/|  $$$$$$/|  $$$$$$/
|_______/  \______/  \____ $$$
                          \__/
```

Grade : B | Mark : 19.8/22

* [Description](#description)
* [Prerequisites](#prerequisites)
* [Installation](#installation)

## Description

You must find the largest possible square on a board while avoiding obstacles.

The board can be generated two ways. The first one is by reading a file passed as the program’s argument.
The file is valid if it is respecting those constraints:

* its first line contains the number of lines on the board (and only that),
* “.” (representing an empty place) and “o” (representing an obstacle) ar ethe only two characters for the
  other lines,
* all of the lines are of the same length (except the first one),
* it contains at least one line,
* each line is terminated by ‘\n’.

You program must print the board, with some “.” replaced by “x” to represent the largest square you found.

If ever there are several solutions, you have to represent only the highest square. If they
are still several solutions, choose the square to the left.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See [**program usage**](#program-usage) for notes on how to use the project after having it installed.

### Prerequisites

* `gcc`
* `make`

#### Fedora:

```
sudo dnf install gcc make
```

#### Ubuntu / Debian:

```
sudo apt-get install gcc make
```

#### Arch:

```
sudo pacman -S install gcc make
```

#### MacOs:

```
brew install gcc make
```

### Installation

First, clone this repository and go into it :

```
git clone https://github.com/AdrienL06/bsq && cd bsq/
```

Compile the project:

```
make
```

## Program usage

bsq expects a map given in argument.

### Using a predefinite map

```
USAGE
    ./bsq maps-intermediate/mouli_maps/[map.txt]
DESCRIPTION
    map.txt file containing the map in which to search the biggest square
```

### Generating your own

The second way to obtain a board is to generate one based on given parameters.

```
USAGE
    ./bsq nbr "pattern"
DESCRIPTION
    nbr number representing the width and height of the board
    pattern pattern that will be repeated line by line along the board
```

For example :

```
❯ ./bsq 10 "...ooo..."
...oooxxx.
..ooo.xxx.
.ooo..xxx.
ooo......o
oo......oo
o......ooo
......ooo.
.....ooo..
....ooo...
...ooo....
❯ 
```

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language)) - Main language used

## Authors

* **Adrien Lachambre** - *the project* - [AdrienL06](https://github.com/AdrienL06)
