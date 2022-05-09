/* THIS WILL NOT GOING TO LOOK PRETTY
	IF YOU LAUNCH THIS IN WINDOW 
	REMOVE THE COLOR TEXT AND REPLACE ● WITH NUMBER */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// GAME PROGRESS
int PROGRESS = 0;

// INITIALIZE BOARD
int BOARD_X = 6;
int BOARD_Y = 8;

// GET THE WORKING SPACE
int SPACE[6][8];
int SPACE_NAV[8] = {6, 6, 6, 6, 6, 6, 6, 6};

// DECLARE CONSOLE TEXT COLOR
const char RED[] = "\033[0;31m";
const char YELLOW[] = "\033[0;33m";
const char CYAN[] = "\033[0;36m";
const char CLEAR[] = "\033[0m";
const char HIDE[] = "\e[?25l";
const char UNHIDE[] = "\e[?25h";

// ALL VOID
void CHECK_WINNER();
void BOARD();

int GET_VALUE()
/* FUNCTION TO GET COLUMN VALUE */
{
	char TURN[100];
	fflush(stdin); // FLUSH LAST INPUT
	fgets(TURN, 100, stdin);
	printf("%s", CLEAR);
	return atoi(TURN); // RETURN INTERGER
}

int main(int argc, char *argv[])
{
	BOARD();
	int TURN = 0;
	while (true) // ALWAYS TRUE FOR GAMEPLAY
	{
		if (SPACE_NAV[0] <= 0 & SPACE_NAV[1] <= 0 & SPACE_NAV[2] <= 0 & SPACE_NAV[3] <= 0 & SPACE_NAV[4] <= 0 & SPACE_NAV[5] <= 0 & SPACE_NAV[6] <= 0 & SPACE_NAV[7] <= 0)
		{
			// BREAK IF DRAW
			printf("IT'S A DRAW!");
			break;
		}
		else if (TURN <= 0 || TURN >= 9)
		{
			/* IF GIVEN VALUE IS LESS THAN OR EQUAL TO 0
			OR GREATER THAN OR EQUAL TO 0 RE EXECUTE*/
			printf("%s%s", HIDE, (PROGRESS % 2) ? RED : YELLOW);
			printf("COLUMN: ");
			TURN = GET_VALUE(); // GET COLUMN VALUE
		}
		else
		{
			system("clear"); // CLEAR CONSOLE
			SPACE_NAV[TURN - 1]--;
			if (SPACE_NAV[TURN - 1] < 0)
			{
				// IF COLUMN IS ALREADY FILLED CONTINUE
				printf("THIS ROW ALREADY FILLED!\n\n");
				TURN = 0;
				continue;
			}
			// REPLACE LATEST COLUMN SPACE
			SPACE[SPACE_NAV[TURN - 1]][TURN - 1] = (PROGRESS % 2) ? 1 : 2;
			BOARD();
			PROGRESS++;
			TURN = 0;
		}
	}
}

void CHECK_WINNER()
/* CHECK WINNER */
{
	// NOT IMPLEMENTED YET :(
}

void BOARD()
/* THE BOARD, THIS WILL ALWAYS EXECUTE AFTER TURN */
{
	for (int row = 0; row != BOARD_X; row++)
	{
		for (int column = 0; column != BOARD_Y; column++)
		{
			printf("|   |"); // FILLER SPACE
		}
		printf("\n");
		for (int column = 0; column != BOARD_Y; column++)
		{
			if (SPACE[row][column] == 0)
			{
				printf("%s", CLEAR);
				printf("|   |");
			}
			else
			{
				printf("| %s●%s |",
					   (SPACE[row][column] == 1) ? RED : YELLOW,
					   CLEAR);
			}
		}
		printf("\n");
	}
	for (int column = 0; column != BOARD_Y; column++)
	{
		printf("| %s%d%s |", CYAN, column + 1, CLEAR); // FILLER SPACE
	} 
	printf("\n\n\n");
}
