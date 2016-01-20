const char PROPERTY_SEPARATOR = ':';
obstacleStr.clear();

std::cout << "Loading known obstacles." << std::endl;
std::ifstream obstacleFile("current_obstacles.txt");
if (obstacleFile.good()) {
  std::string aLine;
  while(std::getline(obstacleFile,aLine)) {
    std::string key(aLine);
    Plan_Obstacle thisObstacle (key);
//    std::istringstream iss(aLine);
//    std::string token;
//    getline(iss, token, PROPERTY_SEPARATOR);
//    thisObstacle.set_intersectionA(token);
//    getline(iss, token, PROPERTY_SEPARATOR);
//    thisObstacle.set_intersectionB(token);
////    thisObstacle.set_isValidLocation(true);
    obstacleMap[key] = thisObstacle;
    obstacleList.push_back(thisObstacle);
    obstacleStr+=key;
  }
  std::cout << obstacleList.size() << " Obstacle(s) have been loaded." << std::endl;
} else {
  std::cout << "No obstacles Loaded" << std::endl;
}

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
