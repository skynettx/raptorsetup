#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <io.h>
#endif // _WIN32
#ifdef __linux__
#include <unistd.h>
#include <sys/io.h>
#define PATH_MAX        4096
#endif // __linux__
#ifdef __APPLE__
#include <unistd.h>
#define PATH_MAX        4096
#endif // __APPLE__

#include "textscreen.h"
#include "prefapi.h"
#include "main.h"
#include "music.h"
#include "sound.h"
#include "input.h"

#ifdef _MSC_VER
#define PATH_MAX        4096
#define access _access
#endif

int setupflag, writesetupflag;
char* textbox_control = NULL;
char* textbox_musiccard = NULL;
char* textbox_soundfx = NULL;
int hasdatapath = 0;
char g_data_path[PATH_MAX];
char g_setup_path[PATH_MAX];
int controltype;
int musiccard;
int soundfxcard;
int fullscreen, aspect_ratio, txt_fullscreen, haptic, joy_ipt_MenuNew, sys_midi, alsaclient, alsaport;
int keymoveup, keymovedown, keymoveleft, keymoveright, keyfire, keyspecial, keymega;
static char soundfont[128];
static char* sf;

txt_window_t* mainwindow;
txt_window_t* infowindow;
txt_table_t* infotable;

char* stringduplicate(const char* source)
{
    char* destination = malloc(strlen(source) + 1);
    if (destination == NULL)
        return NULL;
    strcpy(destination, source);
    return destination;
}

