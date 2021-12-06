#include<stdio.h>

int board[3][3];
char choiceofUser,choiceofComputer;

//on Board 0 for Empty 
//         1 for User
//         2 for Computer

void tictactoe()
{
    int winlosedraw=0;

    initialize();
    choiceOX();
    display();
    // printf("Enter The Position Where Would You Like To Enter %c : \n",choiceofUser);
    while(winlosedraw!=1)
    {
        int position;
        findemptyposition();
        printf("Enter a Position To Enter %d : ",choiceofUser);
        scanf("%d",&position);
        entervalueinBoard(position);
    }
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

    if(choiceofUser=='O' || choiceofUser=='o')
    {
        choiceofComputer='X';
    }
    else if(choiceofUser=='X' || choiceofUser=='x')
    {
        choiceofComputer='O';
    }
    else
    {
        printf("INVALID CHOICE TRY AGAIN ...\n");
        choiceOX();
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

void findemptyposition()
{
    int k=1;
    printf("Available Positions :  ");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==0)
            {
                printf("%d ",k);
            }
            k++;
        }
    }
}

void entervalueinBoard(int position)
{
    switch (position)
    {
        case 1:
            board[0][0]=1;
            break;
        case 2:
            board[0][1]=1;
            break;
        case 3:
            board[0][2]=1;
            break;
        case 4:
            board[1][0]=1;
            break;
        case 5:
            board[1][1]=1;
            break;
        case 6:
            board[1][2]=1;
            break;
        case 7:
            board[2][0]=1;
            break;
        case 8:
            board[2][1]=1;
            break;
        case 9:
            board[2][2]=1;
            break;
        default:
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d",&position);
            enter

    }
}

void main()
{
    tictactoe();
}

// for(int i=0;i<3;i++)
// {
//     for(int j=0;j<3;j++)
//     {
        
//     }
// }
