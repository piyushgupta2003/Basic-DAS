//  left --> root --> right

#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

// Creating function to create a new node
struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void InOrder(struct node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

int main()
{
    struct node *p = createNode(7);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(1);
    struct node *p3 = createNode(0);
    struct node *p4 = createNode(4);

    // Finally, the tree looks like this:
    /*      7
           / \
          2   1
         / \
        0   4
*/
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    InOrder(p);
    return 0;
}
