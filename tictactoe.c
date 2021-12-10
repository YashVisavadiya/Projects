#include <stdio.h>

int board[3][3], computercount = 0, winlosedraw = 0, countComputerWin = 0, countUserWin = 0, isempty;
char choiceofUser, choiceofComputer;

// on Board 0 for Empty
//          1 for User
//          2 for Computer

void tictactoe()
{
    winlosedraw = 0;
    initialize();
    choiceOX();
    display();
    startgame();
}

void initialize()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

void choiceOX()
{
    printf("Enter Your Choice ' O '  /  ' X ' : ");
    scanf("\t%c", &choiceofUser);

    if (choiceofUser == 'O' || choiceofUser == 'o')
    {
        choiceofComputer = 'X';
    }
    else if (choiceofUser == 'X' || choiceofUser == 'x')
    {
        choiceofComputer = 'O';
    }
    else
    {
        printf("\n%d\n",choiceofUser);
        printf("INVALID CHOICE TRY AGAIN ...\n");
        choiceOX();
    }
}

void display()
{
    int k=1;
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                if (j == 2)
                {
                    printf("\t'%d'\t ",k);
                }
                else
                {
                    printf("\t'%d'\t| ",k);
                }
            }
            else if (board[i][j] == 1)
            {
                if (j == 2)
                {
                    printf("\t %c \t ", choiceofUser);
                }
                else
                {
                    printf("\t %c \t| ", choiceofUser);
                }
            }
            else if (board[i][j] == 2)
            {
                if (j == 2)
                {
                    printf("\t %c \t ", choiceofComputer);
                }
                else
                {
                    printf("\t %c \t| ", choiceofComputer);
                }
            }
            k++;
        }
        printf("\n");
    }
}

void startgame()
{
    while (winlosedraw != 1)
    {
        int position;
        computercount = 0;
        // findemptyposition();
        if (!isemptyposition())
        {
            if (checkwinlosedrawCondition())
            {
                break;
            }
        }
        printf("\nEnter a Position To Enter %c : ", choiceofUser);
        scanf("%d", &position);
        entervalueinBoard(position);
        if (checkwinlosedrawCondition())
        {
            break;
        }
        computerturn();
        system("cls");
        display();
        if (checkwinlosedrawCondition())
        {
            break;
        }
    }
}

// void findemptyposition()
// {
//     int k = 1;

//     isempty = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (board[i][j] == 0)
//             {
//                 // if (isempty == 0)
//                 // {
//                 //     printf("Available Positions :  ");
//                 // }
//                 // printf("%d ", k);
//                 isempty = 1;
//             }
//             k++;
//         }
//     }
// }

int isemptyposition()
{
    isempty = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                isempty = 1;
            }
        }
    }
    return isempty;
}

