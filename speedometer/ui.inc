#if defined _speedometer_ui_included
    #endinput
#endif
#define _speedometer_ui_included
#pragma library speedometer_ui

static PlayerText:uiSpeedometer[MAX_PLAYERS][23] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...};

stock Speedometer_ReturnTextDraw(const playerid, const index) return _:uiSpeedometer[playerid][index];
stock Speedometer_ShowStartPanel(const playerid, bool:status)
{
	if (!status)
	{
		PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][0]);
		PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][2]);
		PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][3]);
		uiSpeedometer[playerid][0] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		uiSpeedometer[playerid][2] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		uiSpeedometer[playerid][3] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		return 1;
	}

	uiSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 292.699645, 354.566802, "box");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][0], 0.000000, 4.899998);
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][0], 342.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, uiSpeedometer[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, uiSpeedometer[playerid][0], 153);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][0], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][0], 1);

	uiSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 284.000000, 341.044433, "");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][2], 67.000000, 72.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][2], 0x00000000);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][2], 5);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][2], 0);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][2], true);
	PlayerTextDrawSetPreviewModel(playerid, uiSpeedometer[playerid][2], 11746);
	PlayerTextDrawSetPreviewRot(playerid, uiSpeedometer[playerid][2], 180.000000, -45.000000, 180.000000, 1.000000);

	uiSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 317.800079, 349.911193, "START_ENGINE");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][3], 0.123500, 0.623111);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][3], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][3], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][3], 1);

	PlayerTextDrawShow(playerid, uiSpeedometer[playerid][0]);
	PlayerTextDrawShow(playerid, uiSpeedometer[playerid][2]);
	PlayerTextDrawShow(playerid, uiSpeedometer[playerid][3]);

	GameTextForPlayer(playerid, "PRESS 2 TO SELECT", 3000, 3);
	return 1;
}

stock Speedometer_ShowInfoPanel(const playerid, bool:status)
{
	if (!status)
	{
		for (new i = 4; i <= 7; i++)
		{
			PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][i]);
			uiSpeedometer[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		}
		
		for (new j = 17; j <= 20; j++)
		{
			PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][j]);
			uiSpeedometer[playerid][j] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		}

		PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][1]);
		uiSpeedometer[playerid][1] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		return 1;
	}

	uiSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 345.499694, 349.489013, "box");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][1], 0.000000, 5.950000);
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][1], 457.800048, 0.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, uiSpeedometer[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, uiSpeedometer[playerid][1], 153);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][1], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][1], 1);

	uiSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 400.900146, 348.466735, "_");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][4], 0.123500, 0.623111);
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][4], 0.000000, 307.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][4], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][4], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][4], 1);

	uiSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 402.500000, 342.911132, "");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][5], 57.000000, 66.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][5], 0x00000000);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][5], 5);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][5], 0);
	PlayerTextDrawSetPreviewModel(playerid, uiSpeedometer[playerid][5], 411);
	PlayerTextDrawSetPreviewRot(playerid, uiSpeedometer[playerid][5], -10.000000, 0.000000, -35.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, uiSpeedometer[playerid][5], 1, 1);

	uiSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 350.000000, 402.644470, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][6], 102.899551, 4.390007);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][6], 16711935);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][6], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][6], 0);

	uiSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 399.299987, 395.911254, "_");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][7], 0.140000, 0.747555);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][7], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][7], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][7], 1);

	uiSpeedometer[playerid][17] = CreatePlayerTextDraw(playerid, 358.998840, 357.233428, "_");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][17], 0.200500, 1.195554);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][17], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][17], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][17], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][17], 1);

	uiSpeedometer[playerid][18] = CreatePlayerTextDraw(playerid, 346.000000, 367.800018, "");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][18], 15.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][18], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][18], 0x00000000);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][18], 5);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][18], 0);
	PlayerTextDrawSetPreviewModel(playerid, uiSpeedometer[playerid][18], 1650);
	PlayerTextDrawSetPreviewRot(playerid, uiSpeedometer[playerid][18], 0.000000, 0.000000, 0.000000, 1.000000);

	uiSpeedometer[playerid][19] = CreatePlayerTextDraw(playerid, 359.298980, 371.022338, "45l");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][19], 0.149000, 0.834665);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][19], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][19], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][19], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][19], 1);

	uiSpeedometer[playerid][20] = CreatePlayerTextDraw(playerid, 338.399993, 360.155914, "particle:lamp_shad_64");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][20], 134.000000, -13.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][20], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][20], 128);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][20], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][20], 4);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][20], 0);

	for (new i = 4; i <= 7; i++)
		PlayerTextDrawShow(playerid, uiSpeedometer[playerid][i]);
	
	for (new j = 17; j <= 20; j++)
		PlayerTextDrawShow(playerid, uiSpeedometer[playerid][j]);

	PlayerTextDrawShow(playerid, uiSpeedometer[playerid][1]);
	GameTextForPlayer(playerid, "PRESS H TO SHOW MENU", 3000, 3);
	return 1;
}

