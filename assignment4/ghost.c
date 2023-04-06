#include "defs.h"

//initilize both head and tail of the given list and set them to NULL
void initGhostList(GhostListType *list){
  list->head = NULL;
  list->tail = NULL;
}

//initializes GhostType structure's fields to the given parameters, and “returns” this new structure using the ghost parameter.
void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType **ghost){
  *ghost = (GhostType*)malloc(sizeof(GhostType));
  (*ghost)->id = id;
  (*ghost)->ghostType = gt;
  (*ghost)->room = r;
  (*ghost)->likelihood = like;
}

//adds the ghost directly at the back of the given list.
void addGhost(GhostListType *list, GhostType *ghost){
  NodeType *newNode = malloc(sizeof(NodeType));
  newNode->data = ghost;
  newNode->next = NULL;
  if (list->head == NULL){//if head of list is null, tail and head of the list are the same node
    list->head = newNode;
    list->tail = newNode;
  }
  else{//if head of list is not null, tail of the list is the new node
    list->tail->next = newNode;
    list->tail = newNode;
  }
}

//adds the ghost to the given list, directly in its correct place, in descending order by likelihood.
void addGhostByLikelihood(GhostListType *list, GhostType *ghost){
  NodeType *newNode = (NodeType*)malloc(sizeof(NodeType));
  newNode->data = ghost;
  newNode->next = NULL;
  if(list->head == NULL){//if head of list is null, tail and head of the list are the same node
    list->head = newNode;
    list->tail = newNode;
  }
  else{//if head of list is not null, tail of the list is the new node
    NodeType *curr = list->head;
    NodeType *prev = NULL;
    //if the new node's likelihood is greater than the head's likelihood, the new node becomes the head
    while(curr != NULL && curr->data->likelihood > ghost->likelihood){
      prev = curr;
      curr = curr->next;
    }
    if(prev == NULL){
      newNode->next = list->head;
      list->head = newNode;
    }
    else if(curr == list -> tail){
		  newNode->next = curr;
		  prev->next = newNode;
	  }
    else{
      newNode->next = curr;
      prev->next = newNode;
    }
  }
}

//traverses the given list and deallocates its data only.
void cleanupGhostData(GhostListType *list){
  NodeType *curr = list->head;//set curr to head of list
  NodeType *prev = NULL;//set prev to null

  while(curr != NULL){//while curr is not null:
    prev = curr;//set prev to curr
    free(prev->data);//free the data of prev
    curr = curr->next;//set curr to its next node
  }
}

//traverses the given list and deallocates its nodes only.
void cleanupGhostList(GhostListType *list){
  NodeType *curr = list->head;//set curr to head of list
  NodeType *prev = NULL;//set prev to null

  while(curr != NULL){//while the curr node is not null:
    prev = curr;//set prev to curr
    curr = curr->next;//set curr to its next node
    free(prev);//free prev
  }
}

//prints to the screen every field of the given ghost.
void printGhost(GhostType *ghost){
  printf("Ghost ID: %d", ghost->id);
    printf("\t\tGhost Type: ");
    if(ghost->ghostType == POLTERGEIST){
      printf("Poltergeist");
    }
    else if(ghost->ghostType == WRAITH){
      printf("Wraith");
    }
    else if(ghost->ghostType == PHANTOM){
      printf("Phantom");
    }
    else if(ghost->ghostType == BULLIES){
      printf("Bullies");
    }
    else if(ghost->ghostType == OTHER){
      printf("Other");
    }
    else{
      printf("Unknown");
    }
    printf("\t\tGhost Room: ");
    if (ghost->room == NULL){
        printf("%-15s","Unknown");
    }
    else{
        printf("%-15s", ghost->room->name);
    }
    printf("\t\tGhost Likelihood: %f\n", ghost->likelihood);
}
//prints every ghost in the given list to the screen.
void printGhosts(GhostListType *list, int ends){
  NodeType *curr = list->head;//set curr to head of list

  while(curr != NULL){//while curr is not null:
    printGhost(curr->data);//print the data of the current node
    curr = curr->next;//set curr to the next node
  }

  if(ends == C_TRUE){//if ends is true
    printGhost(list->head->data);//print the data of the head of the list
    printGhost(list->tail->data);//print the data of the tail of the list
  }
}

//prints every ghost in the given list to the screen, in decreasing order by likelihood.
void printByLikelihood(GhostListType *origList, int ends){
  NodeType *curr = origList->head;//set curr to head of origList
	GhostListType *temp = (GhostListType*)malloc(sizeof(GhostListType));//create a temporary list
	temp-> head = NULL;//set the head of the temporary list to null
	temp->tail = NULL;//set the tail of the temporary list to null

	while(curr != NULL){//adds every ghost in the original list to the temporary list
		addGhostByLikelihood(temp, curr->data);
		curr = curr->next;
	}

	printGhosts(temp, ends);//prints the temporary list
	cleanupGhostList(temp);
	free(temp);//frees the temporary list
}