/*
	This is a test header.
*/

#include<stdio.h>
#include<windows.h>
#include<math.h>

int fFace[10][10];
int rFace[10][10];
int lFace[10][10];
int uFace[10][10];
int dFace[10][10];
int bFace[10][10];

//   ^1
// 2< >3
// 4< >5
//   v6

void resetCube(void);
void displayCube(int);
void setColor(int,int);
void uTurn(int,int);
void rTurn(int,int);
void bTurn(int,int);
void rotate(int,int(*)[10]);

int main(void)
{
    char input;
    int curAxis=1;

    resetCube();

    do
    {
        system("cls");
        displayCube(curAxis);
        input=getch();
        switch(input)
        {
        case 'w':case 'W':
            curAxis=1;
            break;
        case 'q':case 'Q':
            curAxis=2;
            break;
        case 'e':case 'E':
            curAxis=3;
            break;
        case 'a':case 'A':
            curAxis=4;
            break;
        case 'd':case 'D':
            curAxis=5;
            break;
        case 's':case 'S':
            curAxis=6;
            break;
        case 'o':
            rotate(1,fFace);
            break;
        case 'p':
            rotate(-1,fFace);
            break;
        }
        if(input>=48&&input<=57)
        {
            switch(curAxis)
            {
            case 1:
                uTurn(1,(input-39)%10);
                break;
            case 2:
                bTurn(-1,(input-39)%10);
                break;
            case 3:
                bTurn(1,(input-39)%10);
                break;
            case 4:
                rTurn(-1,(input-39)%10);
                break;
            case 5:
                rTurn(1,(input-39)%10);
                break;
            case 6:
                uTurn(-1,(input-39)%10);
                break;
            }
        }
    }
    while(input!=27);

    return 0;
}

void resetCube(void)
{
    int i,j;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            fFace[i][j]=1;
            rFace[i][j]=2;
            lFace[i][j]=3;
            uFace[i][j]=4;
            dFace[i][j]=5;
            bFace[i][j]=6;
        }
    }
}

void displayCube(int selectedAxis)
{
    int i,j;
    int colorList[6]={15,12,6,9,10,14};

    setColor(15,0);
    printf("\n\n\t            ");
    if(selectedAxis==1)
    {
        setColor(0,15);
    }
    printf("1234567890");
    setColor(15,0);
    printf(" \n");
    for(i=0;i<10;i++)
    {
        printf("\t           ");
        if(selectedAxis==2)
        {
            setColor(0,15);
        }
        else
        {
            setColor(15,0);
        }
        printf("%i",(i+1)%10);
        for(j=0;j<10;j++)
        {
            setColor(colorList[uFace[i][j]-1],0);
            printf("%c",219);
        }
        if(selectedAxis==3)
        {
            setColor(0,15);
        }
        else
        {
            setColor(15,0);
        }
        printf("%i",(i+1)%10);
        setColor(15,0);
        printf(" \n");
    }

    if(selectedAxis==3)
    {
        setColor(0,15);
    }
    else
    {
        setColor(15,0);
    }
    printf("\t 1234567890");
    setColor(15,0);
    printf("            ");
    if(selectedAxis==2)
    {
        setColor(0,15);
    }
    else
    {
        setColor(15,0);
    }
    printf("0987654321");
    setColor(15,0);
    printf(" ");
    if(selectedAxis==6)
    {
        setColor(0,15);
    }
    else
    {
        setColor(15,0);
    }
    printf("0987654321");
    setColor(15,0);
    printf(" \n");

    for(i=0;i<10;i++)
    {
        if(selectedAxis==4)
        {
            setColor(0,15);
        }
        else
        {
            setColor(15,0);
        }
        printf("\t%i",(i+1)%10);
        for(j=0;j<10;j++)
        {
            setColor(colorList[lFace[i][j]-1],0);
            printf("%c",219);
        }
        setColor(15,0);
        printf(" ");
        for(j=0;j<10;j++)
        {
            setColor(colorList[fFace[i][j]-1],0);
            printf("%c",219);
        }
        setColor(15,0);
        printf(" ");
        for(j=0;j<10;j++)
        {
            setColor(colorList[rFace[i][j]-1],0);
            printf("%c",219);
        }
        setColor(15,0);
        printf(" ");
        for(j=0;j<10;j++)
        {
            setColor(colorList[bFace[i][j]-1],0);
            printf("%c",219);
        }
        if(selectedAxis==5)
        {
            setColor(0,15);
        }
        else
        {
            setColor(15,0);
        }
        printf("%i",(i+1)%10);
        setColor(15,0);
        printf(" \n");
    }

    if(selectedAxis==2)
    {
        setColor(0,15);
    }
    else
    {
        setColor(15,0);
    }
    printf("\t 1234567890");
    setColor(15,0);
    printf("            ");
    if(selectedAxis==3)
    {
        setColor(0,15);
    }
    else
    {
        setColor(15,0);
    }
    printf("0987654321");
    setColor(15,0);
    printf(" ");
    if(selectedAxis==1)
    {
        setColor(0,15);
    }
    else
    {
        setColor(15,0);
    }
    printf("0987654321");
    setColor(15,0);
    printf(" \n");

    for(i=0;i<10;i++)
    {
        printf("\t           ");
        if(selectedAxis==3)
        {
            setColor(0,15);
        }
        else
        {
            setColor(15,0);
        }
        printf("%i",(i+1)%10);
        for(j=0;j<10;j++)
        {
            setColor(colorList[dFace[i][j]-1],0);
            printf("%c",219);
        }
        if(selectedAxis==2)
        {
            setColor(0,15);
        }
        else
        {
            setColor(15,0);
        }
        printf("%i",(i+1)%10);
        setColor(15,0);
        printf(" \n");
    }
    printf("\t            ");
    if(selectedAxis==6)
    {
        setColor(0,15);
    }
    printf("1234567890");
    setColor(15,0);
    printf(" \n");
}

