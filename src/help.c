#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "textscreen.h"

void MainMenuHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Select Music Card") == 0)
    {
        TXT_SetHelpLabel(" Select Sound Card that will play Music");
    }

    if (strcmp(user_data, "Select FX Card") == 0)
    {
        TXT_SetHelpLabel(" Select Sound Card that will play Sound FX");
    }

    if (strcmp(user_data, "Select Control") == 0)
    {
        TXT_SetHelpLabel(" Select Controller Type ( Mouse / Joystick / Keyboard )");
    }

    if (strcmp(user_data, "Controller Config") == 0)
    {
        TXT_SetHelpLabel(" Configure Keyboard / Mouse / Joystick Layout");
    }

    if (strcmp(user_data, "Additional Features") == 0)
    {
        TXT_SetHelpLabel(" Configure Additional Features Video / Audio / Input");
    }

    if (strcmp(user_data, "Save Settings") == 0)
    {
        TXT_SetHelpLabel(" Save Current Settings as Defaults");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void AdditionalFeaturesHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Select Fullscreen") == 0)
    {
        TXT_SetHelpLabel("Select Fullscreen Mode On / Off");
    }

    if (strcmp(user_data, "Select Aspect Ratio") == 0)
    {
        TXT_SetHelpLabel("Select Aspect Ratio Correction On / Off");
    }

    if (strcmp(user_data, "Select Text Mode Fullscreen") == 0)
    {
        TXT_SetHelpLabel("Select Text Mode Fullscreen On / Off");
    }

    if (strcmp(user_data, "Select System Midi") == 0)
    {
        TXT_SetHelpLabel("Select System Midi On / Off");
    }

    if (strcmp(user_data, "Select Alsa Client") == 0)
    {
        TXT_SetHelpLabel("Enter the Client Number for Alsa Client");
    }

    if (strcmp(user_data, "Select Alsa Port") == 0)
    {
        TXT_SetHelpLabel("Enter the Port Number for Alsa Port");
    }

    if (strcmp(user_data, "Type in Soundfont") == 0)
    {
        TXT_SetHelpLabel("Enter the file name for the GM compatible soundfont in SF2 format");
    }

    if (strcmp(user_data, "Select Haptic") == 0)
    {
        TXT_SetHelpLabel("Select Haptic for Controller On / Off");
    }

    if (strcmp(user_data, "Select New Joystick Menu Input") == 0)
    {
        TXT_SetHelpLabel("Select New Joystick Menu Input On / Off");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void GetControlKeyboardHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Select Key Up") == 0)
    {
        TXT_SetHelpLabel("Move ship forward");
    }

    if (strcmp(user_data, "Select Key Down") == 0)
    {
        TXT_SetHelpLabel("Move ship backwards");
    }

    if (strcmp(user_data, "Select Key Left") == 0)
    {
        TXT_SetHelpLabel("Move ship to the left");
    }

    if (strcmp(user_data, "Select Key Right") == 0)
    {
        TXT_SetHelpLabel("Move ship to the right");
    }

    if (strcmp(user_data, "Select Key Fire") == 0)
    {
        TXT_SetHelpLabel("Fire main weapons");
    }

    if (strcmp(user_data, "Select Key Change Special") == 0)
    {
        TXT_SetHelpLabel("Fire special weapons the you pickup/buy");
    }

    if (strcmp(user_data, "Select Mega Bomb") == 0)
    {
        TXT_SetHelpLabel("Change to next available special weapon");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Select") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Select");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press F10 to Accept");
    }
}

void GetControlMouseHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Select Mouse Fire") == 0)
    {
        TXT_SetHelpLabel("Fire main weapons");
    }

    if (strcmp(user_data, "Select Mouse Change Weapon") == 0)
    {
        TXT_SetHelpLabel("Change to next available special weapon");
    }

    if (strcmp(user_data, "Select Mouse Mega Bomb") == 0)
    {
        TXT_SetHelpLabel("Launch a Mega Bomb");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Select") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Select");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press F10 to Accept");
    }
}

void GetControlJoystickHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Select Joystick Fire") == 0)
    {
        TXT_SetHelpLabel("Fire main weapons");
    }

    if (strcmp(user_data, "Select Joystick Change Special") == 0)
    {
        TXT_SetHelpLabel("Change to the next available special weapon");
    }

    if (strcmp(user_data, "Select Joystick Mega") == 0)
    {
        TXT_SetHelpLabel("Fires a Mega Bomb");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Select") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Select");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press F10 to Accept");
    }
}

void ControlButtonConfigHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Config Keyboard") == 0)
    {
        TXT_SetHelpLabel(" Setup New Keyboard Layout");
    }

    if (strcmp(user_data, "Config Mouse") == 0)
    {
        TXT_SetHelpLabel("Configure Mouse Button Layout");
    }

    if (strcmp(user_data, "Config Joystick") == 0)
    {
        TXT_SetHelpLabel("Configure Joystick Button Layout");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void ControlHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Keyboard") == 0)
    {
        TXT_SetHelpLabel(" Use Keyboard for All Controls");
    }

    if (strcmp(user_data, "Mouse") == 0)
    {
        TXT_SetHelpLabel(" Use Mouse for Main control");
    }

    if (strcmp(user_data, "Joystick") == 0)
    {
        TXT_SetHelpLabel(" Use Joystick for Main control");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void InputHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }
}

void MusicCardHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "General Midi") == 0)
    {
        TXT_SetHelpLabel("MPU-401 General MIDI");
    }

    if (strcmp(user_data, "Roland Sound Canvas") == 0)
    {
        TXT_SetHelpLabel("Roland Sound Canvas");
    }

    if (strcmp(user_data, "WaveBlaster") == 0)
    {
        TXT_SetHelpLabel(" WaveBlaster");
    }

    if (strcmp(user_data, "Sound Blaster AWE 32") == 0)
    {
        TXT_SetHelpLabel(" AWE 32 Sound Blaster");
    }

    if (strcmp(user_data, "Sound Blaster") == 0)
    {
        TXT_SetHelpLabel("Sound Blaster, Sound Blaster 16, Sound Blaster AWE32 and Sound Blaster Pro");
    }

    if (strcmp(user_data, "Pro Audio Spectrum") == 0)
    {
        TXT_SetHelpLabel(" Pro Audio Spectrum");
    }

    if (strcmp(user_data, "UltraSound") == 0)
    {
        TXT_SetHelpLabel("Gravis UltraSound");
    }

    if (strcmp(user_data, "Adlib") == 0)
    {
        TXT_SetHelpLabel("Adlib and 100% compatibles");
    }

    if (strcmp(user_data, "NONE") == 0)
    {
        TXT_SetHelpLabel(" Do not use any Sound");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void MusicCardSBHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "210") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 210");
    }

    if (strcmp(user_data, "220") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 220");
    }

    if (strcmp(user_data, "230") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 230");
    }

    if (strcmp(user_data, "240") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 240");
    }

    if (strcmp(user_data, "250") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 250");
    }

    if (strcmp(user_data, "260") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 260");
    }

    if (strcmp(user_data, "280") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 280");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void MusicCardGMSCWBSB32Help(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "220") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 220");
    }

    if (strcmp(user_data, "230") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 230");
    }

    if (strcmp(user_data, "240") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 240");
    }

    if (strcmp(user_data, "250") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 250");
    }

    if (strcmp(user_data, "300") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 300");
    }

    if (strcmp(user_data, "320") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 320");
    }

    if (strcmp(user_data, "330") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 330");
    }

    if (strcmp(user_data, "332") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 332");
    }

    if (strcmp(user_data, "334") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 334");
    }

    if (strcmp(user_data, "336") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 336");
    }

    if (strcmp(user_data, "340") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 340");
    }

    if (strcmp(user_data, "360") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 360");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void FXCardHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "General Midi") == 0)
    {
        TXT_SetHelpLabel(" Select for General Midi Sound FX - MPU-401 General Midi");
    }

    if (strcmp(user_data, "Sound Canvas") == 0)
    {
        TXT_SetHelpLabel(" Select for Roland Sound Canvas Sound FX ( Uses Build in FX on card )");
    }

    if (strcmp(user_data, "Sound Blaster") == 0)
    {
        TXT_SetHelpLabel(" Digital Sound FX  - Sound Blaster, Pro, 16 and AWE32");
    }

    if (strcmp(user_data, "Pro Audio Spectrum") == 0)
    {
        TXT_SetHelpLabel(" Digital Sound FX  - Pro Audio Spectrum");
    }

    if (strcmp(user_data, "UltraSound") == 0)
    {
        TXT_SetHelpLabel(" Gravis UltraSound Digital Sound FX");
    }

    if (strcmp(user_data, "Adlib") == 0)
    {
        TXT_SetHelpLabel(" Sound FX ( Adlib and 100% compatibles )");
    }

    if (strcmp(user_data, "PC Speaker") == 0)
    {
        TXT_SetHelpLabel(" PC speaker Sound FX");
    }

    if (strcmp(user_data, "NONE") == 0)
    {
        TXT_SetHelpLabel(" Select for No Sound FX");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void SoundCardGMHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "220") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 220");
    }

    if (strcmp(user_data, "230") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 230");
    }

    if (strcmp(user_data, "240") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 240");
    }

    if (strcmp(user_data, "250") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 250");
    }

    if (strcmp(user_data, "300") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 300");
    }

    if (strcmp(user_data, "320") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 320");
    }

    if (strcmp(user_data, "330") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 330");
    }

    if (strcmp(user_data, "332") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 332");
    }

    if (strcmp(user_data, "334") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 334");
    }

    if (strcmp(user_data, "336") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 336");
    }

    if (strcmp(user_data, "340") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 340");
    }

    if (strcmp(user_data, "360") == 0)
    {
        TXT_SetHelpLabel(" Sets Midi port to 360");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void SoundCardSBHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "210") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 210");
    }

    if (strcmp(user_data, "220") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 220");
    }

    if (strcmp(user_data, "230") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 230");
    }

    if (strcmp(user_data, "240") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 240");
    }

    if (strcmp(user_data, "250") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 250");
    }

    if (strcmp(user_data, "260") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 260");
    }

    if (strcmp(user_data, "280") == 0)
    {
        TXT_SetHelpLabel(" Sets PORT address to 280");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void SoundCardIrqHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "2") == 0)
    {
        TXT_SetHelpLabel(" Sets IRQ to 2");
    }

    if (strcmp(user_data, "5") == 0)
    {
        TXT_SetHelpLabel(" Sets IRQ to 5");
    }

    if (strcmp(user_data, "7") == 0)
    {
        TXT_SetHelpLabel(" Sets IRQ to 7");
    }

    if (strcmp(user_data, "10") == 0)
    {
        TXT_SetHelpLabel(" Sets IRQ to 10");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void SoundCardDmaHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "0") == 0)
    {
        TXT_SetHelpLabel(" Sets DMA to 0");
    }

    if (strcmp(user_data, "1") == 0)
    {
        TXT_SetHelpLabel(" Sets DMA to 1");
    }

    if (strcmp(user_data, "3") == 0)
    {
        TXT_SetHelpLabel(" Sets DMA to 3");
    }

    if (strcmp(user_data, "5") == 0)
    {
        TXT_SetHelpLabel(" Sets DMA to 5");
    }

    if (strcmp(user_data, "6") == 0)
    {
        TXT_SetHelpLabel(" Sets DMA to 6");
    }

    if (strcmp(user_data, "7") == 0)
    {
        TXT_SetHelpLabel(" Sets DMA to 7");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}

