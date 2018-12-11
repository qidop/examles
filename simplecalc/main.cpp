#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Log(fmt, ...) {printf("" fmt,  ##__VA_ARGS__); printf("\n"); }

//input format:
// 3 + 3
// 3 x 4 
// 2 / 2 
// 10 - 23 

int main(int AC, char **AV) {

	// DEBUG: show input arguments (uncomment && recompile)
	// DEBUG: uncoment for more info
	/*for(int i = 0; i < AC; ++i) {
		Log("%s", AV[i]);
	}*/

	// define the variable and save the number of input arguments
	int wordCounter = AC;
	
	// define our operands
	double opA = 0.0, opB = 1.0;

	// define a variable for the operator
	char *op = 0;
	
	// the main loop for parsing command line arguments, here we fill in our previously defined operands and opretor
	// the loop argument will be a previously saved counter
	// exit condition - zeroing the counter (operation --)
	while(--wordCounter > 0) {

		// we have a simple equation like: X op Y
		// therefore, we stop parsing the input arguments when we collect the required number of parameters for the simplest calculation. 
		// For this, the number of command line arguments to parse is reduced to 3
		if(AC - wordCounter > 3) {
			Log("full stack is ready! breaking....");
			break;
		}

		// define an iterator for an array of input arguments
		int it = AC - wordCounter;

		// at each step, we save the data from the input argument array to our variable in order to work with it later
		char *word = AV[it];

		// DEBUG: uncoment for more info
		//Log("[parser] c:%i wc:%i d:%i w:%s", AC, wordCounter, it, word);

		switch(it) {
			case 1:
				// save the data in the opA variable
				opA = strtod(word, 0);
				// DEBUG: uncoment for more info
				//Log("operand A = %.4f (%s)", opA, word);
				break;
			case 2:
				// save operand
				op = word;
				// DEBUG: uncoment for more info
				//Log("operator = %s", word);
				break;
			case 3:
				// save data in opB variable
				opB = strtod(word, 0);
				// DEBUG: uncoment for more info
				//Log("operand B = %.4f", opB);
				break;
			default:
				// in this place we work on what is not passed by condition in the switch
				{
					// can't define operator
					Log("can't define operator!");
					return -1;
				}
		}	
	}

	// check, suddenly the amount of input is less than what is needed for the equation ???
	if(AC - wordCounter <= 3) {
		Log("not enough input!!!");
		return -1;
	}

	// what if our operator is 0? this should not be! exit the program!
	if(op == 0) {
		Log("invalid input stream!");
		return -1;
	}

	// what if there is more than one character in the operator string? this should not be! exit the program!
	bool isOperatorValid = strlen(op) == 1;
	if(!isOperatorValid) {
		Log("invalid operator! %s", op);
		return -1;
	}

	// what if in operand B the number is 0 and the division operation is defined?
	if(fabs(opB) - 0.00001 < 0.0 && strncmp(op, "/", 1) == 0) {
		Log("operand B is NULL!!!");
		return -1;
	}

	// calculate the equation
	// compare the operator with the template and substitute the operands in the necessary equations

	double res = 0.0;
	if(strncmp(op, "+", 1) == 0) {
		res = opA + opB;
	} else if(strncmp(op, "-", 1) == 0) {
		res = opA - opB;
	} else if(strncmp(op, "x", 1) == 0) {
		res = opA * opB;
	} else if(strncmp(op, "/", 1) == 0) {
		res = opA / opB;
	} else {
		// again - something went wrong! There is no template for the declared operator!
		Log("invalid operator! %s", op);
		return -1;
	}

	// output the result of the calculation if all is well
	Log("%.6f %s %.6f = %.6f", opA, op, opB, res);

	// BINGO! our program has done it!

	return 0;
}