void uTurn(int coeff,int piece)
{
    int i,j;
    int temp[10];

    if(coeff==1)
    {
        for(i=0;i<10;i++)
        {
            temp[i]=uFace[i][piece];
            uFace[i][piece]=fFace[i][piece];
            fFace[i][piece]=dFace[i][piece];
            dFace[i][piece]=bFace[9-i][9-piece];
            bFace[9-i][9-piece]=temp[i];
        }
        if(piece==0)
        {
            rotate(1,lFace);
        }
        else if(piece==9)
        {
            rotate(-1,rFace);
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            temp[i]=dFace[i][piece];
            dFace[i][piece]=fFace[i][piece];
            fFace[i][piece]=uFace[i][piece];
            uFace[i][piece]=bFace[9-i][9-piece];
            bFace[9-i][9-piece]=temp[i];
        }
        if(piece==0)
        {
            rotate(-1,lFace);
        }
        else if(piece==9)
        {
            rotate(1,rFace);
        }
    }
}

void rTurn(int coeff,int piece)
{
    int i,j;
    int temp[10];

    if(coeff==1)
    {
        for(i=0;i<10;i++)
        {
            temp[i]=fFace[piece][i];
            fFace[piece][i]=lFace[piece][i];
            lFace[piece][i]=bFace[piece][i];
            bFace[piece][i]=rFace[piece][i];
            rFace[piece][i]=temp[i];
        }
        if(piece==0)
        {
            rotate(1,uFace);
        }
        else if(piece==9)
        {
            rotate(-1,dFace);
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            temp[i]=fFace[piece][i];
            fFace[piece][i]=rFace[piece][i];
            rFace[piece][i]=bFace[piece][i];
            bFace[piece][i]=lFace[piece][i];
            lFace[piece][i]=temp[i];
        }
        if(piece==0)
        {
            rotate(-1,uFace);
        }
        else if(piece==9)
        {
            rotate(1,dFace);
        }
    }
}

void bTurn(int coeff,int piece)
{
    int i,j;
    int temp[10];

    if(coeff==1)
    {
        for(i=0;i<10;i++)
        {
            temp[i]=rFace[i][9-piece];
            rFace[i][9-piece]=uFace[piece][i];
            uFace[piece][i]=lFace[9-i][piece];
            lFace[9-i][piece]=dFace[9-piece][9-i];
            dFace[9-piece][9-i]=temp[i];
        }
        if(piece==0)
        {
            rotate(1,bFace);
        }
        else if(piece==9)
        {
            rotate(-1,fFace);
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            temp[i]=lFace[9-i][piece];
            lFace[9-i][piece]=uFace[piece][i];
            uFace[piece][i]=rFace[i][9-piece];
            rFace[i][9-piece]=dFace[9-piece][9-i];
            dFace[9-piece][9-i]=temp[i];
        }
        if(piece==0)
        {
            rotate(-1,bFace);
        }
        else if(piece==9)
        {
            rotate(1,fFace);
        }
    }
}

void rotate(int coeff,int(*face)[10])
{
    int i,j;
    int tempFace[10][10];

    if(coeff==1)
    {
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                tempFace[i][j]=face[j][9-i];
            }
        }
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                face[i][j]=tempFace[i][j];
            }
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                tempFace[i][j]=face[9-j][i];
            }
        }
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                face[i][j]=tempFace[i][j];
            }
        }
    }
}

void setColor(int fg,int bg)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,fg+(bg*16));
}


