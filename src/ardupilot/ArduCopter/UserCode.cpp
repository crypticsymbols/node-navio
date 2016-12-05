/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here

    // update location from AHRS
    ahrs.get_position(current_loc);

    hal.console->printf_P(
        PSTR( "ROLL: %f PITCH: %f YAW: %f LAT: %d LONG: %d ALT: %d \n"),
        ahrs.roll,
	ahrs.pitch,
	ahrs.yaw,
	current_loc.lat,
	current_loc.lng,
	current_loc.alt
    );
    hal.console->printf_P(
        PSTR( "AHRS healthy: %d AHRS Initialized: %d GPS sats: %d GPS Status: %d \n"),
	ahrs.healthy(),
	ahrs.initialised(),
        gps.num_sats(),
        gps.status()
    );
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
}
#endif
