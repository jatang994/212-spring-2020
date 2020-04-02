## Programming Assignment 3

> This assignment was originally developed for the COS 226 class of Princeton University.  The introductory portion (including all figures) of this writeup is based off the writeup for the Princeton's [version](http://www.cs.princeton.edu/courses/archive/fall17/cos226/assignments/8puzzle/index.html).

This assignment is to be completed individually.  You are NOT allowed to share your source code with anybody else.  The assignment is worth a total of $$115$$ points.  If you have any questions, visit us during office hours and/or post those questions on Piazza using the appropriate folder tag.

### Square Puzzles

The goal of the assignment is to write a program to solve the [N-puzzle](http://en.wikipedia.org/wiki/Fifteen_puzzle) problem using the A* search algorithm.  The N-puzzle is a sliding puzzle that is played on a square grid with $$N$$ square tiles labeled 1 through $$N$$, plus a blank square (represented as zero).  The goal is to rearrange the tiles so that they are in row-major order, using *as few moves as possible*.  Tiles are permitted to slide either horizontally or vertically into the blank square.  The following diagram shows a sequence of moves from an initial board (left) to the goal board (right) on a 8-puzzle.

![8-puzzle](files/pa-4moves.png){:height="140px"}

#### Detecting Unsolvable Boards

Not all initial boards can lead to the goal board by a sequence of moves, including these two:

![8-puzzle](files/pa-unsolvable.png){:height="140px"}

Remarkably, we can determine whether a board is solvable without solving it!  To do so, we count inversions.  An **inversion** is any pair of tiles $$i$$ and $$j$$ where $$i < j$$ but $$i$$ appears after $$j$$ when considering the board in row-major order (row 0, followed by row 1, and so forth).

![8-puzzle](files/pa-inversions.png){:height="160px"}

In order to determine whether a board is solvable we can:
- First, consider the case when the board size is an odd integer.  When $$l=\sqrt{N+1}$$ is odd, an l-by-l board is solvable if and only if its number of inversions is even.
- Second, when $$l$$ is even, an l-by-l board is solvable if and only if the number of inversions plus the row of the blank square is odd (rows start at index 0).

#### Hamming and Manhattan Distances

To measure how close a board is to the goal board (solution), we define two notions of distance:
- the *Hamming distance* between a board and the goal board is the number of tiles in the wrong position
- the *Manhattan distance* between a board and the goal board is the sum of the Manhattan distances (sum of the vertical and horizontal distance) from the tiles to their goal positions.

![8-puzzle](files/pa-hamming-manhattan.png){:height="160px"}

#### A* Algorithm

A* search is a general artificial intelligence algorithm.  It requires the definition of a *search node*, which is composed by a current board and the number of moves made to reach the board.

First, insert the initial search node (the initial board, 0 moves) into a priority queue (a *priority score/function* needs to be defined).  Then, delete from the priority queue the search node with the minimum priority, and insert onto the priority queue all neighboring search nodes (those that can be reached in one move from the dequeued search node).  Repeat this procedure until the search node dequeued corresponds to the goal board.

> To reduce unnecessary exploration of useless search nodes, when considering the neighbors of a search node, do not enqueue a neighbor if it has previously been enqueued.  We can enforce this by keeping a set (hashtable) of boards that have been explored already.

The efficacy of this approach hinges on the choice of *priority function* for a search node. We consider two priority functions:

- the Hamming priority function is the *Hamming distance of a board plus the number of moves made so far* to get to the current search node.  Intuitively, a search node with a small number of tiles in the wrong position is close to the goal, and we prefer a search node if has been reached using a small number of moves
- the Manhattan priority function is the *Manhattan distance of a board plus the number of moves made so far* to get to the search node

To solve the puzzle from a given search node on the priority queue, the total number of moves we need to make (including those already made) is at least its priority, using either the Hamming or Manhattan priority function.  Consequently, when the goal board is dequeued, we have discovered not only a sequence of moves from the initial board to the goal board, but one that makes the fewest moves.

#### Game Tree

One way to view the computation is as a game tree, where each search node is a node in the game tree and the children of a node correspond to its neighboring search nodes.  The root of the game tree is the initial search node; the internal nodes have already been processed; the leaf nodes are maintained in a priority queue; at each step, the A* algorithm removes the node with the smallest priority from the priority queue and processes it (by adding its children to both the game tree and the priority queue).  For example, the following diagram illustrates the game tree after each of the first three steps of running the A* search algorithm on a 3-by-3 puzzle using the Manhattan priority function.

![8-puzzle](files/pa-game-tree.png){:height="340px"}

### What to implement?

>- 5 points will be awarded for coding style/comments.

You will implement a class `Board` representing a search node (game state).  The class `Board` must be implemented in `board.h` and `board.cc`.  Your class must contain **at least** the following public methods:

>- `get_n_moves`, returns the number of moves for this board (5 points)
>- `hamming`, returns the hamming distance to the goal board (10 points)
>- `manhattan`, returns the manhattan distance to the goal board (15 points)
>- `inversions`, returns the number of inversions for the board (10 points)
>- `is_solvable`, returns whether this board is solvable (5 points)
>- `is_goal`, returns whether this board is a goal board (5 points)
>- `neighbors`, returns a vector of boards (objects of the class `Board`), where each of those is a valid neighbor (25 points)

```c++
#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>

class Board {
    private:
        // TODO
        // define your data members and private methods here

    public:
        // default constructor (for creating an empty board)
        Board();
        // full constructor
        // b: an initial board configuration
        // the board is just a sequence of numbers in row-major order (including the zero element)
        // n: number of elements in the board (including 0, for a 3x3 board n should be 9)
        // m: an initial number of moves
        // type: distance to be used 'm' for manhattan and 'b' for hamming
        Board(unsigned int *b, unsigned int n, unsigned int m, char type);
        // destructor
        ~Board();

        // verifies whether the board is solvable
        bool is_solvable();
        // verifies whether the board is a goal board
        bool is_goal();
        // returns in neigh a list of neighbors for this node
        void neighbors(std::vector<Board *> *neigh, char type);
        // gets the number of moves made so far (up to this node)
        unsigned int get_n_moves();
        // returns the hamming distance to the goal
        unsigned int hamming();
        // returns the manhattan distance to the goal
        unsigned int manhattan();
        // counts the number of inversions on a particular board
        unsigned int inversions();
};

#endif
```

In `main.cc` you will implement the A* algorithm:

>- `solve`, given an initial array of values, and a distance type, it runs a solver (35 points).  This function **must** print to the standard output one of the following messages: `Unsolvable board` if the board given is not solvable, or `Number of moves: n` where $$n$$ is the minimum number of moves required to get to the goal board.

```c++
#include "board.h"

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
// this is the main solver
// -----------------------------------------------------------------------
// b: an initial board configuration
// the board is just a sequence of numbers in row-major order (including the zero element)
// n: number of elements in the board (including 0)
// type: distance to be used 'm' for manhattan and 'b' for hamming
void solve(unsigned int *b, unsigned int n, char type) {
    // TODO
}

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
// it all starts here
// -----------------------------------------------------------------------
int main(int argc, char **argv) {
    // reads the search type from a command line argument (either h or m)
    // reads all initial board values from the stdin
    // calls the solver passing the values of the board and the search type
}
```

### How to run the Program?

We should be able to run your program with:

```bash
$ ./prog h < filename.txt
```

The program expects one command line argument.  The argument is a single character (either 'h' for hamming or 'm' for manhattan) that indicates which priority function to use.  Additionally, the program expects an initial board to be provided in the stdin.  In the example above `filename.txt` corresponds to a single text file that contains an initial board configuration.

Download [this](http://www.cs.princeton.edu/courses/archive/fall17/cos226/assignments/8puzzle/8puzzle.zip) archive if you want access to a large list of sample puzzles.


### Submission and Grading

You will submit **only** three files, named `board.h`, `board.cc`, and `main.cc`, to Gradescope.

You are required to use comments in all your functions and use proper coding style and indentation, otherwise points will be deducted.  Questions will be automatically graded.

> You must be advised that students caught cheating or plagiarizing will receive `no credit`.  Additional actions, including a failing grade in the class or referring the case for disciplinary action, may also be taken.
