#include<stdio.h>

int board[3][3];
char choiceofUser,choiceofComputer;

//on Board 0 for Empty 
//         1 for User
//         2 for Computer



void tictactoe()
{
    initialize();
    choiceOX();
    display();
    // printf("Enter The Position Where Would You Like To Enter %c : \n",choiceofUser);

}

void initialize()
{
    for(int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]=0;
        }
        
    }
}

void choiceOX()
{
    
    printf("Enter Your Choice ' O '  /  ' X ' : ");
    scanf("%c",&choiceofUser);

    if(choiceofUser=='O')
    {
        choiceofComputer='X';
    }
    else if(choiceofUser=='X')
    {
        choiceofComputer='O';
    }
    else
    {
        printf("INVALID CHOICE ...\n");
    }
}

void display()
{
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if(board[i][j]==0)
            {
                printf(" \t| ");
            }
            else if(board[i][j]==1)
            {
                printf("%c \t| ",choiceofUser);
            }
            else if(board[i][j]==2)
            {
                printf("%c \t| ",choiceofComputer);
            }
        }
        printf("\n");
    }
}



void main()
{
    tictactoe();
}
