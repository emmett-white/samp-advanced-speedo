// generated by "sampctl package init"
#include <a_samp>
#define AMX_OLD_CALL
#define YSI_NO_HEAP_MALLOC
#include <speedometer>

main() 
{
	// write code here and run "sampctl package build" to compile
	// then run "sampctl package run" to run it
}

public OnGameModeInit()
{
	SetWorldTime(0);
	return 1;
}

static vehicle;
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (newkeys & KEY_YES)
	{
		new Float:x, Float:y, Float:z, Float:a;
		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, a);
		vehicle = CreateVehicle(560, x, y, z, a, 1, 1, 0);
		PutPlayerInVehicle(playerid, vehicle, 0);
	}
	return 1;
}