#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left, *right;
};

void explore(struct Node *root)
{
    if (root == NULL) 
    { 
        return; 
    }
    else
    {  
        printf(" %d ", root->value);
        explore(root->left);
        explore(root->right);
    }
}

int main() 
{
    
    int last = 0, current = 0;
    struct Node *root, *pleft, *pright, *list[2000];
    int n = 0;
   
    // root value input
    printf("root value? ");
    scanf("%d", &n);
    
    // Create root node
    root = (struct Node *) malloc (sizeof (struct Node));
    root->value = n;
    root->left = NULL;
    root->right = NULL;
    
    // Initialize list with root
    list[0] = root;
    current = 0;
    last = 0;
   
    // Binary tree construction
    while (1)
    {
        if (current > last) 
        { 
            break; 
        }
       
        // Check if current node is marked as -99
        if (list[current]->value == -99) 
        { 
            current++; 
            continue; 
        }
       
        // Create left and right child nodes
        pleft = (struct Node *) malloc (sizeof (struct Node));
        pright = (struct Node *) malloc (sizeof (struct Node));
       
        // Input left child value
        printf("left of %d? ", list[current]->value);
        scanf("%d", &n);
        pleft->value = n;  
        pleft->left = NULL; 
        pleft->right = NULL;
       
        // Input right child value
        printf("right of %d? ", list[current]->value);
        scanf("%d", &n);
        pright->value = n;   
        pright->left = NULL; 
        pright->right = NULL;
       
        // Assign left and right child nodes to current node
        if (pleft->value == -99) 
        { 
            list[current]->left = NULL; 
        }
        else 
        { 
            list[current]->left = pleft; 
        }
        if (pright->value == -99) 
        { 
            list[current]->right = NULL; 
        }
        else 
        { 
            list[current]->right = pright; 
        }
       
        // Add left and right child nodes to list
        list[last+1] = pleft;
        list[last+2] = pright;
        last = last + 2;
        current++;
    }
   
    // Explore the binary tree
    explore(root);
   
    return 0;
}
