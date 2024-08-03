#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define fi(a,n) for(int i=a;i<n;i++)
#define fj(a,n) for(int j=a;j<n;j++)
#define fk(a,n) for(int k=a;k<n;k++)
#define pb push_back

#define BOARD_SIZE 10
#define timee 5000

int n1=0,n2=0;
int att=0;
int m,option=0;

//to check if the input coordinates of the player are correct or not.
int check_for_command(char coord[2],char board[][BOARD_SIZE],int n)
{
    char w[]="0123456789";
    int row,col;
    fi(0,10)
    {
        if(coord[0]==w[i])
        {
            row=i;
        }
        if(coord[1]==w[i])
        {
            col=i;
        }
    }
    if(n==1)
    {
        if(board[row][col]=='o'||board[row][col]=='O'||board[row][col]=='-')
        {
            return 1;
        }
    }
    if(n==2)
    {
        if(board[row][col]=='x'||board[row][col]=='X'||board[row][col]=='-')
        {
            return 1;
        }
    }
    if((coord[0]>'8'||coord[0]<'1')||(coord[1]>'8'||coord[1]<'1'))
    {
        return 1;
    }

}
//swap function to move a piece
void swapi(char board[][BOARD_SIZE],int i1,int j1,int i2,int j2)
{
    char temp;
    temp=board[i1][j1];
    board[i1][j1]=board[i2][j2];
    board[i2][j2]=temp;
}
//this function prints all the possible coordinates where a piece can move and moves it to the position inputted by user by using swapi function.
int move(char coord[2],char board[][BOARD_SIZE],int n)
{
    option=0;
    //int ser=0;
    char w[]="0123456789";
    int row,col;
    fi(0,10)
    {
        if(coord[0]==w[i])
        {
            row=i;
        }
        if(coord[1]==w[i])
        {
            col=i;
        }
    }
    jump1:
    printf("You can move your piece to:\n");
    if(board[row][col]=='x' || board[row][col]=='o')
    {
        if(n==1)
        {
            if(board[row+1][col+1]=='-')
            {
                option++;
                printf("%d%d    " , row+1,col+1);
            }
            if(board[row+1][col-1]=='-')
            {
                option++;
                printf("%d%d    " ,row+1,col-1);
            }
            if(option==0)
            {
                printf("No moves possible for this piece. TRY AGAIN!\n");
                return 0;
            }
            printf("\n\n");
            char ch[2];
            printf("Where do you want to move your piece \n");
            printf("Add row no.\n");
            scanf("%s" , &ch[0]);
            printf("Add column no.\n");
            scanf("%s" , &ch[1]);
            if((ch[0]>'8'||ch[0]<'1')||(ch[1]>'8'||ch[1]<'1'))
            {
                printf("Wrong coordinates. TRY AGAIN!\n");
                goto jump1;
            }
            int x,y;

            fi(0,10)
            {
                if(ch[0]==w[i])
                {
                    x=i;
                }
                if(ch[1]==w[i])
                {
                    y=i;
                }
            }
            if((x==row+1 && y==col+1)||(x==row+1 && y==col-1))
            {
                int ok;
                ok=0;
            }
            else
            {
                printf("Wrong move TRY AGAIN! \n");
                goto jump1;
            }
            swapi(board,row,col,x,y);
            if(x==8 && board[x][y]!='X')
            {
                printf("\nYOUR PIECE HAS BECOME A KING! \n");
                board[x][y]='X';
            }
            return 1;
        }
        if(n==2)
        {
            if(board[row-1][col-1]=='-')
            {
                option++;
                printf("%d%d    " , row-1,col-1);
            }
            if(board[row-1][col+1]=='-')
            {
                option++;
                printf("%d%d    " , row-1,col+1);
            }
            char ch[2];
            if(option==0)
            {
                printf("No moves possible for this piece.TRY AGAIN!\n");
                return 0;
            }
            printf("\n\n");
            printf("Where do you want to move your piece \n");
            printf("Add row no.\n");
            scanf("%s" , &ch[0]);
            printf("Add column no.\n");
            scanf("%s" , &ch[1]);
            if((ch[0]>'8'||ch[0]<'1')||(ch[1]>'8'||ch[1]<'1'))
            {
                printf("Wrong coordinates. TRY AGAIN! \n");
                goto jump1;
            }
            int x,y;
            fi(0,10)
            {
                if(ch[0]==w[i])
                {
                    x=i;
                }
                if(ch[1]==w[i])
                {
                    y=i;
                }
            }
            if((x==row-1 && y==col-1)||(x==row-1 && y==col+1))
            {
                int ok;
                ok=0;
            }
            else
            {
                printf("Wrong move TRY AGAIN! \n");
                goto jump1;
            }
                swapi(board,row,col,x,y);
                if(x==1 && board[x][y]!='O')
                {
                    printf("\nYOUR PIECE HAS BECOME A KING! \n");
                    board[x][y]='O';
                }
                return 1;
        }
    }
    else if(board[row][col]=='X' || board[row][col]=='O')
    {
        if(board[row+1][col+1]=='-')
        {
            option++;
            printf("%d%d    " , row+1,col+1);
        }
        if(board[row+1][col-1]=='-')
        {
            option++;
            printf("%d%d    " ,row+1,col-1);
        }
        if(board[row-1][col-1]=='-')
        {
            option++;
            printf("%d%d    " , row-1,col-1);
        }
        if(board[row-1][col+1]=='-')
        {
            option++;
            printf("%d%d    " , row-1,col+1);
        }
        char ch[2];
        if(option==0)
        {
            printf("No moves possible for this piece.TRY AGAIN!\n");
            return 0;
        }
        printf("\n\n");
        printf("Where do you want to move your piece \n");
        printf("Add row no.\n");
        scanf("%s" , &ch[0]);
        printf("Add column no.\n");
        scanf("%s" , &ch[1]);
        if((ch[0]>'8'||ch[0]<'1')||(ch[1]>'8'||ch[1]<'1'))
        {
            printf("Wrong coordinates. TRY AGAIN! \n");
            goto jump1;
        }
        int x,y;
        fi(0,10)
        {
            if(ch[0]==w[i])
            {
                x=i;
            }
            if(ch[1]==w[i])
            {
                y=i;
            }
        }
            if((x==row-1 && y==col-1)||(x==row-1 && y==col+1)||(x==row+1 && y==col+1)||(x==row+1 && y==col-1))
            {
                int ok;
                ok=0;
            }
            else
            {
                printf("Wrong move TRY AGAIN! \n");
                goto jump1;
            }
            swapi(board,row,col,x,y);
            return 1;
    }
}
//this function checks if any pieces are at attacking position or not and prints the coordinates of the pieces which are getting attacked and which are attacking.
void check_for_attack(char board[][BOARD_SIZE],int n)
{
    att=0;
    if(n==1)
    {
        fi(1,9)
        {
            fj(1,9)
            {
                if(board[i][j]=='x')
                {
                    if(board[i+1][j+1]=='o'||board[i+1][j+1]=='O')
                    {
                        if(board[i+2][j+2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i+1,j+1);
                            att=1;
                        }
                    }
                    if(board[i+1][j-1]=='o'||board[i+1][j-1]=='O')
                    {
                        if(board[i+2][j-2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i+1,j-1);
                            att=1;
                        }
                    }
                }
                else if(board[i][j]=='X')
                {
                    if(board[i+1][j+1]=='o'||board[i+1][j+1]=='O')
                    {
                        if(board[i+2][j+2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i+1,j+1);
                            att=1;
                        }
                    }
                    if(board[i+1][j-1]=='o'||board[i+1][j-1]=='O')
                    {
                        if(board[i+2][j-2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i+1,j-1);
                            att=1;
                        }
                    }
                    if(board[i-1][j-1]=='o'||board[i-1][j-1]=='O')
                    {
                        if(board[i-2][j-2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i-1,j-1);
                            att=1;
                        }
                    }
                    if(board[i-1][j+1]=='o'||board[i-1][j+1]=='O')
                    {
                        if(board[i-2][j+2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i-1,j+1);
                            att=1;
                        }
                    }
                }
            }
        }
    }
    if(n==2)
    {
        fi(1,9)
        {
            fj(1,9)
            {
                if(board[i][j]=='o')
                {
                    if(board[i-1][j-1]=='x'||board[i-1][j-1]=='X')
                    {
                        if(board[i-2][j-2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i-1,j-1);
                            att=1;
                        }
                    }
                    if(board[i-1][j+1]=='x'||board[i-1][j+1]=='X')
                    {
                        if(board[i-2][j+2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i-1,j+1);
                            att=1;
                        }
                    }
                }
                else if(board[i][j]=='O')
                {
                    if(board[i+1][j+1]=='x'||board[i+1][j+1]=='X')
                    {
                        if(board[i+2][j+2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i+1,j+1);
                            att=1;

                        }
                    }
                    if(board[i+1][j-1]=='x'||board[i+1][j-1]=='X')
                    {
                        if(board[i+2][j-2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i+1,j-1);
                            att=1;

                        }
                    }
                    if(board[i-1][j-1]=='x'||board[i-1][j-1]=='X')
                    {
                        if(board[i-2][j-2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i-1,j-1);
                            att=1;

                        }
                    }
                    if(board[i-1][j+1]=='x'||board[i-1][j+1]=='X')
                    {
                        if(board[i-2][j+2]=='-')
                        {
                            printf("%d%d CAN ATTACK %d%d!\n" ,i,j,i-1,j+1);
                            att=1;

                        }
                    }

                }
            }
        }
    }

}
//this function is used to attack. If there are multiple attacks possible from one piece then this function gives you option to attack.
void attack(char coord[2],char board[][BOARD_SIZE],int n)
{
    char w[]="0123456789";
    int row,col,x,y;

    jump2:

    fi(0,10)
    {
        if(coord[0]==w[i])
        {
            row=i;
        }
        if(coord[1]==w[i])
        {
            col=i;
        }
    }


    if(att==1)
    {
        if(n==1)
        {
            if(board[row][col]=='x')
            {
                if((board[row+1][col+1]=='o' || board[row+1][col+1]=='O') && board[row+2][col+2]=='-')
                {
                    printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,row+2,col+2);
                    board[row+1][col+1]='-';
                    if(row+2==8 && board[row+2][col+2]!='X')
                    {
                        printf("\nYOUR PIECE HAS BECOME A KING! \n");
                        board[row+2][col+2]='X';
                    }
                }
                else if((board[row+1][col-1]=='o'||board[row+1][col-1]=='O') && board[row+2][col-2]=='-')
                {
                    printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,row+2,col-2);
                    board[row+1][col-1]='-';
                    if(row+2==8 && board[row+2][col-2]!='X')
                    {
                        printf("\nYOUR PIECE HAS BECOME A KING! \n");
                        board[row+2][col-2]='X';
                    }
                }
                else
                {
                    printf("You can only select the attacking piece. TRY AGAIN! \n");
                    jump3:
                    printf("Add row no. \n");
                    scanf("%s" ,&coord[0]);
                    printf("Add column no. \n");
                    scanf("%s" ,&coord[1]);
                    if(check_for_command(coord,board,n)==1)
                    {
                        printf("Wrong coordinates. TRY AGAIN! \n");
                        goto jump3;
                    }
                    goto jump2;

                }
            }
            else if(board[row][col]=='X')
            {
                att=0; int sign1,sign2;
                if((board[row+1][col+1]=='o' || board[row+1][col+1]=='O') && board[row+2][col+2]=='-')
                {
                    att++;
                    sign1=0;
                    sign2=0;
                }
                else if((board[row+1][col-1]=='o'||board[row+1][col-1]=='O') && board[row+2][col-2]=='-')
                {
                    att++;
                    sign1=0;
                    sign2=1;
                }
                else if((board[row-1][col-1]=='o' || board[row-1][col-1]=='O') && board[row-2][col-2]=='-')
                {
                    att++;
                    sign1=1;
                    sign2=1;
                }
                else if((board[row-1][col+1]=='o' || board[row-1][col+1]=='O') && board[row-2][col+2]=='-')
                {
                    att++;
                    sign1=1;
                    sign2=0;
                }
                else
                {
                    printf("You can only select the attacking piece. TRY AGAIN! \n");
                    jump4:
                    printf("Add row no. \n");
                    scanf("%s" ,&coord[0]);
                    printf("Add column no. \n");
                    scanf("%s" ,&coord[1]);
                    if(check_for_command(coord,board,n)==1)
                    {
                        printf("Wrong coordinates. TRY AGAIN! \n");
                        goto jump4;
                    }
                    goto jump2;

                }
                if(att>1)
                {
                    printf("There are multiple ATTACKS possible , where do you want to move your piece \n");
                    char dead[2];
                    printf("Add row no.\n");
                    scanf("%s" , &dead[0]);
                    printf("Add column no.\n");
                    scanf("%s" , &dead[1]);
                    fi(0,10)
                    {
                        if(dead[0]==w[i])
                        {
                            x=i;
                        }
                        if(dead[1]==w[i])
                        {
                            y=i;
                        }
                    }
                    printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,x,y);
                    board[(x+row)/2][(y+col)/2]='-';
                }
                else if(att==1)
                {
                    printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,row+(2*pow(-1,sign1)),col+(2*pow(-1,sign2)));
                    int row_1=row+pow(-1,sign1) , col_1=col+pow(-1,sign2);
                    board[row_1][col_1]='-';
                }
            }

        }
        if(n==2)
        {
            if(board[row][col]=='o')
            {
                if((board[row-1][col-1]=='x' || board[row-1][col-1]=='X') && board[row-2][col-2]=='-')
                {
                    printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,row-2,col-2);
                    board[row-1][col-1]='-';
                    if(row-2==1 && board[row-2][col-2]!='O')
                    {
                        printf("\nYOUR PIECE HAS BECOME A KING! \n");
                        board[row-2][col-2]='X';
                    }
                }
                else if((board[row-1][col+1]=='x' || board[row-1][col+1]=='X') && board[row-2][col+2]=='-')
                {
                   printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,row-2,col+2);
                    board[row-1][col+1]='-';
                    if(row-2==1 && board[row-2][col+2]!='O')
                    {
                        printf("\nYOUR PIECE HAS BECOME A KING! \n");
                        board[row-2][col+2]='X';
                    }
                }
                else
                {
                    printf("You can only select the attacking piece. TRY AGAIN! \n");
                    jump5:
                    printf("Add row no. \n");
                    scanf("%s" ,&coord[0]);
                    printf("Add column no. \n");
                    scanf("%s" ,&coord[1]);
                    if(check_for_command(coord,board,n)==1)
                    {
                        printf("Wrong coordinates. TRY AGAIN! \n");
                        goto jump5;
                    }
                    goto jump2;

                }
            }
            else if(board[row][col]=='O')
            {
                att=0; int sign1,sign2;
                if((board[row+1][col+1]=='x' || board[row+1][col+1]=='X') && board[row+2][col+2]=='-')
                {
                    att++;
                    sign1=0;
                    sign2=0;
                }
                else if((board[row+1][col-1]=='x'||board[row+1][col-1]=='X') && board[row+2][col-2]=='-')
                {
                    att++;
                    sign1=0;
                    sign2=1;
                }
                else if((board[row-1][col-1]=='x' || board[row-1][col-1]=='X') && board[row-2][col-2]=='-')
                {
                    att++;
                    sign1=1;
                    sign2=1;
                }
                else if((board[row-1][col+1]=='x' || board[row-1][col+1]=='X') && board[row-2][col+2]=='-')
                {
                    att++;
                    sign1=1;
                    sign2=0;
                }
                else
                {
                    printf("You can only select the attacking piece. TRY AGAIN! \n");
                    jump6:
                    printf("Add row no. \n");
                    scanf("%s" ,&coord[0]);
                    printf("Add column no. \n");
                    scanf("%s" ,&coord[1]);
                    if(check_for_command(coord,board,n)==1)
                    {
                        printf("Wrong coordinates. TRY AGAIN! \n");
                        goto jump6;
                    }
                    goto jump2;

                }
                if(att>1)
                {
                    printf("There are multiple ATTACKS possible , where do you want to move your piece \n");
                    char dead[2];
                    printf("Add row no.\n");
                    scanf("%s" , &dead[0]);
                    printf("Add column no.\n");
                    scanf("%s" , &dead[1]);
                    fi(0,10)
                    {
                        if(dead[0]==w[i])
                        {
                            x=i;
                        }
                        if(dead[1]==w[i])
                        {
                            y=i;
                        }
                    }
                    printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,x,y);
                    board[(x+row)/2][(y+col)/2]='-';
                }
                else if(att==1)
                {
                    printf("\n\n      ATTACK! \n");
                    swapi(board,row,col,row+(2*pow(-1,sign1)),col+(2*pow(-1,sign2)));
                    int row_1=row+pow(-1,sign1) , col_1=col+pow(-1,sign2);
                    board[row_1][col_1]='-';
                }
            }

        }

    }

}

