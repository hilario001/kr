/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in 
Appendix B, Section 4. */
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define VARIABLE 'a'

int getop(char []);
void push(double);
double pop(void);
double top(void);
void swap(void);
void clear(void);
void dupl(void);
void powr(void);
void expo(void);
void sine(void);
void retrieve(char []);
void assign(void);

double last;

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
                case VARIABLE:
                        retrieve(s);
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
                case '=':
                        assign();
                        break;
                case '\n':
                        last = pop();
                        printf("\t%.8g\n", last);
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
                case '^':
                        powr();
                        break;
                case 'E':
                        expo();
                        break;
                case 'S':
                        sine();
                        break;
                default:
                        printf("error: unknown command %s\n", s);
                        break;
                }
        }
        return 0;
}

#include <math.h>
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
        if (sp)
                return val[sp-1];

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

void powr(void)
{
        double tmp = pop();
        push(pow(pop(), tmp));
}

void expo(void)
{
        push(exp(pop()));
}

void sine(void)
{
        push(sin(pop()));
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
        if (!isdigit(c) && c != '.' && c != '-') {
                if (islower(c))
                        return VARIABLE;
                return c; /* not a number, nor a possible unary minus operator */
        }
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

#define ALPHAB 26               /* for 26 variables */
double var_stack[ALPHAB];       /* variable value stack */
int var_char;                   /* variable character name */

void retrieve(char s[])
{
        var_char = s[0];
        double value = var_stack[var_char - 'a'];

        if (value)
                push(value);
        else {
                printf("error: variable %c is not defined \n", var_char);
                printf("syntax: name value/expression =\n");
        }
}

void assign(void)
{
        var_stack[var_char - 'a'] = top();
}
