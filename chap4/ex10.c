#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define VARIABLE 'V'
int getop(char s[], char line[]);
void push(double);
double pop(void);
int sp = 0;
double val[MAXVAL];
double var[26];
int varSign[26];
int mgetline(char s[], int lim);

main()
{
    int type;
    double op2, op3;
    char s[MAXOP];
    char line[MAXVAL];
    while (mgetline(line, MAXVAL)) {
        while((type = getop(s, line)) != '\0') {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case VARIABLE:
                    if(varSign[s[0]-'A'])
                        push(var[s[0]-'A']);
                    else {
                        varSign[s[0]-'A'] = 1;
                        if (sp > 0)
                            var[s[0]-'A'] = pop();
                        else
                            return -1;
                    }
                        
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
                    push((int)pop() % (int)op2);
                    break;
                case 't': // command t for print the top element of stack.
                    if (sp > 0)
                        printf("top element : %f\n", val[sp-1]);
                    else
                        printf("error: stack empty\n");
                    break;
                case 's': // command s for swap the top two elements.
                    op2 = pop();
                    op3 = pop();
                    push(op2);
                    push(op3);
                    break;
                case 'd': // command d for duplicate the top element.
                    op2 = pop();
                    push(op2);
                    push(op2);
                    break;
                case 'c': // command c for clean the stack.
                    sp = 0;
                    break;
                case 'a': //command a for sin operate
                    push(sin(pop()));
                    break;
                case 'e': //command e for exp operate
                    push(exp(pop()));
                    break;
                case '^': //command ^ for pow operate
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %s \n", s);
                    break;
            }
        }
    }
    return 0; 
}


void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>


int mgetline(char s[], int lim)
{  
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
int li;
int getop(char s[], char line[])
{
    int j = 0;

    while((s[0] = line[li++]) == ' ' || s[0] == '\t')
        ;
    if (s[0] == '\0')
        return '\0';
    s[1] = '\0';
    if (!isdigit(s[0]) && s[0] != '.' && s[0] != '-' && !isupper(s[0]))
        return s[0];
    if(isupper(s[0]))
        return VARIABLE;

    if (s[0] == '-' && !isdigit(line[li])) 
        return '-';
    
    if (isdigit(s[0]) || s[0] == '-')
        while (isdigit(s[++j] = line[li++]))
            ;
    if (s[j] == '.')
        while (isdigit(s[++j] = line[li++]))
            ;
    s[j] = '\0';
    li--;
    return NUMBER;
}