//counts the number of pieces after each move.
void count(char board[][BOARD_SIZE])
{
    n1=0;n2=0;
    fi(1,9)
    {
        fj(1,9)
        {
            if(board[i][j]=='x'||board[i][j]=='X')
            {
                n1++;
            }
            if(board[i][j]=='o'||board[i][j]=='O')
            {
                n2++;
            }
        }
    }
}
//prints the board.
void printBoard(char board[][BOARD_SIZE])
{
    int i, j;

    printf("  ");
    for (i = 1; i < BOARD_SIZE-1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 1; i < BOARD_SIZE-1; i++)
    {
        printf("%d ", i);
        for (j = 1; j < BOARD_SIZE-1; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int start=0;
    printf("*   *  *****  *      *****  *****    *   *   **** \n");
    printf("*   *  *      *      *      *   *   * * * *  *    \n");
    printf("* * *  ***    *      *      *   *   *  *  *  ***  \n");
    printf("* * *  *      *      *      *   *   *     *  *    \n");
    printf("* * *  *****  *****  *****  *****   *     *  **** \n");

    printf("TO CHECKERS! \n");
    while(start==0)
    {
        printf("Press 1 if you would like to start the game \n");
        printf("Press 2 if you are not familiar with the rules of checkers \n");
        int rep;
        scanf("%d" , &rep);
        if(rep==1)
        {
            break;
        }
        if(rep==2)
        {
            ShellExecute(NULL, "open", "https://www.wikihow.com/Play-Checkers", NULL, NULL, SW_SHOWNORMAL);

        }
    }
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    char p1[1],p2[1];
    // Initialize the board
    fi(0,BOARD_SIZE)
    {
        fj(0,BOARD_SIZE)
        {
            board[i][j]='p';
        }
    }
    for (i = 1; i < BOARD_SIZE-1; i++) {
        for (j = 1; j < BOARD_SIZE-1; j++) {
            // Populate board with empty spaces
            board[i][j] = '-';
        }
    }

    // Set initial positions for pieces
    for (i = 1; i < BOARD_SIZE-1; i += 2) {
        board[1][i+1] = 'x'; // 'x' represents black pieces
        board[2][i] = 'x';
        board[3][i+1] = 'x';
        board[6][i] = 'o'; // 'o' represents white pieces
        board[7][i+1] = 'o';
        board[8][i] = 'o';
    }

    // Print the board
    printBoard(board);


    //GAME//
    m=0;
    time_t start_time , end_time;
    double p1_time=0.0 , p2_time=0.0;
    double elapsed_time;
    while(p1_time<timee && p2_time<timee)
    {
        att=0;
        count(board);
        if(n1==0)
        {
            printf("PLAYER 2 WINS! \n");
            break;
        }
        if(n2==0)
        {
            printf("PLAYER 1 WINS! \n");
            break;
        }
        if(m%2==0)
        {
            //Player 1 turn:
            printf("\nPlayer 1's turn \n");
            char coord[2];
            att=0;
            check_for_attack(board,1);

            start_time = time(NULL);
            //choose
            printf("Add row no.\n");
            scanf(" %c", &coord[0]);
            printf("Add column no.\n");
            scanf(" %c", &coord[1]);
            if(check_for_command(coord,board,1)==1)
            {
                printf("Wrong coordinates TRY AGAIN! \n");
                continue;
            }
            if(att!=0)
            {
                attack(coord,board,1);
            }
            else
            {
                if(move(coord,board,1)==0)
                {
                    continue;
                }

            }

            end_time=time(NULL);
            elapsed_time=difftime(end_time , start_time);
            p1_time=p1_time+elapsed_time;
            printBoard(board);
            printf("\nThe time elapsed for Player 1 is:- %lf ", p1_time);
            m++;
            printf("\n");
        }
        else if(m%2==1)
        {
            //player 2 turn
            printf("\nPlayer 2's turn \n");
            char coord[2];
            att=0;
            check_for_attack(board,2);

            start_time = time(NULL);
            //choose
            printf("Add row no.\n");
            scanf(" %c", &coord[0]);
            printf("Add column no.\n");
            scanf(" %c", &coord[1]);

            if(check_for_command(coord,board,2)==1)
            {
                printf("Wrong coordinates TRY AGAIN! \n");
                continue;
            }
            if(att!=0)
            {
                attack(coord,board,2);
            }
            else
            {
                if(move(coord,board,2)==0)
                {
                    continue;
                }
            }
            end_time=time(NULL);
            elapsed_time=difftime(end_time , start_time);
            p2_time=p2_time+elapsed_time;
            printBoard(board);
            printf("\nThe time elapsed for Player 2 is:- %lf ", p2_time);
            m++;
            printf("\n");
        }
    }
    if(p1_time>timee)
    {
        printf("              PLAYER 2 HAS WON BY TIME \n");
    }
    else if(p2_time>timee)
    {
        printf("              PLAYER 1 HAS WON BY TIME \n");
    }


    return 0;
}
