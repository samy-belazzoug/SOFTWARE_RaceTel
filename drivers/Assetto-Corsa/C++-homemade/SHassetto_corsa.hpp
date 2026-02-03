//DRiver for Assetto Corsa

/*PERSONAL NOTES : SHARED MEMORY FILE NAMES
From https://www.assettocorsamods.net/threads/doc-shared-memory-reference.58/
physics : acpmf_physics
graphics : acpmf_graphics
static : acpmf_static
*/
#ifndef SH_ASSETTO_CORSA_H
#define SH_ASSETTO_CORSA_H

#define BUF_SIZE 256

//AC FLAGS
#define AC_OFF 0
#define AC_REPLAY 1
#define AC_LIVE 2
#define AC_PAUSE 3

#define AC_UNKNOWN -1
#define AC_PRACTICE 0
#define AC_QUALIFY 1
#define AC_RACE 2
#define AC_HOTLAP 3
#define AC_TIME_ATTACK 4
#define AC_DRIFT 5
#define AC_DRAG 6

#define AC_NO_FLAG 0 
#define AC_BLUE_FLAG 1 
#define AC_YELLOW_FLAG 2 
#define AC_BLACK_FLAG 3 
#define AC_WHITE_FLAG 4 
#define AC_CHECKERED_FLAG 5 
#define AC_PENALTY_FLAG 6 

#include <windows.h> // MapViewOfFile
#include <stdint.h> // int32_t_t
#include <float.h> // float
#include <tchar.h> // TCHAR
#include <stdlib.h> 
#include <iostream>

LPCWSTR sh_static = TEXT("acpmf_static");
LPCWSTR sh_physics = TEXT("acpmf_physics");
LPCWSTR sh_graphics = TEXT("acpmf_graphics");

// AC SPECIAL SPECIAL TYPES
typedef int32_t AC_STATUS; // Status of the instance
typedef int32_t AC_SESSION_TYPE; // Session type
typedef int32_t AC_FLAG_TYPE; // Type of flag being shown

struct SPageFileStatic { //The following members are initialized when the instance starts and never changes until the instance is close
    wchar_t smVersion[15]; // Version of the Shared Memory structure
    wchar_t acVersion[15]; // Version of Assetto Corsa
    int32_t numberOfSessions; // Number of sessions in this instance
    int32_t numCars; // Max number of possible cars on track
    wchar_t carModel[33]; // Name of the player's car
    wchar_t track[33]; // Name of the track
    wchar_t playerName[33]; // Name of the player
    wchar_t playerSurname[33]; // Surname of the player
    wchar_t playerNick[33]; // Nickname of the player
    int32_t sectorCount; // Number of track sectors
    float maxTorque; // Max torque value of the player's car
    float maxPower; // Max power value of the player's car
    int32_t maxRPM; // Max rpm value of the player's car
    float maxFuel; // Max fuel value of the player's car
    float suspensionMaxTravel[4]; // Max travel distance of each tyre [Front Left, Front Right, Rear Left, Rear Right]
    float tyreRadius[4]; // Radius of each tyre [Front Left, Front Right, Rear Left, Rear Right]
    float maxTurboBoost; // Max turbo boost value of the player's car
    float deprecated_1; // Do not use it
    float deprecated_2; // Do not use it
    int32_t penaltiesEnabled; // Cut penalties enabled: 1 (true) or 0 (false)
    float aidFuelRate; // Fuel consumption rate: 0 (no cons), 1 (normal), 2 (double cons), etc.

