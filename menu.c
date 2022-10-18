#include <stdio.h>
#include <stdlib.h>


// A linked list node
struct Node{
    int data;
    struct Node *next;
};

//inserts a new node on the front of the list
void push(struct Node** headRef,int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}
//insert a new node after the given node
void insertAfter(struct Node* prevNode, int newData)
{
    //check if the given prevNode is NULL
	if (prevNode == NULL)
	{
		printf("the given previous node is NULL!!!");
		return;
	}

	struct Node* newNode =(struct Node*) malloc(sizeof(struct Node));

	newNode->data = newData;

	newNode->next = prevNode->next;

	prevNode->next = newNode;
}
//insert a new node at the end
void append(struct Node** headRef, int newData)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *headRef;

	newNode->data = newData;

	newNode->next = NULL;

	if (*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}

    //travel till the last node
	while (last->next != NULL){
		last = last->next;
	}

	last->next = newNode;
	return;
}

//Print reverse of a Linked List
 void revPrintList(struct Node *headRef){

    if (headRef == NULL)
       return;

    revPrintList(headRef->next);
    printf(" %d ", headRef->data);
}

//Print a linked list
void printLinkedList(struct Node *node){
    while(node != NULL)
    {
        printf(" %d ",node->data);
        node= node->next;
    }
}
 //Counts no. of nodes in linked list
int lengthList(struct Node* headRef){

	int counter=0;

    struct Node* tmp = headRef;
    while (tmp != NULL) {
        counter++;
        tmp = tmp->next;
    }
    return printf("\ncount of nodes: %d\n",counter);
}

//Delete all elements with the same value
void deleteAllNodes(struct Node *head)
{
	//Define some auxiliary variables
	struct Node *newHead = NULL;
	struct Node *outer = head;
	struct Node *inner = NULL;
	//Resultant variables
	int status = 0;
	int counter = 1;
	printf(" After delete duplicate elements : ");
	//Below process takes O(n*n) time
	//iterating linked list elements
	while (outer != NULL)
	{
		inner = head;
		//iterating linked list elements
		while (inner != NULL && counter <= 1)
		{
			if (inner != outer && inner->data == outer->data)
			{
				//When element are duplicate
				counter++;
			}
			//visit to next node
			inner = inner->next;
		}
		if (counter == 1)
		{
			status = 1;
			append(&newHead,outer->data);
		}
		//reset the counter value
		counter = 1;
		//visit to next node
		outer = outer->next;
	}

	*head = *newHead;
}

int main(int argc, char *argv[]) {

	struct Node* head = NULL;


	return 0;
}
