#include "defs.h"

//initializes the fields of the given RoomArrayType structure that require initialization.
void initRoomArray(RoomArrayType *arr){
  arr->size = 0;//set size to 0
}

//“return” the new room structure using the room parameter
void initRoom(int id, char *name, RoomType **room){
  *room = (RoomType*)malloc(sizeof(RoomType));
  (*room)->id = id;
  strcpy((*room)->name, name);
  (*room)->ghosts = (GhostListType*)malloc(sizeof(GhostListType));
  initGhostList((*room)->ghosts);
}

//adds the room r to the back of the array structure in parameter arr.
void addRoom(RoomArrayType *arr, RoomType *r){
  arr->elements[arr->size] = r;//add room to the back of the array
  arr->size++;//increment size of array
}

//deallocates the dynamically allocated memory in the given room collection.
void cleanupRoomArray(RoomArrayType *arr){
  for(int i = 0; i < arr->size; i++){//loop through array
    cleanupGhostList(arr->elements[i]->ghosts);//cleanup ghost list in each room
    free(arr->elements[i]->ghosts);//free ghost list
    free(arr->elements[i]);//free room
  }
}

//traverses the given room array and prints the fields of each room structure to the screen
void printRooms(RoomArrayType *arr){
  for(int i = 0; i < arr->size; i++){//loop through array
    printf("Room %d: %s\n", arr->elements[i]->id, arr->elements[i]->name);//print room id and name
    printGhosts(arr->elements[i]->ghosts, 0);//print ghost list
    printf("\n");
  }
}