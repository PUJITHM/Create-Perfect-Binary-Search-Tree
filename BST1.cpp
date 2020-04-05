#include<stdio.h>
#include<stdlib.h>
#include<math.h>
  


struct node
{
    int key;
    struct node *left, *right;
};


struct node *root = NULL;
int height,pos,num;
bool Check(struct node *root, int pos,int mid,int key);
  
// A utility function to create a new BST node


struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    /* return the (unchanged) node pointer */
    return node;
}


void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ", root->key);
        inorder(root->right);
    }
}


bool checkPerfectBinaryTree(struct node *root, int h, int maxh)
{
	if(h<maxh)
	{
		if(root->left && root->right)
		{
			if(checkPerfectBinaryTree(root->left,h+1,maxh))
				return checkPerfectBinaryTree(root->right,h+1,maxh);
			else return false;
		}
		return false;
	}
	else if(h==maxh)
	{
		if(root->left || root->right)
			return false;
		else return true;
	}
	else return false;
}


void add(int data)
{
	if(root==NULL)
		root = insert(root, data);
	else
		insert(root, data);
}


void p(int start , int h)
{
	int i,j,k;
	for(i=0;i<h;i++)
	{
		k=pow(2.0,h-i);
		for(j=0;j<pow(2.0,i);j++)
		{
			printf("%d" ,start+k*j);
			add(start+k*j);
			if(checkPerfectBinaryTree(root,0,h-1))
				printf("s  ");
			else printf("f  ");
		}
		start-=k/4;
		printf("\n\n\n\n\n\n");
	}
}


bool Check(struct node *root, int pos,int mid,int key)
{
	if(mid>0)
	{
		if(pos>mid)
		{
			if(root->right!=NULL)
				return Check(root->right,pos-mid,mid/2,key);
			else 
				return false;
		}
		else
		{
			if(root->left!=NULL)
				return Check(root->left,pos,mid/2,key);
			else 
				return false;
		}
	}
	else
	{
		if(key==root->key)
			return true;
		return false;
	}

}



// Driver Program to test above functions
int main()
{
    
    
    int r;
	scanf("%d %d %d",&height,&pos,&num);
	//root=num+(pow(2.0,height)-pos)*2-pow(2.0,height)+1;
	r=num+pow(2.0,height)-2*pos+1;
	p(r,height+1);

  
    // print inoder traversal of the BST
    //inorder(root);
  system("pause");
    return 0;
}
