#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*first = NULL,*temp,*last;

void create_node(){
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data of a node : ");
	scanf("%d",&p -> data);
	p -> next = NULL;
	if(first == NULL){
		first = p;
		temp = p;
	}
	else{
		temp -> next = p;
		temp = p;
	}

}

int display_node(){
	
	struct node*i;
	for(i = first; i != NULL ;i = i -> next){
		printf("%d ",i -> data);
	}
}

void insert_node(){
	struct node*n;
	struct node*p;
	struct node *t1,*t2;
	int ch;
	int pos;
	p = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data you want to insert\n");
	scanf("%d",&p -> data);
	p -> next = NULL;
	n = p;
	temp = first;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	last = temp;
	last -> next = NULL;
	if(first == NULL){
		first = n;
		last = n;
	}
	else{
		printf("enter the choice of insertion \n 1 : Beginning\n 2 : Ending \n 3 : Required Node\n");
		scanf("%c",&ch);
		if (ch  == 1){
			n -> next = first;
			first = n;
		}
		
		else if(ch == 2){
			last -> next = n;
			last = n;
			
		}
		else{
			printf("enter the position to insert the node\n ");
			scanf("%d",&pos);
			t1 = first;
			while(pos - 2 > 0){
				t1 = t1 -> next;
				pos --;
			}
			t2 = t1 -> next;
			t1 -> next = n;
			n -> next = t2;	
		
		}
		printf("\nData after insertion : ");
		display_node();
		
	}
}

void delete_node(){
	int pos;
	struct node*del,*t1,*t2;
	if(first == NULL){
		printf("Deletion is not possible\n");
	}
	else if (first -> next == NULL){
		
		printf("There is only one node\n");
		del = first;
		printf("deleted data : %d", del -> data);
		free(del);
		first = NULL;
	}
	else{
		printf("\nEnter the position of deletion\n");
		scanf("%d",&pos);
		t1 = first;
		if (pos == 1){
			del = first;
			first = first -> next;
			printf("deleted data is %d\n",del -> data);
			free(del);
		}
		else{
			while(pos - 2 > 0){
				t1 = t1 -> next;
				pos --;
			}
			del = t1 -> next;
			t2 = del -> next;
			printf("\ndeleted data is %d\n",del -> data);
			free(del);
			t1 -> next = t2;
		}
	}
}

int search_node(){
	int key,p = 0;
	struct node*t;
	printf("\nEnter the element you want to search : ");
	scanf("%d", &key);
	t = first;
	while(t -> next != NULL){
		if(t -> data == key){
			return p+1;
		}
		t = t -> next;
		p ++;
	
}

int main(){
	int j,c,k;
	for(j = 0; j < 5;j ++){
		create_node();
	}
	while(1){
		printf("\nEnter your choice\n");
		printf("\n1 : Insertion\n2 : Deletion\n3 : Display\n4 : Search\n5 : Exit\n");
		scanf("%d",&c);
		switch(c){
			case 1 : insert_node();
				break;
			case 2 : delete_node();
				break;
			case 3 : display_node();
				break;
			case 4 : k = search_node();
				if(k > 0){
					printf("Element found at node %d\n",k);
				}
				else{
					printf("Element not found\n");
				}
				break;
			case 5 : exit(0);
				default : printf("Enter numbers between 1 to 4\n");
		}
	}
	return 0;
	
}
	
		
	






