#if defined _speedometer_hooks_included
    #endinput
#endif
#define _speedometer_hooks_included
#pragma library speedometer_hooks

#include <YSI_Coding\y_hooks>
#include <YSI_Coding\y_timers>

static Timer:speedoTimerUpdate[MAX_PLAYERS], bool:speedoMenuStatus[MAX_PLAYERS];

TIMER__ SPEEDO_UpdateTimer[1000](playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid),
        Float:health;

    GetVehicleHealth(vehicleid, health);
    va_PlayerTextDrawSetString(
        playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 17), "%d%s",
        Speedometer_GetSpeed(vehicleid, Speedometer_GetSpeedUnit(playerid)), Speedometer_GetSpeedUnit(playerid) == 1 ? "km/h" : "mp/h"
    );
    va_PlayerTextDrawSetString(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 7), "%.0f", health);

    if (health >= 800.00)
        PlayerTextDrawColor(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 6), 16711935);
    else if (health >= 600.00)
        PlayerTextDrawColor(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 6), 0xedaf1fFF);
    else if (health >= 400.00)
        PlayerTextDrawColor(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 6), 0xde5009FF);
    else if (health >= 0.00)
        PlayerTextDrawColor(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 6), 0xFF0000FF);
    PlayerTextDrawShow(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 6));
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if (newstate == PLAYER_STATE_DRIVER)
    {
        Speedometer_SetEngine(playerid, false);
        Speedometer_SetLights(playerid, false);
        Speedometer_ShowStartPanel(playerid, true);
    }

    else if (newstate == PLAYER_STATE_ONFOOT)
    {
        Speedometer_ShowStartPanel(playerid, false);
        Speedometer_ShowInfoPanel(playerid, false);
        Speedometer_ShowMenuPanel(playerid, false);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (newkeys & KEY_SUBMISSION)
    {
        if (IsPlayerInAnyVehicle(playerid))
            SelectTextDraw(playerid, 0xFFFFFFAA);
    }

    else if (newkeys & KEY_CROUCH)
    {
        speedoMenuStatus[playerid] = !speedoMenuStatus[playerid];
        if (IsPlayerInAnyVehicle(playerid) && Speedometer_GetEngine(playerid))
            Speedometer_ShowMenuPanel(playerid, speedoMenuStatus[playerid]);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 2))
    {
        CancelSelectTextDraw(playerid);
        Speedometer_SetEngine(playerid, !Speedometer_GetEngine(playerid));

        if (Speedometer_GetEngine(playerid))
        {
            Speedometer_SetSpeedUnit(playerid);
            Speedometer_ShowStartPanel(playerid, false);
            Speedometer_ShowInfoPanel(playerid, true);

            PlayerTextDrawSetString(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 4), Speedometer_GetVehicleName(GetPlayerVehicleID(playerid)));
            PlayerTextDrawSetPreviewModel(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 5), GetVehicleModel(GetPlayerVehicleID(playerid)));
            PlayerTextDrawShow(playerid, PlayerText:Speedometer_ReturnTextDraw(playerid, 5));
            speedoTimerUpdate[playerid] = REPEAT__ SPEEDO_UpdateTimer(playerid);
        }
    }

    else if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 10))
        Speedometer_SetSpeedUnit(playerid);

    else if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 11))
        Speedometer_SetSpeedUnit(playerid, 2);

    else if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 12))
        Speedometer_SetDoors(playerid, 1, !Speedometer_GetDoors(playerid, 1));

    else if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 13))
        Speedometer_SetDoors(playerid, 3, !Speedometer_GetDoors(playerid, 3));

    else if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 14))
        Speedometer_SetDoors(playerid, 4, !Speedometer_GetDoors(playerid, 4));

    else if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 15))
        Speedometer_SetDoors(playerid, 2, !Speedometer_GetDoors(playerid, 2));

    else if (playertextid == PlayerText:Speedometer_ReturnTextDraw(playerid, 22))
        Speedometer_SetLights(playerid, !Speedometer_GetLights(playerid));
    return Y_HOOKS_CONTINUE_RETURN_1;
}