void entervalueinBoard(int position)
{
    switch (position)
    {
    case 1:
        if (board[0][0] == 0)
        {
            board[0][0] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 2:
        if (board[0][1] == 0)
        {
            board[0][1] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 3:
        if (board[0][2] == 0)
        {
            board[0][2] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 4:
        if (board[1][0] == 0)
        {
            board[1][0] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 5:
        if (board[1][1] == 0)
        {
            board[1][1] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 6:
        if (board[1][2] == 0)
        {
            board[1][2] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 7:
        if (board[2][0] == 0)
        {
            board[2][0] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 8:
        if (board[2][1] == 0)
        {
            board[2][1] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    case 9:
        if (board[2][2] == 0)
        {
            board[2][2] = 1;
        }
        else
        {
            printf("Invalid Position Try agian...\n");
            printf("Enter Position : ");
            scanf("%d", &position);
            entervalueinBoard(position);
        }
        break;
    default:
        printf("Invalid Position Try agian...\n");
        printf("Enter Position : ");
        scanf("%d", &position);
        entervalueinBoard(position);
    }
}

void computerturn()
{
    checkpairofComputer();
    if (computercount == 1)
    {
        return;
    }
    checkpairofUser();
    if (computercount == 1)
    {
        return;
    }
    enterinCenterorCorner();
    if (computercount == 1)
    {
        return;
    }
    enterinCenterofEdge();
}

void enterinCenterorCorner()
{
    if (board[1][1] == 0)
    {
        board[1][1] = 2;
        computercount = 1;
        return;
    }
    if (board[0][0] == 0)
    {
        board[0][0] = 2;
        computercount = 1;
        return;
    }
    if (board[0][2] == 0)
    {
        board[0][2] = 2;
        computercount = 1;
        return;
    }
    if (board[2][0] == 0)
    {
        board[2][0] = 2;
        computercount = 1;
        return;
    }
    if (board[2][2] == 0)
    {
        board[2][2] = 2;
        computercount = 1;
        return;
    }
}

void enterinCenterofEdge()
{
    if (board[0][1] == 0)
    {
        board[0][1] = 2;
        computercount = 1;
        return;
    }
    if (board[1][0] == 0)
    {
        board[1][0] = 2;
        computercount = 1;
        return;
    }
    if (board[1][2] == 0)
    {
        board[1][2] = 2;
        computercount = 1;
        return;
    }
    if (board[2][1] == 0)
    {
        board[2][1] = 2;
        computercount = 1;
        return;
    }
}

void checkpairofComputer()
{
    if ((board[0][1] == 2 && board[0][2] == 2) || (board[1][0] == 2 && board[2][0] == 2) || (board[1][1] == 2 && board[2][2] == 2))
    {
        if (board[0][0] == 0)
        {
            board[0][0] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 2 && board[2][0] == 2) || (board[1][1] == 2 && board[1][2] == 2))
    {
        if (board[1][0] == 0)
        {
            board[1][0] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 2 && board[1][0] == 2) || (board[2][1] == 2 && board[2][2] == 2) || (board[1][1] == 2 && board[0][2] == 2))
    {
        if (board[2][0] == 0)
        {
            board[2][0] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 2 && board[0][2] == 2) || (board[1][1] == 2 && board[2][1] == 2))
    {
        if (board[0][1] == 0)
        {
            board[0][1] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 2 && board[2][2] == 2) || (board[0][2] == 2 && board[2][0] == 2) || (board[1][0] == 2 && board[1][2] == 2) || (board[0][1] == 2 && board[2][1] == 2))
    {
        if (board[1][1] == 0)
        {
            board[1][1] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][1] == 2 && board[1][1] == 2) || (board[2][0] == 2 && board[2][2] == 2))
    {
        if (board[2][1] == 0)
        {
            board[2][1] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 2 && board[0][1] == 2) || (board[1][2] == 2 && board[2][2] == 2) || (board[1][1] == 2 && board[2][0] == 2))
    {
        if (board[0][2] == 0)
        {
            board[0][2] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[1][0] == 2 && board[1][1] == 2) || (board[0][2] == 2 && board[2][2] == 2))
    {
        if (board[1][2] == 0)
        {
            board[1][2] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 2 && board[1][1] == 2) || (board[2][0] == 2 && board[2][1] == 2) || (board[0][2] == 2 && board[1][2] == 2))
    {
        if (board[2][2] == 0)
        {
            board[2][2] = 2;
            computercount = 1;
            return;
        }
    }
}

void checkpairofUser()
{
    if ((board[0][1] == 1 && board[0][2] == 1) || (board[1][0] == 1 && board[2][0] == 1) || (board[1][1] == 1 && board[2][2] == 1))
    {
        if (board[0][0] == 0)
        {
            board[0][0] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 1 && board[2][0] == 1) || (board[1][1] == 1 && board[1][2] == 1))
    {
        if (board[1][0] == 0)
        {
            board[1][0] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 1 && board[1][0] == 1) || (board[2][1] == 1 && board[2][2] == 1) || (board[1][1] == 1 && board[0][2] == 1))
    {
        if (board[2][0] == 0)
        {
            board[2][0] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 1 && board[0][2] == 1) || (board[1][1] == 1 && board[2][1] == 1))
    {
        if (board[0][1] == 0)
        {
            board[0][1] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 1 && board[2][2] == 1) || (board[0][2] == 1 && board[2][0] == 1) || (board[1][0] == 1 && board[1][2] == 1) || (board[0][1] == 1 && board[2][1] == 1))
    {
        if (board[1][1] == 0)
        {
            board[1][1] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][1] == 1 && board[1][1] == 1) || (board[2][0] == 1 && board[2][2] == 1))
    {
        if (board[2][1] == 0)
        {
            board[2][1] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 1 && board[0][1] == 1) || (board[1][2] == 1 && board[2][2] == 1) || (board[1][1] == 1 && board[2][0] == 1))
    {
        if (board[0][2] == 0)
        {
            board[0][2] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[1][0] == 1 && board[1][1] == 1) || (board[0][2] == 1 && board[2][2] == 1))
    {
        if (board[1][2] == 0)
        {
            board[1][2] = 2;
            computercount = 1;
            return;
        }
    }
    if ((board[0][0] == 1 && board[1][1] == 1) || (board[2][0] == 1 && board[2][1] == 1) || (board[0][2] == 1 && board[1][2] == 1))
    {
        if (board[2][2] == 0)
        {
            board[2][2] = 2;
            computercount = 1;
            return;
        }
    }
}

int checkwinlosedrawCondition()
{
    checkwinlosedraw();

    if (winlosedraw == 1 && countUserWin == 1)
    {
        printf("\nUSER WINS \nCOMPUTER LOSES");
        return 1;
    }
    if (winlosedraw == 1 && countComputerWin == 1)
    {
        printf("\nCOMUTER WINS \nUSER LOSES\n");
        return 1;
    }
    if (winlosedraw == 1 && countComputerWin == 0 && countUserWin == 0)
    {
        printf("\nGAME DRAW\n");
        return 1;
    }
}

void checkwinlosedraw()
{
    checkforUserWin();

    if (winlosedraw == 0)
    {
        checkforComputerWin();
    }
    if (winlosedraw == 0)
    {
        checkforDraw();
    }
}

void checkforUserWin()
{
    if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
    else if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
    else if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
    else if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
    else if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
    else if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
    else if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
    else if (board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1)
    {
        winlosedraw = 1;
        countUserWin = 1;
    }
}

void checkforComputerWin()
{
    if (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
    else if (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
    else if (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
    else if (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
    else if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
    else if (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
    else if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
    else if (board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 2)
    {
        winlosedraw = 1;
        countComputerWin = 1;
    }
}

void checkforDraw()
{
    if (isempty == 0 && countComputerWin == 0 && countUserWin == 0)
    {
        winlosedraw = 1;
    }
}

void main()
{
    int choice=1;
    do {
        tictactoe();
        printf("\nIf You Want To Play Again Press 1 \nFor Exit Press 0 :");
        scanf("%d",&choice);
        system("cls");
    }while(choice!=0);

}
