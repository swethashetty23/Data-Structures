#include<stdio.h>

void binary_search(int[],int,int,int);

int main(){
	int key,size,i;
	int arr[50];
	printf("Enter size of a array : ");
	scanf("%d",&size);
	printf("Enter elements in a sorted order\n");
	for(i = 0;i < size;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Enter key to search : ");
	scanf("%d",&key);
	binary_search(arr,0,size,key);
	return 0;
}

void binary_search(int arr[],int low,int high,int key){
	int mid;
	if(low > high){
		printf("Key not found\n");
	}
	else{
	mid = (low + high)/2;
	if (arr[mid] == key){
		printf("Key found in %d position",mid+1);
	}
	else if(arr[mid] > key){
		binary_search(arr,low,mid-1,key);
	}
	else {
		binary_search(arr,mid+1,high,key);
	}
}
}
	
	