void ClosePwnBox(TXT_UNCAST_ARG(widget), TXT_UNCAST_ARG(window))
{
    TXT_CAST_ARG(txt_window_t, window);

    TXT_CloseWindow(window);
}
///////////////////////////////////////////////////Check Settings from Setup.ini///////////////////////////////////////////////////////////////
void CheckSetupSettings(void)
{
    switch (controltype)
    {
    case 0:
        textbox_control = "Keyboard                    ";
        break;
    case 1:
        textbox_control = "Mouse                       ";
        break;
    case 2:
        textbox_control = "Joystick                    ";
        break;
    default:
        textbox_control = "None                        ";
        break;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    switch (musiccard)
    {
    case 0:
        textbox_musiccard = "None                        ";
        break;
    case 2:
        textbox_musiccard = "Adlib                       ";
        break;
    case 3:
        textbox_musiccard = "Gravis Ultra Sound          ";
        break;
    case 4:
        textbox_musiccard = "Pro Audio Spectrum          ";
        break;
    case 5:
        textbox_musiccard = "Sound Blaster               ";
        break;
    case 6:
        textbox_musiccard = "WaveBlaster                 ";
        break;
    case 7:
        textbox_musiccard = "Roland Sound Canvas         ";
        break;
    case 8:
        textbox_musiccard = "General Midi                ";
        break;
    case 9:
        textbox_musiccard = "Sound Blaster AWE 32        ";
        break;
    default:
        textbox_musiccard = "None                        ";
        break;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    switch (soundfxcard)
    {
    case 0:
        textbox_soundfx = "None                        ";
        break;
    case 1:
        textbox_soundfx = "PC Speaker                  ";
        break;
    case 2:
        textbox_soundfx = "Adlib                       ";
        break;
    case 3:
        textbox_soundfx = "Gravis Ultra Sound          ";
        break;
    case 4:
        textbox_soundfx = "Pro Audio Spectrum          ";
        break;
    case 5:
        textbox_soundfx = "Sound Blaster               ";
        break;
    case 7:
        textbox_soundfx = "Roland Sound Canvas         ";
        break;
    case 8:
        textbox_soundfx = "General Midi                ";
        break;
    default:
        textbox_soundfx = "None                        ";
        break;
    }
}
/////////////////////////////////////////////Get Settings from Setup.ini//////////////////////////////////////////////////////
void GetSetupSettings(void)
{
    controltype = INI_GetPreferenceLong("Setup", "Control", 3);
    musiccard = INI_GetPreferenceLong("Music", "CardType", 0);
    soundfxcard = INI_GetPreferenceLong("SoundFX", "CardType", 0);
    keymoveup = INI_GetPreferenceLong("Keyboard", "MoveUp", 72);
    keymovedown = INI_GetPreferenceLong("Keyboard", "MoveDn", 80);
    keymoveleft = INI_GetPreferenceLong("Keyboard", "MoveLeft", 75);
    keymoveright = INI_GetPreferenceLong("Keyboard", "MoveRight", 77);
    keyfire = INI_GetPreferenceLong("Keyboard", "Fire", 29);
    keyspecial = INI_GetPreferenceLong("Keyboard", "FireSp", 56);
    keymega = INI_GetPreferenceLong("Keyboard", "ChangeSp", 57);
    mousebfire = INI_GetPreferenceLong("Mouse", "Fire", 0);
    mousebchweapon = INI_GetPreferenceLong("Mouse", "FireSp", 1);
    mousebmega = INI_GetPreferenceLong("Mouse", "ChangeSp", 2);
    joybfire = INI_GetPreferenceLong("JoyStick", "Fire", 0);
    joybchweapon = INI_GetPreferenceLong("JoyStick", "FireSp", 1);
    joybmega = INI_GetPreferenceLong("JoyStick", "ChangeSp", 2);
    fullscreen = INI_GetPreferenceLong("Video", "fullscreen", 0);
    aspect_ratio = INI_GetPreferenceLong("Video", "aspect_ratio_correct", 1);
    txt_fullscreen = INI_GetPreferenceLong("Video", "txt_fullscreen", 0);
    haptic = INI_GetPreferenceLong("Setup", "Haptic", 1);
    joy_ipt_MenuNew = INI_GetPreferenceLong("Setup", "joy_ipt_MenuNew", 0);
    sys_midi = INI_GetPreferenceLong("Setup", "sys_midi", 0);
    alsaclient = INI_GetPreferenceLong("Setup", "alsa_output_client", 128);
    alsaport = INI_GetPreferenceLong("Setup", "alsa_output_port", 0);
    sf = (char*)INI_GetPreference("Setup", "SoundFont", soundfont, 127, "SoundFont.sf2");
}
/////////////////////////////////////////////Get Setup.ini/////////////////////////////////////////////////////////////////////
const char* RAP_DataPath(void)
{
    memset(g_data_path, 0, sizeof(g_data_path));
    hasdatapath = 0;
    strcpy(g_setup_path, "SETUP.INI");
    return g_data_path;
}

const char* RAP_GetSetupPath(void)
{
    return g_setup_path;
}
////////////////////////////////////////////////Save Settings to SETUP.INI/////////////////////////////////////////////////////
void SaveSettings(TXT_UNCAST_ARG(widget), void* user_data)
{
    INI_PutPreferenceLong("Setup", "Detail", 1);

    if (ControllerType)                                                         //Save Controller Type to SETUP.INI
    {
        INI_PutPreferenceLong("Setup", "Control", ControllerType);
    }
    if (ControllerType == 1000)
    {
        INI_PutPreferenceLong("Setup", "Control", 0);
    }

    INI_PutPreferenceLong("Setup", "Haptic", haptic);                           //Save Additional Feature Haptic to SETUP.INI
    INI_PutPreferenceLong("Setup", "joy_ipt_MenuNew", joy_ipt_MenuNew);         //Save Additional Feature joy_ipt_MenuNew to SETUP.INI
    INI_PutPreferenceLong("Setup", "sys_midi", sys_midi);                       //Save Additional Feature sys_midi to SETUP.INI
    INI_PutPreferenceLong("Setup", "alsa_output_client", alsaclient);           //Save Additional Feature alsa_output_client to SETUP.INI
    INI_PutPreferenceLong("Setup", "alsa_output_port", alsaport);               //Save Additional Feature alsa_output_port to SETUP.INI
    INI_PutPreference("Setup", "SoundFont", sf);                                //Save Additional Feature soundfont to SETUP.INI
    
    if (CardType)                                                               //Save Music Card to SETUP.INI
    {
        INI_PutPreferenceLong("Music", "Volume", 85);
        INI_PutPreferenceLong("Music", "CardType", CardType);
    }
    if (CardType == 4 || CardType == 3)
    {
        INI_DeletePreference("Music", "MidiPort");
        INI_PutPreferenceLong("Music", "BasePort", 220);
        INI_PutPreferenceLong("Music", "Irq", 7);
        INI_PutPreferenceLong("Music", "Dma", 1);
    }
    if (CardType == 2)
    {
        INI_DeletePreference("Music", "MidiPort");
        INI_DeletePreference("Music", "BasePort");
        INI_DeletePreference("Music", "Irq");
        INI_DeletePreference("Music", "Dma");
    }
    if (CardType == 1000)
    {
        INI_DeletePreference("Music", "MidiPort");
        INI_DeletePreference("Music", "BasePort");
        INI_DeletePreference("Music", "Irq");
        INI_DeletePreference("Music", "Dma");
        INI_PutPreferenceLong("Music", "Volume", 85);
        INI_PutPreferenceLong("Music", "CardType", 0);
    }
    if (BasePort)
    {
        INI_DeletePreference("Music", "MidiPort");
        INI_PutPreferenceLong("Music", "BasePort", BasePort);
        INI_PutPreferenceLong("Music", "Irq", 7);
        INI_PutPreferenceLong("Music", "Dma", 1);
    }
    if (MidiPort)
    {
        INI_DeletePreference("Music", "BasePort");
        INI_DeletePreference("Music", "Irq");
        INI_DeletePreference("Music", "Dma");
        INI_PutPreferenceLong("Music", "MidiPort", MidiPort);
    }

    if (SoundCardType)                                                              //Save Sound Card to SETUP.INI
    {
        INI_PutPreferenceLong("SoundFX", "Volume", 85);
        INI_PutPreferenceLong("SoundFX", "CardType", SoundCardType);
    }
    if (SoundCardType == 8 || SoundCardType == 7)
    {
        INI_DeletePreference("SoundFX", "BasePort");
        INI_DeletePreference("SoundFX", "Irq");
        INI_DeletePreference("SoundFX", "Dma");
        INI_PutPreferenceLong("SoundFX", "Channels", 6);
        INI_PutPreferenceLong("SoundFX", "MidiPort", SoundMidiPort);
    }
    if (SoundCardType == 5)
    {
        INI_DeletePreference("SoundFX", "MidiPort");
        INI_PutPreferenceLong("SoundFX", "Channels", SoundChannels);
        INI_PutPreferenceLong("SoundFX", "BasePort", SoundBasePort);
        INI_PutPreferenceLong("SoundFX", "Irq", SoundIrq);
        if (SoundDma == 1000)
            SoundDma = 0;
        INI_PutPreferenceLong("SoundFX", "Dma", SoundDma);
    }
    if (SoundCardType == 4)
    {
        INI_DeletePreference("SoundFX", "BasePort");
        INI_DeletePreference("SoundFX", "MidiPort");
        INI_DeletePreference("SoundFX", "Irq");
        INI_DeletePreference("SoundFX", "Dma");
        INI_PutPreferenceLong("SoundFX", "Channels", SoundChannels);
    }
    if (SoundCardType == 3)
    {
        INI_DeletePreference("SoundFX", "MidiPort");
        INI_PutPreferenceLong("SoundFX", "Channels", SoundChannels);
        INI_PutPreferenceLong("SoundFX", "BasePort", 220);
        INI_PutPreferenceLong("SoundFX", "Irq", 7);
        INI_PutPreferenceLong("SoundFX", "Dma", 1);
    }
    if (SoundCardType == 2)
    {
        INI_DeletePreference("SoundFX", "BasePort");
        INI_DeletePreference("SoundFX", "MidiPort");
        INI_DeletePreference("SoundFX", "Irq");
        INI_DeletePreference("SoundFX", "Dma");
        INI_PutPreferenceLong("SoundFX", "Channels", 3);
    }
    if (SoundCardType == 1)
    {
        INI_DeletePreference("SoundFX", "BasePort");
        INI_DeletePreference("SoundFX", "MidiPort");
        INI_DeletePreference("SoundFX", "Irq");
        INI_DeletePreference("SoundFX", "Dma");
        INI_PutPreferenceLong("SoundFX", "Channels", 4);
    }
    if (SoundCardType == 1000)
    {
        INI_DeletePreference("SoundFX", "BasePort");
        INI_DeletePreference("SoundFX", "MidiPort");
        INI_DeletePreference("SoundFX", "Irq");
        INI_DeletePreference("SoundFX", "Dma");
        INI_PutPreferenceLong("SoundFX", "Volume", 85);
        INI_PutPreferenceLong("SoundFX", "CardType", 0);
        INI_PutPreferenceLong("SoundFX", "Channels", 4);
    }
    if (writesetupflag && !writeflagkey)                                     //Save Defaultkeyboardlayout when SETUP.INI not in folder and layout not set
    {
        INI_PutPreferenceLong("Keyboard", "MoveUp", 72);
        INI_PutPreferenceLong("Keyboard", "MoveDn", 80);
        INI_PutPreferenceLong("Keyboard", "MoveLeft", 75);
        INI_PutPreferenceLong("Keyboard", "MoveRight", 77);
        INI_PutPreferenceLong("Keyboard", "Fire", 29);
        INI_PutPreferenceLong("Keyboard", "FireSp", 56);
        INI_PutPreferenceLong("Keyboard", "ChangeSp", 57);
        INI_PutPreferenceLong("Keyboard", "MegaFire", 54);
    }
    if (writeflagkey)                                                        //Save Keyboardlayout to SETUP.INI
    {
        INI_PutPreferenceLong("Keyboard", "MoveUp", key_up_convert);
        INI_PutPreferenceLong("Keyboard", "MoveDn", key_down_convert);
        INI_PutPreferenceLong("Keyboard", "MoveLeft", key_left_convert);
        INI_PutPreferenceLong("Keyboard", "MoveRight", key_right_convert);
        INI_PutPreferenceLong("Keyboard", "Fire", key_fire_convert);
        INI_PutPreferenceLong("Keyboard", "FireSp", key_special_convert);
        INI_PutPreferenceLong("Keyboard", "ChangeSp", key_mega_convert);
        INI_PutPreferenceLong("Keyboard", "MegaFire", 54);
    }
    if (writesetupflag && !writeflagmouse)                                  //Save Defaultmouselayout when SETUP.INI not in folder and layout not set
    {
        INI_PutPreferenceLong("Mouse", "Fire", 0);
        INI_PutPreferenceLong("Mouse", "FireSp", 1);
        INI_PutPreferenceLong("Mouse", "ChangeSp", 2);
    }
    if (writeflagmouse)                                                    //Save Mouselayout to SETUP.INI
    {
        INI_PutPreferenceLong("Mouse", "Fire", mousebfire);
        INI_PutPreferenceLong("Mouse", "FireSp", mousebchweapon);
        INI_PutPreferenceLong("Mouse", "ChangeSp", mousebmega);
    }
    if (writesetupflag && !writeflagjoy)                                  //Save Defaultjoysticklayout when SETUP.INI not in folder and layout not set
    {
        INI_PutPreferenceLong("JoyStick", "Fire", 0);
        INI_PutPreferenceLong("JoyStick", "FireSp", 1);
        INI_PutPreferenceLong("JoyStick", "ChangeSp", 2);
        INI_PutPreferenceLong("JoyStick", "MegaFire", 3);
    }
    if (writeflagjoy)                                                     //Save joysticklayout to SETUP.INI
    {
        if (writeflagjoybfire || writesetupflag)
        INI_PutPreferenceLong("JoyStick", "Fire", joybfireout);
        if (writeflagjoybchweapon || writesetupflag)
        INI_PutPreferenceLong("JoyStick", "FireSp", joybchweaponout);
        if (writeflagjoybmega || writesetupflag)
        INI_PutPreferenceLong("JoyStick", "ChangeSp", joybmegaout);

        INI_PutPreferenceLong("JoyStick", "MegaFire", 3);
    }

    INI_PutPreferenceLong("Video", "fullscreen", fullscreen);                          //Save Additional Feature fullscreen to SETUP.INI
    INI_PutPreferenceLong("Video", "aspect_ratio_correct", aspect_ratio);              //Save Additional Feature aspect_ratio_correct to SETUP.INI
    INI_PutPreferenceLong("Video", "txt_fullscreen", txt_fullscreen);                  //Save Additional Feature txt_fullscreen to SETUP.INI
}
/////////////////////////////////////////////////////////Info Window/////////////////////////////////////////////////////////
void InfoWindow(TXT_UNCAST_ARG(widget), void* user_data)
{
    CheckSetupSettings();
    
    infowindow = TXT_NewWindow("Current Configuration:                      ");
    TXT_SetWindowAction(infowindow, TXT_HORIZ_LEFT, NULL);
    TXT_SetWindowAction(infowindow, TXT_HORIZ_RIGHT, NULL);
    TXT_SetWindowPosition(infowindow, TXT_HORIZ_CENTER, TXT_VERT_TOP, TXT_SCREEN_W / 2, 2);
    
    infotable = TXT_NewTable(2);
    TXT_AddWidgets(infotable,
        TXT_NewLabel("Control Type  : "),
        TXT_NewLabel(textbox_control),
        TXT_NewLabel("Music Card    : "),
        TXT_NewLabel(textbox_musiccard),
        TXT_NewLabel("Sound FX Card : "),
        TXT_NewLabel(textbox_soundfx),
        NULL);
    
    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(infowindow, infotable);
}
////////////////////////////////////////////////Select Additional Features////////////////////////////////////////////////////////
void AdditionalFeatures(TXT_UNCAST_ARG(widget), void* user_data)
{
  txt_window_t* window;
  sf = stringduplicate(sf);

  window = TXT_NewWindow("Additional Features                                        ");
  
  TXT_SetWidgetFocus(mainwindow, 1);
  
  TXT_AddWidgets(window, TXT_NewSeparator("Video"),
  TXT_NewCheckBox("Fullscreen", &fullscreen),
  TXT_NewCheckBox("Aspect Ratio", &aspect_ratio), 
  TXT_NewCheckBox("Text Mode Fullscreen", &txt_fullscreen), NULL);
  
  TXT_AddWidgets(window, TXT_NewSeparator("Audio"),
  TXT_NewCheckBox("System Midi", &sys_midi),
  TXT_NewHorizBox(TXT_NewLabel("Alsa Output Port: "), TXT_NewIntInputBox(&alsaclient, 4),
  TXT_NewLabel(":"), TXT_NewIntInputBox(&alsaport, 1), TXT_NewLabel(" (Default = 128:0)"), NULL),
  TXT_NewHorizBox(TXT_NewLabel("TSF SoundFont Filename: "), TXT_NewInputBox(&sf, 35), NULL), NULL);
  
  TXT_AddWidgets(window, TXT_NewSeparator("Controller"),
  TXT_NewCheckBox("Haptic (Game Controller Rumble Support)", &haptic),
  TXT_NewCheckBox("New Joystick Menu Input", &joy_ipt_MenuNew), NULL);
}
////////////////////////////////////////////////Select ControlButtonConfigMain////////////////////////////////////////////////////
void ControlButtonConfig(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;

    window = TXT_NewWindow("Controller Configuration   ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 8);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("Keyboard                   "),
        button2 = TXT_NewButton("Mouse                      "),
        button3 = TXT_NewButton("Joystick                   "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetControlKeyboard, "Keyboard");
    TXT_SignalConnect(button2, "pressed", GetControlMouse, "Mouse");
    TXT_SignalConnect(button3, "pressed", GetControlJoystick, "Joystick");
   
    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}
////////////////////////////////////////////////Select ControlType/////////////////////////////////////////////////////////////
void Control(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;

    window = TXT_NewWindow("Select Controller Type      ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 40, 8);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("Keyboard                    "),
        button2 = TXT_NewButton("Mouse                       "),
        button3 = TXT_NewButton("Joystick                    "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetControl, "Keyboard");
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetControl, "Mouse");
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetControl, "Joystick");
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);

    if (setupflag)
    {
        TXT_SignalConnect(button1, "pressed", MusicCard, NULL);
        TXT_SignalConnect(button2, "pressed", MusicCard, NULL);
        TXT_SignalConnect(button3, "pressed", MusicCard, NULL);
        TXT_SignalConnect(close_button, "pressed", MusicCard, NULL);
        TXT_SignalConnect(close_button, "pressed", GetControl, "Keyboard");
    }
    
    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}
////////////////////////////////////////////////Select Sound FX Card//////////////////////////////////////////////////////////
void SoundCardChannels(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_button_t* button7;
    txt_button_t* button8;

    window = TXT_NewWindow("Number of Digital Channels ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 7);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("One                        "),
        button2 = TXT_NewButton("Two                        "),
        button3 = TXT_NewButton("Three                      "),
        button4 = TXT_NewButton("Four                       "),
        button5 = TXT_NewButton("Five                       "),
        button6 = TXT_NewButton("Six                        "),
        button7 = TXT_NewButton("Seven                      "),
        button8 = TXT_NewButton("Eight                      "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetSoundChannels, "One");
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetSoundChannels, "Two");
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetSoundChannels, "Three");
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", GetSoundChannels, "Four");
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", GetSoundChannels, "Five");
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", GetSoundChannels, "Six");
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button7, "pressed", GetSoundChannels, "Seven");
    TXT_SignalConnect(button7, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button8, "pressed", GetSoundChannels, "Eight");
    TXT_SignalConnect(button8, "pressed", ClosePwnBox, window);

    switch (SoundChannels)
    {
    case 1:
        TXT_SelectWidget(table, button1);
        break;
    case 2:
        TXT_SelectWidget(table, button2);
        break;
    case 3:
        TXT_SelectWidget(table, button3);
        break;
    case 4:
        TXT_SelectWidget(table, button4);
        break;
    case 5:
        TXT_SelectWidget(table, button5);
        break;
    case 6:
        TXT_SelectWidget(table, button6);
        break;
    case 7:
        TXT_SelectWidget(table, button7);
        break;
    case 8:
        TXT_SelectWidget(table, button8);
        break;
    default:
        TXT_SelectWidget(table, button4);
        break;
    }
    
    if (setupflag)
    {
        TXT_SignalConnect(button1, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button2, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button3, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button4, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button5, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button6, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button7, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button8, "pressed", MainMenu, NULL);
        TXT_SignalConnect(close_button, "pressed", MainMenu, NULL);
    }

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}

