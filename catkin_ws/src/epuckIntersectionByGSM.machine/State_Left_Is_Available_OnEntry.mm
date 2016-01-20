wbcIntersection_Status = wbhIntersection_Status.get();
Direction newDirections = static_cast<Direction>(static_cast<uint8_t>(wbcIntersection_Status.directions().direction()) | static_cast<uint8_t>(Direction::LEFT));
wbcIntersection_Status.directions().set_direction(newDirections);
wbhIntersection_Status.set(wbcIntersection_Status);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
