# Projects
Hello! This repo contains some of the projects I have completed over the years. 

# Traveling Sales Person
A C++ project that implements a solver for the Traveling Salesperson Problem (TSP).

The input to the problem is a collection of n points in the plane. The goal of the TSP is to find the shortest path that visists every point exactly once and returns to the starting point. That is, we are looking for a cyccle in the graph that visits each vertex exactly once, such that the total length is as small as possible. For this problem, I applied the "nearest next point heuristic". 

The main file will output 5 tests. Each test will display the list of points (if there are 20 or less points), a drawing of the points (if there are 20 or less points), and the solution to the problem. 

# Binary Tree Implementation
A C project that involves manipulating and performing calculations on binary trees.

Part 1 gets a binary tree representing an arithmetic expression and returns the evaluation of the expression. 

Part 2 gets a binary search tree and returns the maximal element. A seperate function also returns the median element in the tree. For example, if the tree contains (1, 3, 6, 8, 100), the output is 6.

# Implementation of ADT of ints
A C project that implements a data structure to perform the following operations on an array of ints:

1. Creates a new array of a given length
2. Returns the length of the array
3. Sets the value in the array at a specified index
4. Returns the value from the array at a specified index
5. Frees the array
6. Changes the size of the array
7. Creates a copy of the given array and returns it
8. Appends an array to the original array and returns a pointer to the resulting array
9. Returns the first index of the array containing the element
10. For each index i=0... length-1, applies a function f to ar[i] and stores f(ar[i]) in ar[i]
11. Starting with accumulator = ar[0], for i=1..length-1 computes accumulator=f(accumulator,ar[i] and returns the accumulator
12. Returns a new array contaning only the elements that satisfy f[element]==true, adjusting length accordingly

# Maze Solving Robot
The purpose of this porject was to build a  miniature sized robot that was capable of solving a maze. The objective of the software was to program our robot to travel through a maze reaching any predetermined target using as many moves as needed, then maneuvering back to the starting position cell using the quickes route. The main code is written in the file 'Program.cs'. 

The following video provides a demonstration of our project: https://streamable.com/zws8tp

# Traffic Light Controller
We created a traffic light system using the TM4C123 MCU/Launchpad embedded microcontroller development system and Code Composer Studio IDE. The traffic light would specifically be designed to control traffic in a high volume high way intersection.