    float aidTireRate; // Tire wear rate: 0 (no wear), 1 (normal), 2 (double wear) etc.
    float aidMechanicalDamage; // Damage rate: 0 (no damage) to 1 (normal)
    int32_t aidAllowTyreBlankets; // Player starts with hot (optimal temp) tyres: 1 (true) or 0 (false)
    float aidStability; // Stability aid: 0 (no aid) to 1 (full aid)
    int32_t aidAutoClutch; // If player's car has the "auto clutch" feature enabled : 0 or 1
    int32_t aidAutoBlip; // If player's car has the "auto blip" feature enabled : 0 or 1
    int32_t hasDRS; // If player's car has the "DRS" system: 0 or 1
    int32_t hasERS; // If player's car has the "ERS" system: 0 or 1
    int32_t hasKERS; //If player's car has the "KERS" system: 0 or 1
    float kersMaxJ; //Max KERS Joule value of the player's car
    int32_t engineBrakeSettingsCount; // Count of possible engine brake settings of the player's car
    int32_t ersPowerControllerCount; // Count of possible power controllers of the player's car
    float trackSPlineLength; //Length of the spline of the selected track
    wchar_t trackConfiguration[33]; // Name of the track's layout (only multi-layout tracks)
    float ersMaxJ; // Max ERS Joule value of the player's car
    int32_t isTimedRace; // 1 if the race is a timed one
    int32_t hasExtraLap; // 1 if the timed race is set with an extra lap
    wchar_t carSkin[33]; // Name of the used skin
    int32_t reversedGridPositions; // How many positions are going to be swapped in the second race
    int32_t PitWindowStart; // Pit window is open on Lap/Minute
    int32_t PitWindowEnd; // Pit window is closed on Lap/Minute
};

struct SPageFilePhysics {
    int32_t packetId; // Index of the shared memory's current step
    float gas; // Value of gas pedal: 0 to 1 (fully pressed)
    float brake; // Value of brake pedal: 0 to 1 (fully pressed) 
    float fuel; // Liters of fuel in the car 
    int32_t gear;  // Selected gear (0 is reverse, 1 is neutral, 2 is first gear ) 
    int32_t rpms;  // Value of rpm 
    float steerAngle;  // Angle of steer 
    float speedKmh;  // Speed in Km/h 
    float velocity[3]; // Velocity for each axis (world related) [x, y, z] 
    float accG[3]; // G-force for each axis (local related) [x, y, z] 
    float wheelSlip[4]; /* Spin speed of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float wheelLoad[4]; /* Load on each tyre (in N) 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float wheelsPressure[4]; /* Pressure of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float wheelAngularSpeed[4]; /* Angular speed of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float tyreWear[4]; /* Current wear of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float tyreDirtyLevel[4]; /* Dirt level on each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/
    float tyreCoreTemperature[4]; /* Core temperature of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float camberRAD[4]; /* Camber of each tyre in Radian 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float suspensionTravel[4]; /* Suspension travel for each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float drs; // If DRS is present and enabled: 0 (false) or 1 (true) 
    float tc; // Slip ratio limit for the traction control (if enabled) 
    float heading; // Heading of the car on world coordinates 
    float pitch; // Pitch of the car on world coordinates 
    float roll; // Roll of the car on world coordinates 
    float cgHeight; // Height of Center of Gravity 
    float carDamage[5]; // Level of damage for each car section (only first 4 are valid) 
    int32_t numberOfTyresOut; /* How many tyres are allowed to stay out of the track to not 
    receive a penalty*/
    int32_t pitLimiterOn; // If pit limiter is enabled: 0 (false) or 1 (true) 
    float abs; // Slip ratio limit for the ABS (if enabled) 
    float kersCharge; // KERS/ERS battery charge: 0 to 1 
    float kersInput; // KERS/ERS input to engine: 0 to 1 
    int32_t autoShifterOn; // If auto shifter is enabled: 0 (false) or 1 (true) 
    float rideHeight[2]; // Right heights: front and rear 
    float turboBoost; // Turbo boost 
    float ballast; // Kilograms of ballast added to the car (only in multiplayer) 
    float airDensity; // Air density 
    float airTemp; // Ambient temperature 
    float roadTemp; // Road temperature 
    float localAngularVel[3]; // Angular velocity of the car [x, y, z] 
    float finalFF; // Current Force Feedback value; 
    float performanceMeter; // Performance meter compared to the best lap 
    int32_t engineBrake; // Engine brake setting 
    int32_t ersRecoveryLevel;  // ERS recovery level 
    int32_t ersPowerLevel;  // ERS selected power controller 
    int32_t ersHeatCharging;  // ERS changing: 0 (Motor) or 1 (Battery) 
    int32_t ersIsCharging; // If ERS battery is recharging: 0 (false) or 1 (true) 
    float kersCurrentKJ;  // KERS/ERS KiloJoule spent during the lap 
    int32_t drsAvailable;  // If DRS is available (DRS zone): 0 (false) or 1 (true) 
    int32_t drsEnabled;  // If DRS is enabled: 0 (false) or 1 (true) 
    float brakeTemp[4];  /* Brake temp for each tire 
    [Front Left, Front Right, Rear Left, Rear Right]*/
    float clutch;  // Value of clutch pedal: 0 to 1 (fully pressed) 
    float tyreTempI[4];  /* Inner temperature of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/
    float tyreTempM[4]; /* Middle temperature of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    float tyreTempO[4];  /* Outer temperature of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right]*/ 
    int32_t isAIControlled;  // AI controlled car: 0 (human) or 1 (AI) 
    float tyreContactPoint[4][3]; /* Vector for contact point32_t of each tyre 
    [Front Left, Front Right, Rear Left, Rear Right][x, y, z]*/ 
    float tyreContactNormal[4][3]; // Vector for contact normal of each tyre [Front Left, Front Right, Rear Left, Rear Right][x, y, z] 
    float tyreContactHeading[4][3]; // Vector for contact heading of each tyre [Front Left, Front Right, Rear Left, Rear Right][x, y, z] 
    float brakeBias; // Brake bias from 0 (rear) to 1 (front) 
    float localVelocity[3]; // Vector for local velocity
};

