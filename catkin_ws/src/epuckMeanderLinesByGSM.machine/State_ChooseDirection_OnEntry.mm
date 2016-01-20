
int numChoices = 0;
if (possibleDirections & STRAIGHT) numChoices++;
if (possibleDirections & RIGHT) numChoices++;
if (possibleDirections & LEFT) numChoices++;

// Only one possible way to go, so return immediately.
if (numChoices == 1) {
 whichWay = possibleDirections;
} else {
  // Otherwise pick a direction
  int choice = (rand() % numChoices)+1;
  if ((possibleDirections & STRAIGHT) && (choice-- == 1)) {
    whichWay = STRAIGHT;
  } else if ((possibleDirections & RIGHT) && (choice-- == 1)) {
    whichWay = RIGHT;
    curPosition.angle = (curPosition.angle+90)%360;
  } else {
    whichWay = LEFT;
    curPosition.angle = (curPosition.angle != 0) ? curPosition.angle-90 : 270;
  }
}
gsLeftPathTrigger = 0;
gsCenterPathTrigger = 0;
gsRightPathTrigger = 0;
gsLeftIntersectionTrigger = 0;
gsCenterIntersectionTrigger = 0;
gsRightIntersectionTrigger = 0;
#ifdef DEBUG
  printf("ChooseDirection:OnEntry Done\n");
  printf("Directions Available = %d\n",static_cast<int>(possibleDirections));
  printf("Direction Chosen = %d\n",static_cast<int>(whichWay));
#endif