void SoundCardDma(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;

    window = TXT_NewWindow("Available DMA Channels     ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 6);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("0                          "),
        button2 = TXT_NewButton("1                          "),
        button3 = TXT_NewButton("3                          "),
        button4 = TXT_NewButton("5                          "),
        button5 = TXT_NewButton("6                          "),
        button6 = TXT_NewButton("7                          "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetSoundDma, "0");
    TXT_SignalConnect(button1, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetSoundDma, "1");
    TXT_SignalConnect(button2, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetSoundDma, "3");
    TXT_SignalConnect(button3, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", GetSoundDma, "5");
    TXT_SignalConnect(button4, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", GetSoundDma, "6");
    TXT_SignalConnect(button5, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", GetSoundDma, "7");
    TXT_SignalConnect(button6, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);

    switch (SoundDma)
    {
    case 1000:
        TXT_SelectWidget(table, button1);
        break;
    case 1:
        TXT_SelectWidget(table, button2);
        break;
    case 3:
        TXT_SelectWidget(table, button3);
        break;
    case 5:
        TXT_SelectWidget(table, button4);
        break;
    case 6:
        TXT_SelectWidget(table, button5);
        break;
    case 7:
        TXT_SelectWidget(table, button6);
        break;
    default:
        TXT_SelectWidget(table, button2);
        break;
    }
    
    if (setupflag)
        TXT_SignalConnect(close_button, "pressed", MainMenu, NULL);

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}

void SoundCardIrq(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;

    window = TXT_NewWindow("Available IRQs             ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 8);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("2                          "),
        button2 = TXT_NewButton("5                          "),
        button3 = TXT_NewButton("7                          "),
        button4 = TXT_NewButton("10                         "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetSoundIrq, "2");
    TXT_SignalConnect(button1, "pressed", SoundCardDma, NULL);
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetSoundIrq, "5");
    TXT_SignalConnect(button2, "pressed", SoundCardDma, NULL);
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetSoundIrq, "7");
    TXT_SignalConnect(button3, "pressed", SoundCardDma, NULL);
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", GetSoundIrq, "10");
    TXT_SignalConnect(button4, "pressed", SoundCardDma, NULL);
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);

    switch (SoundIrq)
    {
    case 2:
        TXT_SelectWidget(table, button1);
        break;
    case 5:
        TXT_SelectWidget(table, button2);
        break;
    case 7:
        TXT_SelectWidget(table, button3);
        break;
    case 10:
        TXT_SelectWidget(table, button4);
        break;
    default:
        TXT_SelectWidget(table, button3);
        break;
    }
    
    if (setupflag)
    TXT_SignalConnect(close_button, "pressed", MainMenu, NULL);

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}

void SoundCardSB(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_button_t* button7;

    GetSoundcard(0, user_data);

    window = TXT_NewWindow("Available PORTs            ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 6);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("210                        "),
        button2 = TXT_NewButton("220                        "),
        button3 = TXT_NewButton("230                        "),
        button4 = TXT_NewButton("240                        "),
        button5 = TXT_NewButton("250                        "),
        button6 = TXT_NewButton("260                        "),
        button7 = TXT_NewButton("280                        "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetSoundBasePort, "210");
    TXT_SignalConnect(button1, "pressed", SoundCardIrq, NULL);
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetSoundBasePort, "220");
    TXT_SignalConnect(button2, "pressed", SoundCardIrq, NULL);
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetSoundBasePort, "230");
    TXT_SignalConnect(button3, "pressed", SoundCardIrq, NULL);
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", GetSoundBasePort, "240");
    TXT_SignalConnect(button4, "pressed", SoundCardIrq, NULL);
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", GetSoundBasePort, "250");
    TXT_SignalConnect(button5, "pressed", SoundCardIrq, NULL);
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", GetSoundBasePort, "260");
    TXT_SignalConnect(button6, "pressed", SoundCardIrq, NULL);
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button7, "pressed", GetSoundBasePort, "280");
    TXT_SignalConnect(button7, "pressed", SoundCardIrq, NULL);
    TXT_SignalConnect(button7, "pressed", ClosePwnBox, window);

    switch (SoundBasePort)
    {
    case 210:
        TXT_SelectWidget(table, button1);
        break;
    case 220:
        TXT_SelectWidget(table, button2);
        break;
    case 230:
        TXT_SelectWidget(table, button3);
        break;
    case 240:
        TXT_SelectWidget(table, button4);
        break;
    case 250:
        TXT_SelectWidget(table, button5);
        break;
    case 260:
        TXT_SelectWidget(table, button6);
        break;
    case 280:
        TXT_SelectWidget(table, button7);
        break;
    default:
        TXT_SelectWidget(table, button2);
        break;
    }
    
    if (setupflag)
        TXT_SignalConnect(close_button, "pressed", MainMenu, NULL);

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}

