#include<stdio.h>
#include<stdlib.h>

int main()
{
	
	int choice = 0;
	do
	{
		printf("Welcome to Tic Tac Toe!\n Enter 1 : Single player\t 2 : Dual player\t 3 : Rules\t 4 : Exit\n");
		scanf("%d", &choice);
		char box[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
		int n = check(box);                    //returns 1 for in the game, 2 for draw, 3 for player 1 win, 4 player 2 win.
		switch(choice)
		{
			case 1: game1(box);			//single player (TBD)
				break;
			case 2: game2(box);			//dual player
				break;
			case 3: rules();			//rules
				break;
			case 4: break;
			default: printf("Invalid input.\n");
		}
	}while(choice!=4);
	printf("Thank you for playing!\n");
	return 0;
}