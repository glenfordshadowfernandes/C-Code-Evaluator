
	/*	Author:Francesca Rodricks
		Date Created:28:02:2011
		Purpose:BSEARCH
		Date Modified:02:03:2011
	*/
#include<stdio.h>
#include<string.h>
#include "bsearch.h"
#include<malloc.h>
#include<stdlib.h>
#define SUCCESS 1


	int insert(BST_node_type **BST, elementtype newelement)
 	  {	int ans;
		BST_node_type *temp;
		BST_node_type *newnode;
		BST_node_type *parent;
				 
			newnode=(BST_node_type*)malloc(sizeof(BST_node_type));

			  if(newnode==NULL)
			   { 
			  	  printf("ERROR:COULD NOT ALLOCATE SPACE\n");
			   }
			  newnode->info=newelement;
			  newnode->right=NULL;
			  newnode->left=NULL;
			 
		if(*BST==NULL)
		{
			 *BST=newnode;	
			return(1);
		 }	
		else
		{
		   temp=*BST;
		   while(temp!=NULL)
		   {
			parent=temp;
			//compare the already existing data(info[root]) >= newnode[newdata]
			if(temp->info >= newnode->info)
			{
				temp=temp->left;
			}
			else
				temp=temp->right;
		   }
			//inserting the value 
		   if(newnode->info <= parent->info)
		   {
			parent->left=newnode;
		   }
	   	   else
		   {
			parent->right=newnode;
		   }		
		}
		  return(SUCCESS);
	 }


	void print_tree(BST_node_type *BST,int order)
	  {	printf("PRESS 1:PRE-ORDER 2:IN-ORDER 3:POST-ORDER \n");
		scanf("%d",&order);
		if(BST==NULL)
		printf("EMPTY\n");
		else if (order==1)
		preorder(BST);
		else if (order==2)
		inorder(BST);
		else if(order==3)
		postorder(BST);
	 }


	inorder (BST_node_type *BST)
	  {
		if(BST!=NULL)
		{
			inorder(BST->left);
			printf("\t%d\n",BST->info);
			inorder(BST->right);
		}
	  }
	
	preorder (BST_node_type *BST)
	  {
		if(BST!=NULL)
		{
			printf("\t%d\n",BST->info);
			preorder(BST->left);
			preorder(BST->right);
		}
	  }
	

	postorder(BST_node_type *BST)
	  {	
		if(BST!=NULL)
		{
			postorder(BST->left);
			postorder(BST->right);
			printf("\t%d\n",BST->info);
		}
	  }

	int deletee(BST_node_type **BST, elementtype key)
	{	BST_node_type *temp;
		BST_node_type *deleteptr;
		if(*BST==NULL)
		{
			return 0;
		}
		temp=*BST;
		if(key < temp->info)
		
			return(deletee(&temp->left,key));
		else if (key > temp->info)
		
			return (deletee(&temp->right,key));
		
		else//Element found
			if((temp->left == NULL)&&(temp->right != NULL))
			{
				deleteptr=*BST;
				*BST=temp->right;
				free(deleteptr);
			}
		
			else if((temp->left != NULL)&&(temp->right == NULL))
			{
				deleteptr=*BST;
				*BST=temp->left;
				free(deleteptr);
			}
			else if((temp->left == NULL)&&(temp->right == NULL))
			{	deleteptr=*BST;
				*BST=NULL;
				free(deleteptr);				
			}
			else{
				deleteptr=temp->left;
				while(deleteptr->right != NULL)
					deleteptr=deleteptr->right;
				(*BST)->info=deleteptr->info;
				return(deletee(&((*BST)->left),deleteptr->info));
			}
			return 1;
	}
	