void SoundCardGM(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_button_t* button7;
    txt_button_t* button8;
    txt_button_t* button9;
    txt_button_t* button10;
    txt_button_t* button11;
    txt_button_t* button12;

    GetSoundcard(0, user_data);

    window = TXT_NewWindow("Available MIDI Ports       ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 3);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("220                        "),
        button2 = TXT_NewButton("230                        "),
        button3 = TXT_NewButton("240                        "),
        button4 = TXT_NewButton("250                        "),
        button5 = TXT_NewButton("300                        "),
        button6 = TXT_NewButton("320                        "),
        button7 = TXT_NewButton("330                        "),
        button8 = TXT_NewButton("332                        "),
        button9 = TXT_NewButton("334                        "),
        button10 = TXT_NewButton("336                        "),
        button11 = TXT_NewButton("340                        "),
        button12 = TXT_NewButton("360                        "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetSoundGMPort, "220");
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetSoundGMPort, "230");
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetSoundGMPort, "240");
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", GetSoundGMPort, "250");
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", GetSoundGMPort, "300");
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", GetSoundGMPort, "320");
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button7, "pressed", GetSoundGMPort, "330");
    TXT_SignalConnect(button7, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button8, "pressed", GetSoundGMPort, "332");
    TXT_SignalConnect(button8, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button9, "pressed", GetSoundGMPort, "334");
    TXT_SignalConnect(button9, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button10, "pressed", GetSoundGMPort, "336");
    TXT_SignalConnect(button10, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button11, "pressed", GetSoundGMPort, "340");
    TXT_SignalConnect(button11, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button12, "pressed", GetSoundGMPort, "360");
    TXT_SignalConnect(button12, "pressed", ClosePwnBox, window);

    switch (SoundMidiPort)
    {
    case 220:
        TXT_SelectWidget(table, button1);
        break;
    case 230:
        TXT_SelectWidget(table, button2);
        break;
    case 240:
        TXT_SelectWidget(table, button3);
        break;
    case 250:
        TXT_SelectWidget(table, button4);
        break;
    case 300:
        TXT_SelectWidget(table, button5);
        break;
    case 320:
        TXT_SelectWidget(table, button6);
        break;
    case 330:
        TXT_SelectWidget(table, button7);
        break;
    case 332:
        TXT_SelectWidget(table, button8);
        break;
    case 334:
        TXT_SelectWidget(table, button9);
        break;
    case 336:
        TXT_SelectWidget(table, button10);
        break;
    case 340:
        TXT_SelectWidget(table, button11);
        break;
    case 360:
        TXT_SelectWidget(table, button12);
        break;
    default:
        TXT_SelectWidget(table, button7);
        break;
    }
    
    if (setupflag)
    {
        TXT_SignalConnect(button1, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button2, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button3, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button4, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button5, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button6, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button7, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button8, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button9, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button10, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button11, "pressed", MainMenu, NULL);
        TXT_SignalConnect(button12, "pressed", MainMenu, NULL);
        TXT_SignalConnect(close_button, "pressed", MainMenu, NULL);
    }

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}

