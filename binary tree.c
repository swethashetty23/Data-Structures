#include<stdio.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
}*root = NULL,*temp;

void create_node(){
	struct node*p;
	p = (struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&p -> data);
	p -> left = NULL;
	p -> right = NULL;
	if (root == NULL){
		root = p;
		temp = p;
	}
	else{
		char ch;
		int pos;
		printf("enter your choice\n 'l' - left\n 'r' - right : ");
		scanf("%c",&ch);
		if (ch  == "l"){
			printf("\nenter position\n1 for left \n 2 for right : ");
			scanf("%d",&pos);
			if(pos == 1){
				while (temp->left != NULL){
					temp = temp -> left;
				}
				temp -> left = p;
			}
			else{
				while(temp -> right != NULL){
					temp = temp -> right;
				}
				temp -> right = p;
			}
		}
	
		else{
			printf("enter position\n1 for left \n 2 for right :");
			scanf("%d",&pos);
			if(pos == 1){
				while (temp->left != NULL){
					temp = temp -> left;
				}
				temp -> left = p;
			}
			else{
				while(temp -> right != NULL){
					temp = temp -> right;
				}
				temp -> right = p;
			}
		}
		
	}
	
}
int main(){
	int i = 5;
	for(i = 0;i < 5;i++){
		create_node();
	}
	
	return 0;
}
