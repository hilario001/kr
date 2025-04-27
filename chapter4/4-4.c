/* Exercise 4-4. Add the commands to print the top elements of the stack without
 * popping, to duplicate it, and to swap the top two elements. Add a command to
 * clear the stack. */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double top(void);
void swap(void);
void clear(void);
void dupl(void);

/* reverse Polish calculator  */
int main()
{
        int type;
        double op2;
        char s[MAXOP];

        while ((type = getop(s)) != EOF) {
                switch (type) {
                case NUMBER:
                        push(atof(s));
                        break;
                case '+':
                        push(pop() + pop());
                        break;
                case '-':
                        push(pop() - pop());
                        break;
                case '*':
                        op2 = pop();
                        push(pop() * op2);
                        break;
                case '/':
                        op2 = pop();
                        push(pop() / op2);
                        break;
                case '%':
                        op2 = pop();
                        push((int)pop() % (int)op2);
                        break;
                case '\n':
                        printf("\t%.8g\n", pop());
                        break;
                case '!':
                        clear();
                        break;
                case '?':
                        top();
                        break;
                case '~':
                        swap();
                        break;
                case '#':
                        dupl();
                        break;
                default:
                        printf("error: unknown command %s\n", s);
                        break;
                }
        }
        return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
        if (sp > 0)
                return val[--sp];
        else {
                printf("error: stack empty\n");
                return 0.0;
        }
}

double top(void)
{
        if (sp) {
                printf("Top of stack: %.8g\n", val[sp-1]);
                return val[sp-1];
        }

        printf("error: stack empty\n");
        return 0.0;
}

void swap(void)
{
        if (sp) {
                double tmp1 = pop();
                double tmp2 = pop();
                push(tmp1);
                push(tmp2);
                return;
        }

        printf("error: stack empty\n");
        return;
}

void clear(void)
{
        sp = 0;
}

void dupl(void)
{
        push(top());
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
        int i, c, d;
        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';
        if (!isdigit(c) && c != '.' && c != '-')
                return c; /* not a number, nor a possible unary minus operator */
        i = 0;
        /* if binary minus, return it
         * if unary minus, store the character next to it */
        if (c == '-') {
                d = getch();
                if (!isdigit(d) && d != '.')
                        return c;
                s[++i] = c = d;
        }
        if (isdigit(c)) /* collect integer part */
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.') /* collect fraction part */
                while (isdigit(s[++i] = c = getch()))
                        ;
        s[i] = '\0';
        if (c != EOF)
                ungetch(c);
        return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}

/* Get a character
 * Check if character is a number
 * If character is a minus or addition operator
 *      Check if the next character is a number
 *      If next character is not a number
 *              Return the operator
 *      If next character is a number
 *              Store the next character to the array
 *              
 * */
