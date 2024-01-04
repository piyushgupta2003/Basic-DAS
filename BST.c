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

int IsBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!IsBST(root->left))
        {
            return 0;
        }
        if(prev!= NULL && root ->data <= prev->data){
            return 0;
        }
        prev = root;
        return IsBST(root->right);
    }
    else 
    {
        return 1;
    }
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Finally, the tree looks like this:
    /*      5
           / \
          3   6
         / \
        1   4
*/
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    InOrder(p);
    printf("\n");
    printf("%d",IsBST(p));
    return 0;
}
