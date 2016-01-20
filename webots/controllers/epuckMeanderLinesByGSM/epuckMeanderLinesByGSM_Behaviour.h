#ifndef epuckMeanderLinesByGSM_Behaviour_H_INCLUDED
#define epuckMeanderLinesByGSM_Behaviour_H_INCLUDED

#include <webots/Robot.hpp>
#include <webots/DifferentialWheels.hpp>

const int TIME_STEP = 32;

// Number of consecutive sensor readings required to make a decision.
const int SENSOR_TRIGGER_SIZE = 3;

// Infrared Sensor return value thresholds used for navigation.
const int PATH_THRESHOLD = 680;
const int INTERSECTION_THRESHOLD = 380;

// Because the line/intersection markings are not anti-aliased, the transition between
// 'On the marking' and 'Off the marking' is stark and produces large deltas during calculations.
// Therefore use a very small feedback gain, otherwise the robot goes out of control.
const double ALIGN_GAIN = 0.04;

// Infrared Sensors (PS7 & PS0) return value for range = 15mm.
const int RANGE_THRESHOLD = 500;

// Minimum turn distance (using the Wheel Encoders as the Unit of Measure) to clear the path.
// The TURN behaviour only requires that the GMS sensors move to the right/left of the path
// Once they clear the path, the ALIGN behaviour takes care of their return to the path on
// completion of the turn.
const int MIN_TURN = 260;
const int INTERSECTION_ALIGN = 270; //310;

// Speed of the E-Puck
const double MAX_SPEED = 300.0;
// Speed reduction factor when aligning at intersections and turning
const double TURN_FACTOR = 0.333;

#define GRID_WIDTH 6
#define GRID_HEIGHT 6

// Ground Sensor Module Indicies
#define LEFT_GS 0
#define CENTER_GS 1
#define RIGHT_GS 2
// Position Sensor Indicies
#define LEFT_PS 0     //  PS7
#define RIGHT_PS 1    //  PS0

// Wheel Encoder Indicies
#define LEFT_ENC 0    // Left encoder
#define RIGHT_ENC 1   // Right encoder

class epuckMeanderLinesByGSM_Behaviour : public webots::DifferentialWheels {

  public:

     /***
    * Defines the possible directions that the robot can
    * choose from when navigating an intersection
    */
    enum Direction {
      UNDECIDED     = 0x00,
      STRAIGHT      = 0x01,
      RIGHT         = 0x02,
      LEFT          = 0x04
    };

    /*** Setup state enumeration and buffers.
    */
    enum SearchStates {
      FORWARD       = 0x01,   // Going forward (normal)
      INTERSECTION  = 0x02,   // Entering Intersection, need to advance to the 'center'
      TURN          = 0x04,   // Turn To Right or Left the first 80 degrees
      ALIGN         = 0x08,   // Finish the turn by aligning to the path

      STOP          = 0x80    // Stops the robot and performs no further processing.
    };

    /**
     * epuckMeanderLinesByGSM_Behaviour constructor
     */
    epuckMeanderLinesByGSM_Behaviour();

    /**
     * epuckMeanderLinesByGSM_Behaviour destructor
     */
    virtual ~epuckMeanderLinesByGSM_Behaviour();


    /**
     * run() method as required by the Webots API.
     * After setting up initial conditions and requirements,
     * the main loop is entered.
     */
    void run();

    Direction chooseDirection (Direction possibleDirections);

    void setInitialPosition(int x, int y, int angle);


  private:

    struct position {
      int x;      // 1 is on the left of the map
      int y;      // 1 is at the top of the map
      int angle;  // 0, 90, 180, 270 (0 is up/north)
    };

    struct rotationalEncoders {
      double encoder[2];
    };

    rotationalEncoders getEncoders();
    void updatePosition();


    webots::DistanceSensor* gs[3];
    webots::DistanceSensor* ps[2];  // Only using PS0 & PS7, PS1 - PS6 not used.
    rotationalEncoders encStateB4Maneuver;

    bool running = false;

    bool returning = false;
    position curPosition = {3,6,0};

/*
    // Commented out in this example
    webots::LightSensor* ls[8]; // LightSensors are positioned almost the same as DistanceSensors
    webots::LED* led[10]; // See the class constructor implementation for mapping of LEDs
*/

};
#endif // epuckMeanderLinesByGSM_Behaviour_H_INCLUDED
