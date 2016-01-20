const char PROPERTY_SEPARATOR = ':';

std::string obstacle_filename("current_obstacles.txt");
std::ofstream obstacle_stream( obstacle_filename.c_str() );
obstacleStr.clear();
for ( obstacleMap_it = obstacleMap.begin(); obstacleMap_it != obstacleMap.end(); obstacleMap_it++ ) {
  Plan_Obstacle thisObstacle = obstacleMap_it->second;
  obstacleStr+=obstacleMap_it->first;
  obstacle_stream << thisObstacle.to_string() << std::endl;
}
std::cout << machine_name() << "::" << state_name() << "::obstacleStr = " << std::boolalpha << obstacleStr << '\n';
obstacle_stream.close();
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
