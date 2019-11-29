/*
7. Queries

R A B C
1 56 67 89
2 89 54 90
3 78 91 83
4 69 72 95
R – Rollno, A, B, C – Marks in three subjects
Given the above matrix, print the result of the queries given the following syntax.
The first input string has a single character denoting the field to be printed.
* – All fields of the selected rows
A – Print only field A
B – Print only field B
C – Print only field C

The second string contains the condition – <field><relational_operator><value>.
> – Greater than
< – Less than
= – Equal to

I/P: *
A>70

O/P:

2 89 54 90
3 78 91 83
4 69 72 95

I/P: A
C<90

O/P:


56
78
*/


#include <stdio.h>

struct student
{
    int R;
    int A,B,C;
};

int main(int argc, char const *argv[])
{
    int n = 4;
    struct student students[n];

    students[0].R = 1; students[0].A = 54; students[0].B = 67; students[0].C = 89;
    students[1].R = 2; students[1].A = 89; students[1].B = 54; students[1].C = 90;
    students[2].R = 3; students[2].A = 78; students[2].B = 91; students[2].C = 83;
    students[3].R = 4; students[3].A = 69; students[3].B = 72; students[3].C = 95;


    char field;
    char reloperator;
    int value;

    scanf("%c%c%d",&field,&reloperator,&value);
    // printf("%c %c %d\n",field,reloperator,value);

    if (reloperator == '>')
    {
        switch (field)
        {
            case 'A':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].A > value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;

            case 'B':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].B > value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;

            case 'C':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].A > value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;
            
            default:
                break;
        }
        
    } else if (reloperator == '<') 
    {
        switch (field)
        {
            case 'A':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].A < value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;

            case 'B':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].B < value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;

            case 'C':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].A < value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;
            
            default:
                break;
        }
    } else if (reloperator == '=')
    {
        switch (field)
        {
            case 'A':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].A == value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;

            case 'B':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].B == value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;

            case 'C':
                for (int i = 0; i < n; i++)
                {
                    if (students[i].A == value) {
                        printf("%d %d %d %d\n",students[i].R,students[i].A,students[i].B,students[i].C);
                    }
                }
                break;
            
            default:
                break;
        }
        
    } else {
        printf("Invalid <field><relational_operator><value> provided in input\n");
    }
    
    return 0;
}
