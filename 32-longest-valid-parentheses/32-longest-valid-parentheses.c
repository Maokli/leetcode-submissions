typedef struct node {
    int val;
    struct node* next;
} node;

typedef node* stack;

stack push(stack s, int c)
{
    stack nv = malloc(sizeof(node));
    nv->val = c;
    nv->next = s;
    
    return nv;
}

stack pop(stack s)
{
    if(s == NULL) return s;
    
    stack temp = s;
    s = s->next;
    free(temp);
    
    return s;
}

int top(stack s)
{
    return s->val;
}

int longestValidParentheses(char * s){
    stack st = NULL;
    int i, len = strlen(s), maxValid = 0;
    st = push(st,-1);
    for(i = 0; i<len;i++)
    {   
        if(*(s+i) == '(') st = push(st,i);
        
        if(*(s+i) == ')')
        {
            
            st = pop(st);
            if(st == NULL)
            {
                st = push(st,i);
            }
            else
            {
                maxValid = i - top(st) > maxValid ? i - top(st) : maxValid;
            }
                
        }
        
    }
    
    return maxValid;

}