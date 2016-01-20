wbcIntersection_Status = wbhIntersection_Status.get();
Direction newDirections = static_cast<Direction>(static_cast<uint8_t>(wbcIntersection_Status.directions().direction()) | static_cast<uint8_t>(Direction::STRAIGHT));
wbcIntersection_Status.directions().set_direction(newDirections);
wbhIntersection_Status.set(wbcIntersection_Status);

alignedInIntersection = wbcDifferentialRobot_Status.left_motor().odo()>encStateB4Maneuver.encoder[0]+INTERSECTION_ALIGN || wbcDifferentialRobot_Status.right_motor().odo()>encStateB4Maneuver.encoder[1]+INTERSECTION_ALIGN;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
