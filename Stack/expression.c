#include "expression.h"

void Init(SqStack** Stack){
    *Stack = (SqStack*)malloc(sizeof(SqStack));
    (*Stack)->top = -1;
}

bool Push(SqStack* Stack, ElemType e){
    if(Stack->top == MaxSize - 1)
        return false;
    Stack->data[++(Stack->top)] = e;
    return true;
}
bool Pop(SqStack* Stack, ElemType* e){
    if(Stack->top == -1)
        return false;
    *e = Stack->data[(Stack->top)--];
    return true;
}
bool GetTop(SqStack* Stack, ElemType* e){
    if(Stack->top == -1)
        return false;
    *e = Stack->data[Stack->top];
    return true;
}

// Transmit infix to sufix
bool Transmit(char from[], char to[]){
    int i,j;
    i = j = 0;
    SqStack* Optr;
    Init(&Optr);
    int op;
    while(from[i] != '\0' && from [i] != '\n'){
        if(from[i] >= '0' && from[i] <= '9'){
            to[j++] = from[i++];
        }
        else{
            to[j++] = ' ';
            switch(from[i]){
                case '(':
                    if(!Push(Optr, from[i]))
                        return false;
                    break;
                case ')':
                    while(Pop(Optr, &op)){
                        if(op == '(')
                            break;
                        to[j++] = op;
                    }
                    if(op != '(')
                        return false;
                    break;
                case '*':
                    if(!GetTop(Optr, &op)){
                        Push(Optr, from[i]);
                        break;
                    }
                    if(op == '+' ||op == '-'){
                        Push(Optr, from[i]);
                    }
                    else{
                        while(GetTop(Optr, &op)){
                            if(op == '*' || op == '/'){
                                Pop(Optr, &op);
                                to[j++] = op;
                            }
                            else
                                break;
                        }
                        Push(Optr, from[i]);
                    }
                    break;
                case '/':
                    if(!GetTop(Optr, &op)){
                        Push(Optr, from[i]);
                        break;
                    }
                    if(op == '+' ||op == '-'){
                        Push(Optr, from[i]);
                    }
                    else{
                        while(GetTop(Optr, &op)){
                            if(op == '*' || op == '/'){
                                Pop(Optr, &op);
                                to[j++] = op;
                            }
                            else
                                break;
                        }
                        Push(Optr, from[i]);
                    }
                    break;
                case '+':
                    if(!GetTop(Optr, &op)){
                        Push(Optr, from[i]);
                        break;
                    }
                    while(GetTop(Optr, &op)){
                        if(op == '(')
                            break;
                        else{
                            Pop(Optr, &op);
                            to[j++] = op;
                        }
                    }
                    Push(Optr, from[i]);
                    break;
                case '-':
                    if(!GetTop(Optr, &op)){
                        Push(Optr, from[i]);
                        break;
                    }
                    while(GetTop(Optr, &op)){
                        if(op == '(')
                            break;
                        else{
                            Pop(Optr, &op);
                            to[j++] = op;
                        }
                    }
                    Push(Optr, from[i]);
                    break;
            }
            i++;
        }
    }
    while(Pop(Optr, &op)){
        to[j++] = op;
    }
    to[j] = '\0';
    return true;
}

// Calculate the expression
bool Calculate(char exp[], ElemType* ans){
    int i = 0;
    int a, b;
    SqStack* num;
    Init(&num);
    int sum = 0;
    while(exp[i] != '\0'){
        if(exp[i] >= '0' && exp[i] <= '9'){
            sum = sum*10 + exp[i] - '0';
        }
        else{
            if(sum){
                Push(num, sum);
                sum = 0;
            }
            switch(exp[i]){
                case '+':
                    Pop(num, &b);
                    Pop(num, &a);
                    Push(num, a+b);
                    break;
                case '-':
                    Pop(num, &b);
                    Pop(num, &a);
                    Push(num, a-b);
                    break;
                case '*':
                    Pop(num, &b);
                    Pop(num, &a);
                    Push(num, a*b);
                    break;
                case '/':
                    Pop(num, &b);
                    Pop(num, &a);
                    Push(num, a/b);
                    break;
            }
        }
        i++;
    }
    Pop(num, ans);
    return true;
}