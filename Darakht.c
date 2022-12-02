#include<stdio.h>
#include<stdlib.h>
struct TNode
{
	struct TNode *left;
	int data;
	struct TNode *right;
};
void insert(struct TNode **sr,int data)
{
	struct TNode *r,*curr,*par;
	char flag;
	r=(struct TNode *)malloc(sizeof(struct TNode));
	r->left=NULL;
	r->data=data;
	r->right=NULL;
	if(*sr==NULL)
	{
		*sr=r;
	}
	else
	{
		curr=*sr;
		par=NULL;
		while(curr!=NULL)
		{
			if(data > curr->data)
			{
				par=curr;               //backup
				curr=curr->right;
				flag='r';
			}
			else
			{
				par=curr;
				curr=curr->left;
				flag='l';
			}
		}
		if(flag=='r')
		{
			par->right=r;
		}
		else
		{
			par->left=r;
		}
	}
}
void inorder(struct TNode *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		printf("%i\t",sr->data);
		inorder(sr->right);
	}
}
void preorder(struct TNode *sr)
{
	if(sr!=NULL)
	{
		printf("%i\t",sr->data);
		preorder(sr->left);
		preorder(sr->right);
	}
}
void postorder(struct TNode *sr)
{
	if(sr!=NULL)
	{
		postorder(sr->left);
		postorder(sr->right);
		printf("%i\t",sr->data);
	}
}
int main()
{
	struct TNode *root;
	root=NULL;
	insert(&root,6);
	insert(&root,4);
	insert(&root,10);
	insert(&root,1);
	insert(&root,5);
	insert(&root,8);
	insert(&root,12);
	insert(&root,7);
	insert(&root,9);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
}
