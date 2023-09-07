/*
    1194 - Pre, In and Post
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} node;

void createTree(node **, const char *, const char *);
void printInPost(const node *);
void cleanTree(node **);

int main(void)
{
    int cases;
    char s1[55];
    char s2[55];
    node *tree = NULL;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%*d %s %s", s1, s2);
        createTree(&tree, s1, s2);
        printInPost(tree);
        printf("\n");
        cleanTree(&tree);   //just to free memory, not necessary
    }

    return 0;
}

void createTree(node **t, const char *s1, const char *s2)
{
    char newS1[55] = "\0";
    char newS2[55] = "\0";
    int i;
    int j;
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = s1[0];
    newNode->left = newNode->right = NULL;

    for(i = 0 ; s2[i] != s1[0] ; i++);  //find root position in string
    for(j = 0 ; j < i ; j++)
    {   //creates the pre and in-order combination of the left subtree
        newS1[j] = s1[j+1];
        newS2[j] = s2[j];
    }
    newS1[i] = newS2[i] = '\0';

    if(newS1[0] != '\0' && newS2[0] != '\0')
        createTree(&newNode->left, newS1, newS2);

    for(j = i ; s1[i+1] != '\0' ; i++)  //find the last position in string
    {   //creates the pre and in-order combination of the right subtree
        newS1[i-j] = s1[i+1];
        newS2[i-j] = s2[i+1];
    }
    newS1[i-j] = newS2[i-j] = '\0';

    if(newS1[0] != '\0' && newS2[0] != '\0')
        createTree(&newNode->right, newS1, newS2);
    
    *t = newNode;   //return newNode;
}
void printInPost(const node *n)
{
    if(n)
    {
        printInPost(n->left);
        printInPost(n->right);
        printf("%c", n->data);
    }
}
void cleanTree(node **n)
{
    if(*n)
    {
        node *n0 = *n;
        cleanTree(&n0->left);
        cleanTree(&n0->right);
        free(n0);
        *n = NULL;
    }
}
