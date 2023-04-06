#include "defs.h"

int main()
{
  BuildingType building;//declare building

  initBuilding(&building);//initialize building

  loadBuildingData(&building);//load building data

  int choice = 0;
  printMenu(&choice);
  while(choice != 0){
    if(choice == 1){//if user chose 1
      printRooms(&building.rooms);//print rooms
    }
    else if(choice == 2){//if user chose 2
      printGhosts(&building.ghosts, C_FALSE);//print ghosts
    }
    else if(choice == 3){//if user chose 3
      printByLikelihood(&building.ghosts, C_FALSE);//print ghosts by likelihood
    }
    else{//if user chose other than 1, 2, or 3
      printf("Invalid option! Please try again.");//print error message
    }
    printMenu(&choice);
  }

  cleanupBuilding(&building);//cleanup building
  return(0);
}

void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}