void SoundCardProUl(TXT_UNCAST_ARG(widget), void* user_data)
{
    GetSoundcard(0, user_data);
}

void SoundCardAdPCNo(TXT_UNCAST_ARG(widget), void* user_data)
{
    GetSoundcard(0, user_data);
    if (setupflag)
        MainMenu(0, 0);
}

void FXCard(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_button_t* button7;
    txt_button_t* button8;

    window = TXT_NewWindow("Select Sound FX Device   ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 5);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("General Midi             "),
        button2 = TXT_NewButton("Sound Canvas             "),
        button3 = TXT_NewButton("Sound Blaster            "),
        button4 = TXT_NewButton("Pro Audio Spectrum       "),
        button5 = TXT_NewButton("UltraSound               "),
        button6 = TXT_NewButton("Adlib                    "),
        button7 = TXT_NewButton("PC Speaker               "),
        button8 = TXT_NewButton("NONE                     "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", SoundCardGM, "General Midi");
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", SoundCardGM, "Sound Canvas");
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", SoundCardSB, "Sound Blaster");
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", SoundCardProUl, "Pro Audio Spectrum");
    TXT_SignalConnect(button4, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", SoundCardProUl, "UltraSound");
    TXT_SignalConnect(button5, "pressed", SoundCardChannels, NULL);
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", SoundCardAdPCNo, "Adlib");
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button7, "pressed", SoundCardAdPCNo, "PC Speaker");
    TXT_SignalConnect(button7, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button8, "pressed", SoundCardAdPCNo, "NONE");
    TXT_SignalConnect(button8, "pressed", ClosePwnBox, window);

    switch (SoundCardType)
    {
    case 1:
        TXT_SelectWidget(table, button7);
        break;
    case 2:
        TXT_SelectWidget(table, button6);
        break;
    case 3:
        TXT_SelectWidget(table, button5);
        break;
    case 4:
        TXT_SelectWidget(table, button4);
        break;
    case 5:
        TXT_SelectWidget(table, button3);
        break;
    case 7:
        TXT_SelectWidget(table, button2);
        break;
    case 8:
        TXT_SelectWidget(table, button1);
        break;
    case 1000:
        TXT_SelectWidget(table, button8);
        break;
    default:
        TXT_SelectWidget(table, button3);
        break;
    }
    
    if (setupflag)
        TXT_SignalConnect(close_button, "pressed", MainMenu, NULL);

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}
///////////////////////////////////////Select Music Card////////////////////////////////////////////////////////////
void MusicCardGMSCWBSB32(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_button_t* button7;
    txt_button_t* button8;
    txt_button_t* button9;
    txt_button_t* button10;
    txt_button_t* button11;
    txt_button_t* button12;

    GetMusiccard(0, user_data);

    window = TXT_NewWindow("Available MIDI Ports       ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 3);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("220                        "),
        button2 = TXT_NewButton("230                        "),
        button3 = TXT_NewButton("240                        "),
        button4 = TXT_NewButton("250                        "),
        button5 = TXT_NewButton("300                        "),
        button6 = TXT_NewButton("320                        "),
        button7 = TXT_NewButton("330                        "),
        button8 = TXT_NewButton("332                        "),
        button9 = TXT_NewButton("334                        "),
        button10 = TXT_NewButton("336                        "),
        button11 = TXT_NewButton("340                        "),
        button12 = TXT_NewButton("360                        "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetMusicGMPort, "220");
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetMusicGMPort, "230");
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetMusicGMPort, "240");
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", GetMusicGMPort, "250");
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", GetMusicGMPort, "300");
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", GetMusicGMPort, "320");
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button7, "pressed", GetMusicGMPort, "330");
    TXT_SignalConnect(button7, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button8, "pressed", GetMusicGMPort, "332");
    TXT_SignalConnect(button8, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button9, "pressed", GetMusicGMPort, "334");
    TXT_SignalConnect(button9, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button10, "pressed", GetMusicGMPort, "336");
    TXT_SignalConnect(button10, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button11, "pressed", GetMusicGMPort, "340");
    TXT_SignalConnect(button11, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button12, "pressed", GetMusicGMPort, "360");
    TXT_SignalConnect(button12, "pressed", ClosePwnBox, window);

    switch (MidiPort)
    {
    case 220:
        TXT_SelectWidget(table, button1);
        break;
    case 230:
        TXT_SelectWidget(table, button2);
        break;
    case 240:
        TXT_SelectWidget(table, button3);
        break;
    case 250:
        TXT_SelectWidget(table, button4);
        break;
    case 300:
        TXT_SelectWidget(table, button5);
        break;
    case 320:
        TXT_SelectWidget(table, button6);
        break;
    case 330:
        TXT_SelectWidget(table, button7);
        break;
    case 332:
        TXT_SelectWidget(table, button8);
        break;
    case 334:
        TXT_SelectWidget(table, button9);
        break;
    case 336:
        TXT_SelectWidget(table, button10);
        break;
    case 340:
        TXT_SelectWidget(table, button11);
        break;
    case 360:
        TXT_SelectWidget(table, button12);
        break;
    default:
        TXT_SelectWidget(table, button7);
        break;
    }
    
    if (setupflag)
    {
        TXT_SignalConnect(button1, "pressed", FXCard, NULL);
        TXT_SignalConnect(button2, "pressed", FXCard, NULL);
        TXT_SignalConnect(button3, "pressed", FXCard, NULL);
        TXT_SignalConnect(button4, "pressed", FXCard, NULL);
        TXT_SignalConnect(button5, "pressed", FXCard, NULL);
        TXT_SignalConnect(button6, "pressed", FXCard, NULL);
        TXT_SignalConnect(button7, "pressed", FXCard, NULL);
        TXT_SignalConnect(button8, "pressed", FXCard, NULL);
        TXT_SignalConnect(button9, "pressed", FXCard, NULL);
        TXT_SignalConnect(button10, "pressed", FXCard, NULL);
        TXT_SignalConnect(button11, "pressed", FXCard, NULL);
        TXT_SignalConnect(button12, "pressed", FXCard, NULL);
        TXT_SignalConnect(close_button, "pressed", FXCard, NULL);
    }

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}

