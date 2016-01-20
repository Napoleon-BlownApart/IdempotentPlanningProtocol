wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();

ready4align = (encStateB4Maneuver.encoder[0]-wbcDifferentialRobot_Status.left_motor().odo())>targetEncoderDelta;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:Internal Done\n",machine_name(),state_name());
  printf("%s::LEFT Init (%d) - Curr (%d) = %d\n",machine_name(),encStateB4Maneuver.encoder[0],wbcDifferentialRobot_Status.left_motor().odo(),encStateB4Maneuver.encoder[0]-wbcDifferentialRobot_Status.left_motor().odo());
  printf("%s::RIGHT Init (%d) / Curr (%d) = %d\n",machine_name(),encStateB4Maneuver.encoder[1],wbcDifferentialRobot_Status.right_motor().odo(),encStateB4Maneuver.encoder[1]-wbcDifferentialRobot_Status.right_motor().odo());
  printf("%s::Target = %d\n",machine_name(),targetEncoderDelta);
#endif
