#if defined _speedometer_functions_included
    #endinput
#endif
#define _speedometer_functions_included
#pragma library speedometer_functions

#if defined SPEEDO_DEFAULT_SPEED_UNIT
    #undef SPEEDO_DEFAULT_SPEED_UNIT
#endif

// 1 = km/h
// 2 = mp/h
const SPEEDO_DEFAULT_SPEED_UNIT = 1;

static speedoVehicleEngine[MAX_PLAYERS],
    speedoVehicleLights[MAX_PLAYERS],
    speedoVehicleSpeedUnit[MAX_PLAYERS],
    speedoVehicleFuel[MAX_PLAYERS] = 50,
    speedoVehicleDoor[MAX_PLAYERS][4];

static const modelNames[][] =
{
    "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel",
    "Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana", "Infernus",
    "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
    "Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection",
    "Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator", "Bus",
    "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", "Cabbie",
    "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral",
    "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder",
    "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", "Berkley's RC Van",
    "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale",
    "Oceanic","Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy",
    "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", "Regina", "Comet", "BMX",
    "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper",
    "Rancher", "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking",
    "Blista Compact", "Police Maverick", "Boxvillde", "Benson", "Mesa", "RC Goblin",
    "Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher", "Super GT",
    "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stunt",
    "Tanker", "Roadtrain", "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra",
    "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune",
    "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer",
    "Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex", "Vincent",
    "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", "Primo",
    "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite",
    "Windsor", "Monster", "Monster", "Uranus", "Jester", "Sultan", "Stratium",
    "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
    "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper",
    "Broadway", "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400",
    "News Van", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
    "Freight Box", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car",
    "Police Car", "Police Car", "Police Ranger", "Picador", "S.W.A.T", "Alpha",
    "Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs", "Boxville",
    "Tiller", "Utility Trailer"
};

enum
{
    E_DOOR_FRONT_LEFT = 0b01,
    E_DOOR_FRONT_RIGHT,
    E_DOOR_REAR_LEFT,
    E_DOOR_REAR_RIGHT
};

stock Speedometer_GetEngine(const playerid) return speedoVehicleEngine[playerid];
stock Speedometer_GetLights(const playerid) return speedoVehicleLights[playerid];
stock Speedometer_GetSpeedUnit(const playerid) return speedoVehicleSpeedUnit[playerid];
stock Speedometer_GetDoors(const playerid, const door) return speedoVehicleDoor[playerid][door - 1];

stock Speedometer_SetEngine(const playerid, const bool:status)
{
    if (!IsPlayerInAnyVehicle(playerid))
        return 0;

    static engine, lights, alarm, doors, bonnet, boot, objective;
    speedoVehicleEngine[playerid] = status;

    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(GetPlayerVehicleID(playerid), (!status ? 0 : 1), lights, alarm, doors, bonnet, boot, objective);
    return 1;
}

stock Speedometer_SetLights(const playerid, const bool:status)
{
    if (!IsPlayerInAnyVehicle(playerid))
        return 0;

    static engine, lights, alarm, doors, bonnet, boot, objective;
    speedoVehicleLights[playerid] = status;
    
    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, (!status ? 0 : 1), alarm, doors, bonnet, boot, objective);
    return 1;
}

stock Speedometer_SetDoors(const playerid, const door, const bool:status)
{
    if (!IsPlayerInAnyVehicle(playerid))
        return 0;

    static driver, passenger, backleft, backright;
    GetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), driver, passenger, backleft, backright);

    speedoVehicleDoor[playerid][door - 1] = status;
    switch (door)
    {
        case E_DOOR_FRONT_LEFT: SetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), (!status ? 0 : 1), passenger, backleft, backright);
        case E_DOOR_FRONT_RIGHT: SetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), driver, (!status ? 0 : 1), backleft, backright);
        case E_DOOR_REAR_LEFT: SetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), driver, passenger, (!status ? 0 : 1), backright);
        case E_DOOR_REAR_RIGHT: SetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), driver, passenger, backleft, (!status ? 0 : 1));
    }
    return 1;
}

stock Speedometer_SetSpeedUnit(const playerid, const unit = SPEEDO_DEFAULT_SPEED_UNIT)
{
    if (!IsPlayerInAnyVehicle(playerid))
        return 0;

    speedoVehicleSpeedUnit[playerid] = unit;
    return 1;
}

stock Speedometer_GetSpeed(const vehicleid, const unit = SPEEDO_DEFAULT_SPEED_UNIT)
{
    static Float: pos_y,
        Float: pos_x,
        Float: pos_z,
        Float: veh_speed;

    GetVehicleVelocity(vehicleid, pos_x, pos_y, pos_z);
    veh_speed = unit == 1 ? VectorSize(pos_x, pos_y, pos_z) * 180 : VectorSize(pos_x, pos_y, pos_z) * 136.66;
    return floatround(veh_speed, floatround_round);
}

stock Speedometer_GetVehicleName(const vehicleid)
{
    new name[32];
 
    if(400 <= GetVehicleModel(vehicleid) <= 611)
        strcopy(name, modelNames[GetVehicleModel(vehicleid) - 400]);
    else
        name = "Unknown";
    return name;
}

#pragma unused speedoVehicleFuel