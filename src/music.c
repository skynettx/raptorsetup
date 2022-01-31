#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "textscreen.h"
#include "main.h"

int MidiPort;
int CardType;
int BasePort;


void GetMusiccard(TXT_UNCAST_ARG(widget), void* user_data)
{
	if (strcmp(user_data, "General Midi") == 0)
	{
		CardType = 8;
		textbox_musiccard = "General Midi                      ";
	}
	if (strcmp(user_data, "Roland Sound Canvas") == 0)
	{
		CardType = 7;
		textbox_musiccard = "Roland Sound Canvas               ";
	}
	if (strcmp(user_data, "WaveBlaster") == 0)
	{
		CardType = 6;
		textbox_musiccard = "WaveBlaster                       ";
	}
	if (strcmp(user_data, "Sound Blaster AWE 32") == 0)
	{
		CardType = 9;
		textbox_musiccard = "Sound Blaster AWE 32              ";
	}
	if (strcmp(user_data, "Sound Blaster") == 0)
	{
		CardType = 5;
		textbox_musiccard = "Sound Blaster                     ";
	}
	if (strcmp(user_data, "Pro Audio Spectrum") == 0)
	{
		CardType = 4;
		textbox_musiccard = "Pro Audio Spectrum                ";
	}
	if (strcmp(user_data, "UltraSound") == 0)
	{
		CardType = 3;
		textbox_musiccard = "Gravis Ultra Sound                ";
	}
	if (strcmp(user_data, "Adlib") == 0)
	{
		CardType = 2;
		textbox_musiccard = "Adlib                             ";
	}
	if (strcmp(user_data, "NONE") == 0)
	{
		CardType = 1000;
		textbox_musiccard = "None                              ";
	}
	
	TXT_ClearTable(infotable);
	infotable = TXT_NewTable(2);
	TXT_AddWidgets(infotable,
		TXT_NewLabel("Control Type  : "),
		TXT_NewLabel(textbox_control),
		TXT_NewLabel("Music Card    : "),
		TXT_NewLabel(textbox_musiccard),
		TXT_NewLabel("Sound FX Card : "),
		TXT_NewLabel(textbox_soundfx),
		NULL);
	TXT_AddWidget(infowindow, infotable);
}

void GetMusicGMPort(TXT_UNCAST_ARG(widget), void* user_data)
{
	BasePort = 0;

	if (strcmp(user_data, "220") == 0)
		MidiPort = 220;
	if (strcmp(user_data, "230") == 0)
		MidiPort = 230;
	if (strcmp(user_data, "240") == 0)
		MidiPort = 240;
	if (strcmp(user_data, "250") == 0)
		MidiPort = 250;
	if (strcmp(user_data, "300") == 0)
		MidiPort = 300;
	if (strcmp(user_data, "320") == 0)
		MidiPort = 320;
	if (strcmp(user_data, "330") == 0)
		MidiPort = 330;
	if (strcmp(user_data, "332") == 0)
		MidiPort = 332;
	if (strcmp(user_data, "334") == 0)
		MidiPort = 334;
	if (strcmp(user_data, "336") == 0)
		MidiPort = 336;
	if (strcmp(user_data, "340") == 0)
		MidiPort = 340;
	if (strcmp(user_data, "360") == 0)
		MidiPort = 360;
}

void GetMusicBasePort(TXT_UNCAST_ARG(widget), void* user_data)
{
	MidiPort = 0;

	if (strcmp(user_data, "210") == 0)
		BasePort = 210;
	if (strcmp(user_data, "220") == 0)
		BasePort = 220;
	if (strcmp(user_data, "230") == 0)
		BasePort = 230;
	if (strcmp(user_data, "240") == 0)
		BasePort = 240;
	if (strcmp(user_data, "250") == 0)
		BasePort = 250;
	if (strcmp(user_data, "260") == 0)
		BasePort = 260;
	if (strcmp(user_data, "280") == 0)
		BasePort = 280;
}
