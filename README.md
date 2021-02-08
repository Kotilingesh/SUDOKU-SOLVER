# SUDOKU SOLVER-A C-Program that solves a 9x9 sudoku puzzle

This project is a c program that inputs a 9x9 sudoku problem from the stdin and prints the solved one as an output.The problem needs to be inputed in such a way that the blank spaces are typed as zeroes.The program works on the principle of recursions, by doing trial and errors on the blank spaces in an orderly manner that reduces computation time.

This c-project consists of 9 broad functions, which are defined for its own specific purpose. The 9 functions include-

•	int main

•	inputfunc

•	printfunc

•	checposs

•	checposs_beta

•	comchec

•	fseg

•	gridsolve

•	kolinf

“int main”-
          
   Needless to say, it is the function at which the whole program starts and ends. In this program, three functions are called in the ‘int main’. Also the problem matrix is declared here as a 2d- array with indices as ‘9’.

“inputfunc”- a void function
           
   This function inputs the Sudoku problem as a 2 dimensional array with the respective indices representing the respective row number and column number, from the stdin from the user. Also, the blank spaces are to be fed as zeroes in the input by the user.  For example, the element in 5th row and 6th column is represented as “a [5][6]”.
        The process of inputting the matrix is done using 2 “while” loops (one inside the other). 
        
“printfunc”- a void function
           
   This function inputs a given 2d array and prints it out to the stdout. For example, an element with indices as “a [i][j]” is printed in the i’th row and j’th column
       
 “gridsolve”- a void function (applied in the “checposs” and “fsudoku” function)
          
   This function checks for the recurrence of a given number ‘k’ (provided as input) at a given index ‘l’ and ‘m’ (provided as input) in a box in which it exists and saves ‘0’ in a given address location (provided as input) if there is a recurrence (‘1’ if not). 
          
“comchec”-an integer type function
        
   This function checks for the completeness of a given sudoku matrix. If the matrix is complete, it returns ‘1’ (‘0’ if not).
           
“checposs”- a ‘pointer array’ return type function
             
   This function checks the number of possibilities of existence of a solution at each-and-every indices combination in an input 2d matrix and stores it in another 2d matrix with the respective indices. Also, it ignores the already filled index combination and fills it with ‘1’. 
         It does the above task by doing trial and error of each-and-every number (from 1 to 9) at each-and-every blank space.
      
“fseg”- a void function
           
   This function checks for the index value of a blank space in a given problem matrix that has the least possible number of solutions (except 0) and saves the index values in the assigned addresses. For this the ‘checposs’ function is used to get the possibility matrix. 

“checposs_beta”- an ‘integer’ return type function
          
   This function checks for the possibility of existence of a solution at each-and-every indices combination that is a blank space in an input 2d matrix. In other words, it checks if at least one possible number (1 to 9) could be filled in a given blank space. If a blank space is found with no possible solution, it returns ‘0’ (‘1’ if not) and stops.
          
"kolinf"- a void function
        
   It is the main function that actually solves the Sudoku. It is a recursive function (in other words the same function is called again in itself). 
      It solves the problem through the method of trial-and-error. It substitutes a value at a blank space which has the least possible number of solutions (which is found with the ‘fseg’ function) and checks for possibility of existence of a solution (with the ‘checposs_beta’ and ‘checposs’ function) for the thus formed matrix. If so (if there exists a solution), it continues and repeats the same (through means of recursion) with another index position, and so on, until the completeness of the grid (which is satisfied with the ‘comchec’ function). 


          
          