struct SPageFileGraphic {
    int32_t packetId; //Index of the shared memory's current step 
    AC_STATUS status = AC_OFF; 
    /*  Status of the instance: 
        AC_OFF 0 
        AC_REPLAY 1 
        AC_LIVE 2 
        AC_PAUSE 3 
    */

    AC_SESSION_TYPE session = AC_PRACTICE; 
    /* Session type: 
    
        AC_UNKNOWN -1 
        AC_PRACTICE 0 
        AC_QUALIFY 1 
        AC_RACE 2 
        AC_HOTLAP 3 
        AC_TIME_ATTACK 4 
        AC_DRIFT 5 
        AC_DRAG 6
    */ 
    wchar_t currentTime[15]; // Current lap time 
    wchar_t lastTime[15]; // Last lap time 
    wchar_t bestTime[15]; // Best lap time 
    wchar_t split[15]; // Time in sector 
    int32_t completedLaps; // Number of completed laps by the player 
    int32_t position; // Current player position (standings) 
    int32_t iCurrentTime; // Current lap time 
    int32_t iLastTime; // Last lap time 
    int32_t iBestTime; // Best lap time 
    float sessionTimeLeft; // Time left until session is closed 
    float distanceTraveled; // Distance traveled during the instance 
    int32_t isInPit; // If player's car is stopped in the pit: 0 (false) or 1 (true) 
    int32_t currentSectorIndex; // Current sector index 
    int32_t lastSectorTime; // Last sector time 
    int32_t numberOfLaps; // Number of laps needed to close the session 
    wchar_t tyreCompound[33]; // Current tyre compound 
    float replayTimeMultiplier; // Replay multiplier 
    float normalizedCarPosition; // Car position on the track's spline 
    float carCoordinates[3]; // Car position on world coordinates [x, y, z] 
    float penaltyTime; // Time of penalty 
    AC_FLAG_TYPE flag;
    /* Type of flag being shown: 
    
        AC_NO_FLAG 0 
        AC_BLUE_FLAG 1 
        AC_YELLOW_FLAG 2 
        AC_BLACK_FLAG 3 
        AC_WHITE_FLAG 4 
        AC_CHECKERED_FLAG 5 
        AC_PENALTY_FLAG 6 
    */
    int32_t idealLineOn; // If ideal line is enabled: 0 (false) or 1 (true) 
    int32_t isInPitLane; // If player's car is in the pitlane: 0 (false) or 1 (true) 
    float surfaceGrip; // Current grip of the track's surface 
    int32_t mandatoryPitDone; // Set to 1 if the player has done the mandatory pit 
    float windSpeed; // Speed of the wind on the current session 
    float windDirection; // Direction of the wind (0-359) on the current session 
};

class Mapping_AC {
    public:
        HANDLE sh_acpmf_static_mapping;
        LPVOID sh_acpmf_static_view;
        Mapping_AC(); // Constructor - Map to Assetto Corsa shared memory
        ~Mapping_AC(); // Destructor - destroy map
};

#endif