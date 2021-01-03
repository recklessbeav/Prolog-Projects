/*
	Beaverly Cuasi
	CSADPRG S11
*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Set {
	int n;
	struct Set *pointer;
} Set;


Set *create(){
	Set *creates;
	creates = malloc(sizeof(Set));
	creates->pointer = NULL;	
	return creates;
}


	// ascending order

void sort(Set *a) {
	Set *sets = a;
	int counter = 0;
	while(sets->pointer != NULL){
		sets = sets->pointer;
		counter++;
	}
	
	int sorting[counter];
	sets = a;
	int i=0,j;
	while (sets->pointer != NULL){
		sorting[i]=sets->n;
		sets=sets->pointer;
		i++;
	}
	
	// sorting time;
	
	int temp;
	for(i=0;i<counter;i++){
		for(j=0;j<counter-i-1;j++){
			if(sorting[j]>sorting[j+1]){
				temp = sorting[j];
				sorting[j] = sorting[j+1];
				sorting[j+1] = temp;			
			}
		}
	}	
	
	// put the sorted list to struct
	sets = a;
	i = 0;
	while(sets->pointer!=NULL){
		sets->n = sorting[i];
		i++;
		sets=sets->pointer;
	}
}


//	new value e in set a and return the pointer to the first element of a

Set *add(Set *a,int e){
	Set *tail;
	Set *b;	
	tail = a;
	
	// Traverse the linked list until the LAST BOX or last node.	
	while(tail->pointer != NULL){
		tail = tail->pointer;
	}
	
	// Adding new elements to the LAST BOX or last node.
	tail->n = e;
	
	// create new empty box/node
	b = create();
	
	// connect last box/node to the previous box/node.
	tail->pointer = b;
	
	sort(a);
	return a;
}


	// merge elements from sets s1 and s2 and returns a new Ordered Set

Set *Union(Set *s1,Set *s2){
	Set *a = s1;	
	Set *b = s2;
	Set *c = create();
	Set *d;
	Set *point = c;
	Set *tail;
	
	int isfound = FALSE;
	Set *traverse;
	
	// traverse through s1
	tail = a;
	while(tail->pointer!=NULL){
		traverse = c;
		while(traverse != NULL && isfound == FALSE){
			if(tail->n == traverse->n){
				isfound = TRUE;
			}
			traverse = traverse->pointer;
		}	
		if (isfound == FALSE){
			//copy value
			point->n = tail->n;
			
			//creates new node
			d = create();
			
			//goes to the next node
			point->pointer = d;
			point = point->pointer;
			
		}
		isfound = FALSE;
		tail = tail->pointer;
	}
	
	// traverse s2 and find non-common elements from s1
	tail = b;
	while(tail->pointer!=NULL){
		traverse = c;
		while(traverse != NULL && isfound == FALSE){
			if(tail->n == traverse->n){
				isfound = TRUE;
			}
			traverse = traverse->pointer;
		}	
		
		if(isfound == FALSE){
			//copy value
			point->n = tail->n;
			
			//creates new node
			d = create();
			
			//goes to the next
			point->pointer = d;
			point = point->pointer;
			
		}
		
		isfound = FALSE;
		tail = tail->pointer;
	}
	
	// after traversing s1 and s2, there will be an extra node. Free that node. 
	free(point);
	sort(c);
	return c;
}


Set *intersection(Set *s1, Set *s2){
	Set *a = s1;
	Set *b = s2;
	Set *c = create();			//to check if for repeating elements
	Set * d;
	Set *point = c;
	Set *tail;
	Set *find;
	
	int isfound = FALSE;
	int isfound2 = FALSE;
	int temp;
	
	// traverse through s1
	while(a->pointer!=NULL){
		b = s2;
		while(b->pointer!=NULL && isfound == FALSE){
			if(a->n == b->n){
				temp = a->n;
				isfound = TRUE;
			}
			b = b->pointer;
		}	
		
		// checks if element is repeated
		if (isfound == TRUE){
			find = c;
			
			//traverse through C, find if the element is repeated
			while(find->pointer != NULL && isfound2 == FALSE){
				if(find->n == temp){
					isfound2 = TRUE;
				}
				find = find->pointer;
			}
			
			// if no repeating elements, add the elements
			if(isfound2== FALSE){
				point->n = temp;			//copy value
				d = create();				//creates new node
				point->pointer = d;			//goes to next node
				point = point->pointer;	
					
			}
			
			isfound2 = FALSE;
		}
		
		isfound = FALSE;		
		a = a->pointer;		
	}
	
	sort(c);
	return c;
	
}


Set *difference(Set *s1, Set *s2){
	Set *a = Union(s1,s2); //creates union list from s1 and s2 
	Set *b = intersection(s1,s2); // creates intersection list from s1 and s2
	Set *c = create(); // stores the list with its difference
	Set *d;
	Set *point = c;
	Set *tail;
	Set *find;
	
	int isfound = FALSE;
	int isfound2 = FALSE;
	int temp;
	
	// traverse through the union list
	while(a->pointer!=NULL){
		b = s2;
		temp = a->n;
		while(b->pointer!=NULL && isfound == FALSE){
			if(temp == b->n){
				isfound = TRUE;
			}
			b = b->pointer;
		}	
	
		// get unique elements from union set with the list from intersection 
		if(isfound == FALSE){
			find = c;
			
			//Traverse through the C linked list
			while(find->pointer != NULL && isfound2 == FALSE){
				if(find->n == temp){
					isfound2 = TRUE;
				}
				find = find->pointer;
			}
			
			//if not element not found in the C linked list, add element
			if(isfound2== FALSE){
				point->n = temp;
				d = create();
				point->pointer = d;
				point = point->pointer;	
			}
			isfound2 = FALSE;
			
		}
		isfound = FALSE;		
		a= a->pointer;		
	}
	sort(c);
	return c;
	
}

void print(Set *a){
	Set *sets = a;
	while(sets->pointer!=NULL){
		printf("%d ",sets->n);
		sets=sets->pointer;
	}
}

int main(){
	Set *s1;
	Set *s2;
	Set *s3;
	
	s1 = create();
	s2 = create();
	s3 = create();
	
	add(s1,4);
	add(s1,2);
	add(s1,8);
	add(s1,6);
	printf("Print s1: ");
	print(s1); 				//this statement will display (2, 4, 6, 8);
	
	add(s2,2);
	add(s2,5);
	printf("\nPrint s2: ");
	print(s2);				//this statement will display (2, 5);
	
	add(s3,7);
	add(s3,6);
	printf("\nPrint s3: ");
	print(s3);				//this statement will display (6, 7);
	
	printf("\n\nUnion: ");
	print(Union(s1,s2));	//this statement will return (2, 4, 5, 6, 8);
	
	printf("\nUnion: ");
	print(Union(s2,s3));	//this statement will return ();
	
	printf("\n\nIntersection: "); 
	print(intersection(s1,s2)); //this statement will return (2);
	
	printf("\nIntersection: "); 
	print(intersection(s2,s3)); //this statement will return (2, 5, 6, 7);
	
	printf("\n\nDifference: ");
	print(difference(s1,s3));	//this statement will return (2, 4, 8);
	return 0;
}
