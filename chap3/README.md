# NOTE

## 3.1 Statements and Blocks
Block syntactically equivalent to a singe statement.

## 3.2 If-Else
statement := expression with a semicolon e.g. a++;
the else go to the most inner else-less if.

## 3.3 Else-If
remain exercise here

## 3.4 Switch

    switch (expression) {
        case const-expr: statements
        case const-expr: statements
        default: statements
    }
* break;
* const-expr need to be integer.
* we don't need a break statement in default condition logically, but it's better to have one as a matter of a good form.

## Loops - While and For

    for (; expression;) == while(expression)
    for(;;) == while(1)

    p.55's shell sort
    
    comma ',' operator have less precedence than assign '=' operator.

## Loops - Do-While
    do 
        statement
    while (expression);
## Break and Continue
 A break; statement causes the innermost enclosing loop or switch to be exited.
 A continue; statement causes the next iteration of the enclosing for, while, do loop begin.
 in while and do-loop, the test part is executed immediately;
 in the for, control pass to the increment step. 

## Goto and labels
lable名稱與變數名稱格式一樣,可出現在任何statement前
label必須與對應的goto在相同function內
goto能少用則少用

---
## Remain work
* shell sort @ p.55.
* exercise 1 detail.