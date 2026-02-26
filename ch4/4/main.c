/*
Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op1;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 == 0.0)
            {
                printf("error: zero divisor\n");
                break;
            }

            op1 = pop();

            double r = fmod(op1, op2);
            if (r < 0)
                r += fabs(op2);
            push(r);
            break;
        case 'p':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case 'c':
            clearstack();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i = 0, c;

    while ((s[i] = c = getch()) == ' ' || c == '\t')
        ;

    // In case it's an operator
    s[++i] = '\0';

    if (!isdigit(c) && c != '.')
    {
        if (c == '-')
        {
            c = getch();                 // peek
            if (!isdigit(c) && c != '.') // operator
            {
                ungetch(c);
                return '-';
            }
            s[i++] = c; // sign
        }
        else
            return c; // operator
    }

    if (isdigit(c))
        while (isdigit(s[i++] = c = getch()))
            ;

    if (c == '.')
    {
        s[i++] = c;
        while (isdigit(s[i++] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void clearstack()
{
    sp = 0;
}