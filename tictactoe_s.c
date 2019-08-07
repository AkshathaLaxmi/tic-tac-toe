#include<stdio.h>
#include<stdlib.h>
#include"tictactoe.h"
int check(char box[10])
{
	
	if((box[0]==box[1])&&(box[1]==box[2]))
	{
		if(box[0]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[3]==box[4])&&(box[4]==box[5]))
	{
		if(box[3]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[6]==box[7])&&(box[7]==box[8]))
	{
		if(box[6]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[0]==box[4])&&(box[4]==box[8]))
	{
		if(box[0]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[2]==box[4])&&(box[4]==box[6]))
	{
		if(box[2]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[0]==box[3])&&(box[3]==box[6]))
	{
		if(box[0]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[1]==box[4])&&(box[4]==box[7]))
	{
		if(box[1]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[2]==box[5])&&(box[5]==box[8]))
	{
		if(box[2]=='X')
			return 3;
		else
			return 4;
	}
	else if((box[0]!='1')&&(box[1]!='2')&&(box[2]!='3')&&(box[3]!='4')&&(box[4]!='5')&&(box[5]!='6')&&(box[6]!='7')&&(box[7]!='8')&&(box[8]!='9'))
		return 2;
	else 
		return 1;
}
void game2(char box[])
{
	int n = check(box);
	int check1 = 1;
	int pos = -1;
	char player1, player2;
	printf("Player 1 is X and player 2 is O\n");
	player1 = 'X';
	player2 = 'O';
	
	printf("The game begins!\n");
	while(n == 1)
	{
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[0], box[1], box[2]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[3], box[4], box[5]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[6], box[7], box[8]);
		printf("	|	|	\n");
		printf("Player 1, enter the box number where you want to enter %c in: ", player1);
		scanf("%d", &pos);
		
		if(box[pos-1]!=pos+48)
		{
			printf("Box occupied. Game Over.\n");
			exit(1);
				
		}
		
		box[pos-1] = player1;
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[0], box[1], box[2]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[3], box[4], box[5]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[6], box[7], box[8]);
		printf("	|	|	\n");
		n = check(box);
		
		if(n == 1)
		{	
			printf("Player 2, enter the box number where you want to enter %c in: ", player2);
			scanf("%d", &pos);
			
			if(box[pos-1]!=pos+48)
			{
				printf("Box occupied. Game Over.\n");
				exit(1);
				
			}
			
		
		
		box[pos-1] = player2;
		n = check(box);

		
		}
	}
	switch(n)
	{
		case 2: printf("It's a draw :/\n");
			break;
		case 3: printf("Player 1 wins!\n");
			break;
		case 4: printf("Player 2 wins!\n");
			break;
	}		
}
void shuffle(int *array, int n)
{
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int occupied(char *box, int pos)
{
	if(box[pos-1]!=pos+48)
	{
		return 1;
			
	}
	else
		return 0;
}
void game1(char box[])
{
	char C_move = 'O';
	char H_move = 'X';
	int n = check(box);
	int check1 = 1;
	int pos = -1;
	printf("Player is X and Computer is O\n");
	printf("The game begins!\n");
	int moves[9] = {1,2,3,4,5,6,7,8,9};
	shuffle(moves, 9);
	while(n == 1)
	{
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[0], box[1], box[2]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[3], box[4], box[5]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[6], box[7], box[8]);
		printf("	|	|	\n");
		printf("Player, enter the box number where you want to enter %c in: ", H_move);
		scanf("%d", &pos);
		if(box[pos-1]!=pos+48)
		{
			printf("Box occupied. Game Over.\n");
			exit(1);
			
		}
		box[pos-1] = H_move;
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[0], box[1], box[2]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[3], box[4], box[5]);
		printf("________|_______|_______\n");
		printf("	|	|	\n");
		printf("    %c   |   %c   |   %c   \n", box[6], box[7], box[8]);
		printf("	|	|	\n");
		n = check(box);
		if(n == 1)
		{	
			
			n = check(box);
			int i = 0;
			pos = moves[i];			
			int l = occupied(box, pos);
			while(l)
			{
				i++;
				pos = moves[i];
				l = occupied(box, pos);
			}
			box[pos-1] = C_move;
			n = check(box);
		}
	}
	switch(n)
	{
		case 2: printf("It's a draw :/\n");
			break;
		case 3: printf("Player 1 wins!\n");
			break;
		case 4: printf("Player 2 wins!\n");
			break;
	}		
}

void rules()
{
	printf("Only motive is to get a straight line of 3 (Xs or Os).\n");
	printf("Our mode of playing would require user to type in the position of the box (position of box displayed in the box if available)where they want to enter their avatar\n");
	printf("The postion of the box must be between 1 and 9\n");
	printf("Enjoy!\n");
}