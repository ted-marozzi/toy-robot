# Toy Robot Coding Challenge

This is a coding challenge from Iress.

## View this document in VSCode

<kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>V</kbd>

## Description and requirements

The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

See the [ToyRobot.pdf](ToyRobot.pdf) for more details.

See [gameprogrammingpatterns](https://gameprogrammingpatterns.com/command.html) for info on the command pattern used in this repo.

## Environment

This has only been tested inside the vscode docker container.

## VSCode Set Up

Make sure you have g++ and cmake installed and added to path and the recommend workspace extensions installed.

### Build

<kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd>

### Build and Debug

<kbd>F5</kbd>

### Code Coverage
Code coverage html is created after every test run.
This assumes running in dev container as it uses /app/lib
```
./code-coverage.sh
```
Start a live server with the live server extension and view the code_coverage_report folder.

## TODO

* Abstract out input and output

* Integration Tests - Mocking and Test Generation

* Gui Mode - Flag to print out a graph of the grid on report

* Verbose Mode - Flag to turn on help messages

* Look at Marking scheme
