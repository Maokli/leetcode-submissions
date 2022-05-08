typedef struct node{
    int val;
    struct node* next;
} node;
typedef node* stack;

stack push(stack s, int val)
{
    stack new = malloc(sizeof(node));
    new->val = val;
    new->next = s;
    
    return new;
}

stack pop(stack s)
{
    if(s == NULL) return s;
    
    stack temp = s;
    s = s->next;
    free(temp);
    
    return s;
}

int performOperation(int a, int b, char* operator)
{
    int res = 0;
    switch(*operator) {

       case '+'  :
          res = a+b;
          break; 
       case '-'  :
          res = a-b;
          break;
       case '*'  :
          res = a*b;
          break;  
       case '/'  :
          res = a/b;
          break; 
    }
    
    return res;
}

int power(int n)
{
    if(n == 0) return 1;
    
    return 10*power(n-1);
}
int parseInt(char* s)
{
    int coeff = 1;
    if(*s == '-') {coeff = -1; s++;}
    int i;
    int res = 0;
    for(i=0;i<strlen(s);i++)
    {
        int x = (int)(*(s+i)) - 48;
        res += x*power(strlen(s)-1-i);
    }
    return coeff*res;
}


int evalRPN(char ** tokens, int tokensSize){
    stack s = NULL;
    int i;
    for(i = 0;i<tokensSize;i++)
    {
        if(strcmp(*(tokens+i), "+") == 0 || strcmp(*(tokens+i), "-") == 0 || 
           strcmp(*(tokens+i), "*") == 0 || strcmp(*(tokens+i), "/") == 0 )
        {
            int a = s->val;
            s = pop(s);
            int b = s->val;
            s = pop(s);
            
            int op = performOperation(b,a,*(tokens+i));
            s = push(s,op);
        }else {
            int x = parseInt(*(tokens+i));
            s = push(s,x);
        }
    }
    
    
    return s->val;
    
}