void MusicCardSB(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_button_t* button7;

    GetMusiccard(0, user_data);

    window = TXT_NewWindow("Available PORTs            ");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 6);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("210                        "),
        button2 = TXT_NewButton("220                        "),
        button3 = TXT_NewButton("230                        "),
        button4 = TXT_NewButton("240                        "),
        button5 = TXT_NewButton("250                        "),
        button6 = TXT_NewButton("260                        "),
        button7 = TXT_NewButton("280                        "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", GetMusicBasePort, "210");
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", GetMusicBasePort, "220");
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", GetMusicBasePort, "230");
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", GetMusicBasePort, "240");
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", GetMusicBasePort, "250");
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", GetMusicBasePort, "260");
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button7, "pressed", GetMusicBasePort, "280");
    TXT_SignalConnect(button7, "pressed", ClosePwnBox, window);

    switch (BasePort)
    {
    case 210:
        TXT_SelectWidget(table, button1);
        break;
    case 220:
        TXT_SelectWidget(table, button2);
        break;
    case 230:
        TXT_SelectWidget(table, button3);
        break;
    case 240:
        TXT_SelectWidget(table, button4);
        break;
    case 250:
        TXT_SelectWidget(table, button5);
        break;
    case 260:
        TXT_SelectWidget(table, button6);
        break;
    case 280:
        TXT_SelectWidget(table, button7);
        break;
    default:
        TXT_SelectWidget(table, button2);
        break;
    }
    
    if (setupflag)
    {
        TXT_SignalConnect(button1, "pressed", FXCard, NULL);
        TXT_SignalConnect(button2, "pressed", FXCard, NULL);
        TXT_SignalConnect(button3, "pressed", FXCard, NULL);
        TXT_SignalConnect(button4, "pressed", FXCard, NULL);
        TXT_SignalConnect(button5, "pressed", FXCard, NULL);
        TXT_SignalConnect(button6, "pressed", FXCard, NULL);
        TXT_SignalConnect(button7, "pressed", FXCard, NULL);
        TXT_SignalConnect(close_button, "pressed", FXCard, NULL);
    }

    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}