void SoundCardChannelsHelp(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "One") == 0)
    {
        TXT_SetHelpLabel(" Will play one Digital sound effect at a time");
    }

    if (strcmp(user_data, "Two") == 0)
    {
        TXT_SetHelpLabel(" Will play two Digital sound effects at a time");
    }

    if (strcmp(user_data, "Three") == 0)
    {
        TXT_SetHelpLabel(" Will play three Digital sound effects at a time");
    }

    if (strcmp(user_data, "Four") == 0)
    {
        TXT_SetHelpLabel(" Will play four Digital sound effects at a time");
    }

    if (strcmp(user_data, "Five") == 0)
    {
        TXT_SetHelpLabel(" Will play five Digital sound effects at a time");
    }

    if (strcmp(user_data, "Six") == 0)
    {
        TXT_SetHelpLabel(" Will play six Digital sound effects at a time");
    }

    if (strcmp(user_data, "Seven") == 0)
    {
        TXT_SetHelpLabel(" Will play seven Digital sound effects at a time");
    }

    if (strcmp(user_data, "Eight") == 0)
    {
        TXT_SetHelpLabel(" Will play eight Digital sound effects at a time");
    }

    if (strcmp(user_data, "Abort") == 0)
    {
        TXT_SetHelpLabel(" Press ESC to Abort");
    }

    if (strcmp(user_data, "Accept") == 0)
    {
        TXT_SetHelpLabel(" Press ENTER to Accept");
    }
}