stock Speedometer_ShowMenuPanel(const playerid, bool:status)
{
	if (!status)
	{
		for (new i = 8; i <= 16; i++)
		{
			PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][i]);
			uiSpeedometer[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		}

		PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][21]);
		PlayerTextDrawDestroy(playerid, uiSpeedometer[playerid][22]);
		uiSpeedometer[playerid][21] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		uiSpeedometer[playerid][22] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
		return 1;
	}

	uiSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 461.800201, 349.588958, "box");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][8], 0.000000, 5.899996);
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][8], 538.799804, 0.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][8], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][8], -1);
	PlayerTextDrawUseBox(playerid, uiSpeedometer[playerid][8], 1);
	PlayerTextDrawBoxColor(playerid, uiSpeedometer[playerid][8], 153);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][8], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][8], 1);

	uiSpeedometer[playerid][9] = CreatePlayerTextDraw(playerid, 461.800201, 349.588958, "box");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][9], 0.000000, 5.749996);
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][9], 459.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][9], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][9], -1);
	PlayerTextDrawUseBox(playerid, uiSpeedometer[playerid][9], 1);
	PlayerTextDrawBoxColor(playerid, uiSpeedometer[playerid][9], 153);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][9], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][9], 1);

	uiSpeedometer[playerid][10] = CreatePlayerTextDraw(playerid, 479.000000, 349.911193, "kmh");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][10], 8.00, 20.00);
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][10], 0.198000, 0.840888);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][10], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][10], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][10], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][10], true);

	uiSpeedometer[playerid][11] = CreatePlayerTextDraw(playerid, 522.399475, 349.911193, "mph");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][11], 8.00, 20.00);
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][11], 0.198000, 0.840888);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][11], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][11], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][11], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][11], true);

	uiSpeedometer[playerid][12] = CreatePlayerTextDraw(playerid, 478.699493, 364.300140, "FLD");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][12], 8.00, 20.00);
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][12], 0.198000, 0.840888);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][12], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][12], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][12], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][12], true);

	uiSpeedometer[playerid][13] = CreatePlayerTextDraw(playerid, 478.699493, 373.700714, "RLD");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][13], 8.00, 20.00);
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][13], 0.198000, 0.840888);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][13], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][13], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][13], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][13], true);

	uiSpeedometer[playerid][14] = CreatePlayerTextDraw(playerid, 522.698913, 373.700714, "RRD");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][14], 8.00, 20.00);
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][14], 0.198000, 0.840888);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][14], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][14], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][14], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][14], true);

	uiSpeedometer[playerid][15] = CreatePlayerTextDraw(playerid, 522.698913, 364.000122, "FRD");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][15], 8.00, 20.00);
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][15], 0.198000, 0.840888);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][15], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][15], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][15], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][15], true);

	uiSpeedometer[playerid][16] = CreatePlayerTextDraw(playerid, 500.098968, 343.544586, "MENU");
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][16], 0.128500, 0.753776);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][16], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][16], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][16], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][16], 1);

	uiSpeedometer[playerid][21] = CreatePlayerTextDraw(playerid, 456.599853, 386.367095, "particle:lamp_shad_64");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][21], 89.000000, 19.000000);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][21], 1);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][21], 128);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][21], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][21], 4);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][21], 0);

	uiSpeedometer[playerid][22] = CreatePlayerTextDraw(playerid, 500.698913, 391.356414, "LIGHTS");
	PlayerTextDrawTextSize(playerid, uiSpeedometer[playerid][22], 8.00, 20.00);
	PlayerTextDrawLetterSize(playerid, uiSpeedometer[playerid][22], 0.198000, 0.840888);
	PlayerTextDrawAlignment(playerid, uiSpeedometer[playerid][22], 2);
	PlayerTextDrawColor(playerid, uiSpeedometer[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, uiSpeedometer[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, uiSpeedometer[playerid][22], 255);
	PlayerTextDrawFont(playerid, uiSpeedometer[playerid][22], 2);
	PlayerTextDrawSetProportional(playerid, uiSpeedometer[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, uiSpeedometer[playerid][22], true);

	for (new i = 8; i <= 16; i++)
		PlayerTextDrawShow(playerid, uiSpeedometer[playerid][i]);

	PlayerTextDrawShow(playerid, uiSpeedometer[playerid][21]);
	PlayerTextDrawShow(playerid, uiSpeedometer[playerid][22]);
	return 1;
}