void MusicCardProUltraADNO(TXT_UNCAST_ARG(widget), void* user_data)
{
    GetMusiccard(0, user_data);
    if (setupflag)
        FXCard(0, 0);
}

void MusicCard(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_button_t* button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_button_t* button7;
    txt_button_t* button8;
    txt_button_t* button9;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_table_t* table;

    window = TXT_NewWindow("Select Music Playback Device");
    TXT_SetWindowPosition(window, TXT_HORIZ_CENTER, TXT_VERT_TOP, 40, 5);
    table = TXT_NewTable(1);
    TXT_AddWidgets(table,
        button1 = TXT_NewButton("General Midi                "),
        button2 = TXT_NewButton("Sound Canvas                "),
        button3 = TXT_NewButton("WaveBlaster                 "),
        button4 = TXT_NewButton("SB AWE 32                   "),
        button5 = TXT_NewButton("Sound Blaster               "),
        button6 = TXT_NewButton("Pro Audio Spectrum          "),
        button7 = TXT_NewButton("UltraSound                  "),
        button8 = TXT_NewButton("Adlib                       "),
        button9 = TXT_NewButton("NONE                        "),
        NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button1, "pressed", MusicCardGMSCWBSB32, "General Midi");
    TXT_SignalConnect(button1, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button2, "pressed", MusicCardGMSCWBSB32, "Roland Sound Canvas");
    TXT_SignalConnect(button2, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button3, "pressed", MusicCardGMSCWBSB32, "WaveBlaster");
    TXT_SignalConnect(button3, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button4, "pressed", MusicCardGMSCWBSB32, "Sound Blaster AWE 32");
    TXT_SignalConnect(button4, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button5, "pressed", MusicCardSB, "Sound Blaster");
    TXT_SignalConnect(button5, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button6, "pressed", MusicCardProUltraADNO, "Pro Audio Spectrum");
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button7, "pressed", MusicCardProUltraADNO, "UltraSound");
    TXT_SignalConnect(button7, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button8, "pressed", MusicCardProUltraADNO, "Adlib");
    TXT_SignalConnect(button8, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(button9, "pressed", MusicCardProUltraADNO, "NONE");
    TXT_SignalConnect(button9, "pressed", ClosePwnBox, window);

    
    switch (CardType)
    {
    case 2:
        TXT_SelectWidget(table, button8);
        break;
    case 3:
        TXT_SelectWidget(table, button7);
        break;
    case 4:
        TXT_SelectWidget(table, button6);
        break;
    case 5:
        TXT_SelectWidget(table, button5);
        break;
    case 6:
        TXT_SelectWidget(table, button3);
        break;
    case 7:
        TXT_SelectWidget(table, button2);
        break;
    case 8:
        TXT_SelectWidget(table, button1);
        break;
    case 9:
        TXT_SelectWidget(table, button4);
        break;
    case 1000:
        TXT_SelectWidget(table, button9);
        break;
    default:
        TXT_SelectWidget(table, button5);
        break;
    }
    
    if (setupflag)
        TXT_SignalConnect(close_button, "pressed", FXCard, NULL);
        
    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(window, table);
    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}
