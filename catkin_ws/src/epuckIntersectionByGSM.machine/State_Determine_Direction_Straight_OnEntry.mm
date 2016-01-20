wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();
canGoStraight         = (!((wbcIntersection_Status.directions().direction())&Direction::STRAIGHT)&&(gsCenterPathTrigger>=SENSOR_TRIGGER_SIZE)&&((gsLeftPathTrigger==0)||(gsRightPathTrigger==0)));
alignedInIntersection = wbcDifferentialRobot_Status.left_motor().odo()>encStateB4Maneuver.encoder[0]+INTERSECTION_ALIGN || wbcDifferentialRobot_Status.right_motor().odo()>encStateB4Maneuver.encoder[1]+INTERSECTION_ALIGN;


#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  printf("%s::========================================================\n",machine_name());
  printf("%s::Left CurEnc (%d) / OrgEnc (%d)\n",machine_name(),encStateB4Maneuver.encoder[0],wbcDifferentialRobot_Status.left_motor().odo());
  printf("%s::Right CurEnc (%d) / OrgEnc (%d)\n",machine_name(),encStateB4Maneuver.encoder[1],wbcDifferentialRobot_Status.right_motor().odo());
  printf("%s::Difference  Left (%d) / Right (%d)\n",machine_name(),encStateB4Maneuver.encoder[0]-wbcDifferentialRobot_Status.left_motor().odo(),encStateB4Maneuver.encoder[1]-wbcDifferentialRobot_Status.right_motor().odo());
  printf("%s::========================================================\n",machine_name());
#endif
