//DRiver for Assetto Corsa

/*PERSONAL NOTES : SHARED MEMORY FILE NAMES
From https://www.assettocorsamods.net/threads/doc-shared-memory-reference.58/
physics : acpmf_physics
graphics : acpmf_graphics
static : acpmf_static
*/
#ifndef SH_ASSETTO_CORSA_H
#define SH_ASSETTO_CORSA_H

#define STATIC "Local/acpmf_static"
#define PHYSICS "Local/acpmf_physics"
#define GRAPHICS "Local/acpmf_graphics"


#include <windows.h> //MapViewOfFile

struct SPageFileStatic { //The following members are initialized when the instance starts and never changes until the instance is close
    wchar_t smVersion[15]; // Version of the Shared Memory structure
    wchar_t acVersion[15]; // Version of Assetto Corsa
    int numberOfSessions = 0; // Number of sessions in this instance
    int numCars = 0; // Max number of possible cars on track
    wchar_t carModel[33]; // Name of the player's car
    wchar_t track[33]; // Name of the track
    wchar_t playerName[33]; // Name of the player
    wchar_t playerSurname[33]; // Surname of the player
    wchar_t playerNick[33]; // Nickname of the player
    int sectorCount = 0; // Number of track sectors
    float maxTorque = 0; // Max torque value of the player's car
    float maxPower = 0; // Max power value of the player's car
    int maxRPM = 0; // Max rpm value of the player's car
    float maxFuel = 0; // Max fuel value of the player's car
    float suspensionMaxTravel[4]; // Max travel distance of each tyre [Front Left, Front Right, Rear Left, Rear Right]
    float tyreRadius[4]; // Radius of each tyre [Front Left, Front Right, Rear Left, Rear Right]
    float maxTurboBoost = 0; // Max turbo boost value of the player's car
    float deprecated_1; // Do not use it
    float deprecated_2; // Do not use it
    int penaltiesEnabled = 0; // Cut penalties enabled: 1 (true) or 0 (false)
    float aidFuelRate = 0; // Fuel consumption rate: 0 (no cons), 1 (normal), 2 (double cons), etc.
};

struct SPageFilePhysics;

struct SPageFileGraphic;

#endif