/////////////////////////////////////////////////////////Main Menu/////////////////////////////////////////////////////////
void MainMenu(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_button_t *button1;
    txt_button_t* button2;
    txt_button_t* button3;
    txt_button_t* button4;
    txt_button_t* button5;
    txt_button_t* button6;
    txt_table_t *table;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;

    mainwindow = TXT_NewWindow("Main Menu                  ");
    TXT_SetWindowPosition(mainwindow, TXT_HORIZ_CENTER, TXT_VERT_TOP, 39, 10);
    table = TXT_NewTable(1);
    
    TXT_AddWidgets(table,
                   button1 = TXT_NewButton("Select Music Card          "),
                   button2 = TXT_NewButton("Select Sound FX Card       "),
                   button3 = TXT_NewButton("Select Controller Type     "),
                   button4 = TXT_NewButton("Controller Config          "),
                   button5 = TXT_NewButton("Additional Features        "),
                   button6 = TXT_NewButton("Save Settings              "),
                   NULL);
    accept_button = TXT_NewWindowAction(KEY_ENTER, "Accept");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");
    
    TXT_SignalConnect(button1, "pressed", MusicCard, NULL);
    TXT_SignalConnect(button2, "pressed", FXCard, NULL);
    TXT_SignalConnect(button3, "pressed", Control, NULL);
    TXT_SignalConnect(button4, "pressed", ControlButtonConfig, NULL);
    TXT_SignalConnect(button5, "pressed", AdditionalFeatures, NULL);
    TXT_SignalConnect(button6, "pressed", SaveSettings, NULL);
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, mainwindow);
    TXT_SignalConnect(button6, "pressed", ClosePwnBox, infowindow);
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, mainwindow);
    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, infowindow);
    
    if(setupflag)
       TXT_SelectWidget(table, button6);
    
    TXT_SetWidgetFocus(mainwindow, 1);
    TXT_AddWidget(mainwindow, table);
    
    TXT_SetWindowAction(mainwindow, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(mainwindow, TXT_HORIZ_RIGHT, accept_button);

    setupflag = 0;
}

int main(int argc, char *argv[])
{
    RAP_DataPath();

    if (access(RAP_GetSetupPath(), 0))                     //Check setup.ini is in folder
    {
        setupflag = 1;
        writesetupflag = 1;
    }

    INI_InitPreference(RAP_GetSetupPath());
    GetSetupSettings();
    
    TXT_Fullscreen(txt_fullscreen);
    
    if (!TXT_Init())
    {
        fprintf(stderr, "Failed to initialise GUI\n");
        exit(-1);
    }

    TXT_SetColor(TXT_COLOR_BLUE, 0x04, 0x14, 0x40);

    TXT_SetDesktopTitle("Raptor Setup ver 1.2                              (c) Cygnus Studios Inc. 1994");
    TXT_SetWindowTitle("Raptor Setup");

    if (!setupflag)
    {
        InfoWindow(0, 0);
        MainMenu(0, 0);
    }

    if (setupflag)
    {
        InfoWindow(0, 0);
        Control(0, 0);
    }

    TXT_GUIMainLoop();

    TXT_Shutdown();

    return 0;
}


