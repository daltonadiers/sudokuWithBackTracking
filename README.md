# sudokuBackTracking

This project aims to solve any sudoku game that has a possible solution. To do this, it uses the BackTracking technique, that is, every time the algorithm makes a mistake and has no more options available to move forward, it must undo a previous step and try again following another path.
To implement backtracking, the stack structure was used, responsible for informing us of the last actions performed and where we should go back. If the algorithm finds itself dead-end and the stack is empty, it means that the current game has no solution.
