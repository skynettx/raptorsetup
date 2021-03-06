#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "textscreen.h"
#include "main.h"
#include "input.h"
#include "txt_keyinput.h"
#include "txt_mouseinput.h"
#include "txt_joyinput.h"


int ControllerType;

int key_up = KEY_UPARROW;
int key_down = KEY_DOWNARROW;
int key_left = KEY_LEFTARROW;
int key_right = KEY_RIGHTARROW;
int key_fire = KEY_RCTRL;
int key_special = KEY_LALT;
int key_mega = ' ';
int convertflagkey;
int writeflagkey;
int key_up_convert, key_down_convert, key_left_convert, key_right_convert, key_fire_convert, key_special_convert, key_mega_convert;
static int* controls[] = { &key_up, &key_down, &key_left, &key_right, &key_fire, &key_special, &key_mega, NULL };

static const int scantokey[128] =
{
    0  ,    27,     '1',    '2',    '3',    '4',    '5',    '6',
    '7',    '8',    '9',    '0',    '-',    '=',    KEY_BACKSPACE, 9,
    'q',    'w',    'e',    'r',    't',    'y',    'u',    'i',
    'o',    'p',    '[',    ']',    13,		KEY_RCTRL, 'a',    's',
    'd',    'f',    'g',    'h',    'j',    'k',    'l',    ';',
    '\'',   '`',    KEY_RSHIFT,'\\',   'z',    'x',    'c',    'v',
    'b',    'n',    'm',    ',',    '.',    '/',    KEY_RSHIFT,KEYP_MULTIPLY,
    KEY_RALT,  ' ',  KEY_CAPSLOCK,KEY_F1,  KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,
    KEY_F6,   KEY_F7,   KEY_F8,   KEY_F9,   KEY_F10,  /*KEY_NUMLOCK?*/KEY_PAUSE,KEY_SCRLCK,KEY_HOME,
    KEY_UPARROW,KEY_PGUP,KEY_MINUS,KEY_LEFTARROW,KEYP_5,KEY_RIGHTARROW,KEYP_PLUS,KEY_END,
    KEY_DOWNARROW,KEY_PGDN,KEY_INS,KEY_DEL,0,   0,      0,      KEY_F11,
    KEY_F12,  0,      0,      0,      0,      0,      0,      0,
    0,      0,      0,      0,      0,      0,      0,      0,
    0,      0,      0,      0,      0,      0,      0,      0,
    0,      0,      0,      0,      0,      0,      0,      0,
    0,      0,      0,      0,      0,      0,      KEY_PRTSCR, 0
};

int mousebfire, mousebchweapon, mousebmega;
int mousebfireout, mousebchweaponout, mousebmegaout;
int writeflagmouse;

static int* all_mouse_buttons[] = {
    &mousebfire,
    &mousebchweapon,
    &mousebmega,
};

int joybfire, joybchweapon, joybmega, joybspeed;
int joybfireout, joybchweaponout, joybmegaout;
int writeflagjoy, writeflagjoybfire, writeflagjoybchweapon, writeflagjoybmega;


void GetControl(TXT_UNCAST_ARG(widget), void* user_data)
{
    if (strcmp(user_data, "Keyboard") == 0)
    {
        ControllerType = 1000;
        textbox_control = "Keyboard                          ";
    }
    if (strcmp(user_data, "Mouse") == 0)
    {
        ControllerType = 1;
        textbox_control = "Mouse                             ";
    }
    if (strcmp(user_data, "Joystick") == 0)
    {
        ControllerType = 2;
        textbox_control = "Joystick                          ";
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
////////////////////////////////////////////////Select ControlButtonConfigKeyboard///////////////////////////////////////////////////
static int VarInGroup(int* variable, int** group)
{
    unsigned int i;

    for (i = 0; group[i] != NULL; ++i)
    {
        if (group[i] == variable)
        {
            return 1;
        }
    }

    return 0;
}

static void CheckKeyGroup(int* variable, int** group)
{
    unsigned int i;

    // Don't check unless the variable is in this group.

    if (!VarInGroup(variable, group))
    {
        return;
    }

    // If another variable has the same value as the new value, reset it.

    for (i = 0; group[i] != NULL; ++i)
    {
        if (*variable == *group[i] && group[i] != variable)
        {
            // A different key has the same value.  Clear the existing
            // value. This ensures that no two keys can have the same
            // value.

            *group[i] = 0;
        }
    }
 }

static void KeySetCallback(TXT_UNCAST_ARG(widget), TXT_UNCAST_ARG(variable))
{
    TXT_CAST_ARG(int, variable);

    CheckKeyGroup(variable, controls);
}

void ConvertKey(TXT_UNCAST_ARG(widget), void* user_data)
{
    int s;

    writeflagkey = 1;

    for (s = 0; s < 128; ++s)
    {
        if (scantokey[s] == key_up)
        {
            key_up_convert = s;
            break;
        }
    }
    for (s = 0; s < 128; ++s)
    {
        if (scantokey[s] == key_down)
        {
            key_down_convert = s;
            break;
        }
    }
    for (s = 0; s < 128; ++s)
    {
        if (scantokey[s] == key_left)
        {
            key_left_convert = s;
            break;
        }
    }
    for (s = 0; s < 128; ++s)
    {
        if (scantokey[s] == key_right)
        {
            key_right_convert = s;
            break;
        }
    }
    for (s = 0; s < 128; ++s)
    {
        if (scantokey[s] == key_fire)
        {
            key_fire_convert = s;
            break;
        }
    }
    for (s = 0; s < 128; ++s)
    {
        if (scantokey[s] == key_special)
        {
            key_special_convert = s;
            break;
        }
    }
    for (s = 0; s < 128; ++s)
    {
        if (scantokey[s] == key_mega)
        {
            key_mega_convert = s;
            break;
        }
    }
}

static void AddKeyControl(TXT_UNCAST_ARG(table), const char* name, int* var)
{
    TXT_CAST_ARG(txt_table_t, table);
    txt_key_input_t* key_input;

    TXT_AddWidget(table, TXT_NewLabel(name));
    key_input = TXT_NewKeyInput(var);
    TXT_AddWidget(table, key_input);

    TXT_SignalConnect(key_input, "set", KeySetCallback, var);
}

void GetControlKeyboard(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_window_action_t* select_button;

    if (!convertflagkey)
    {
        key_up = scantokey[keymoveup];
        key_down = scantokey[keymovedown];
        key_left = scantokey[keymoveleft];
        key_right = scantokey[keymoveright];
        key_fire = scantokey[keyfire];
        key_special = scantokey[keyspecial];
        key_mega = scantokey[keymega];
        convertflagkey = 1;
    }

    window = TXT_NewWindow("Keyboard Configuration            ");

    TXT_SetTableColumns(window, 2);
    TXT_SetColumnWidths(window, 4, 3);
    //TXT_AddWidget(window, TXT_TABLE_EMPTY);
    TXT_AddWidget(window, TXT_NewSeparator("Movement"));
    AddKeyControl(window, " Up                ", &key_up);
    AddKeyControl(window, " Down              ", &key_down);
    AddKeyControl(window, " Left              ", &key_left);
    AddKeyControl(window, " Right             ", &key_right);
    TXT_AddWidget(window, TXT_NewSeparator("Action"));
    AddKeyControl(window, " Fire              ", &key_fire);
    AddKeyControl(window, " Change Special    ", &key_special);
    AddKeyControl(window, " Mega Bomb         ", &key_mega);

    accept_button = TXT_NewWindowAction(KEY_F10, "Accept");
    select_button = TXT_NewWindowAction(KEY_ENTER, "Select");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");

    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(close_button, "pressed", ControlButtonConfig, NULL);
    TXT_SignalConnect(accept_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(accept_button, "pressed", ConvertKey, NULL);
    TXT_SignalConnect(accept_button, "pressed", ControlButtonConfig, NULL);

    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_CENTER, select_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}
////////////////////////////////////////////////Select ControlButtonConfigMouse///////////////////////////////////////////////////
static void MouseSetCallback(TXT_UNCAST_ARG(widget), TXT_UNCAST_ARG(variable))
{
    TXT_CAST_ARG(int, variable);
    unsigned int i;

    // Check if the same mouse button is used for a different action
    // If so, set the other action(s) to -1 (unset)

    for (i = 0; i < arrlen(all_mouse_buttons); ++i)
    {
        if (*all_mouse_buttons[i] == *variable
            && all_mouse_buttons[i] != variable)
        {
            *all_mouse_buttons[i] = -1;
        }
    }
}

static void AddMouseControl(TXT_UNCAST_ARG(table), const char* label, int* var)
{
    TXT_CAST_ARG(txt_table_t, table);
    txt_mouse_input_t* mouse_input;

    TXT_AddWidget(table, TXT_NewLabel(label));

    mouse_input = TXT_NewMouseInput(var);
    TXT_AddWidget(table, mouse_input);

    TXT_SignalConnect(mouse_input, "set", MouseSetCallback, var);
}

void SaveMouseConfig(TXT_UNCAST_ARG(widget), void* user_data)
{
    if ((mousebfire > 2) || (mousebchweapon > 2) || (mousebmega > 2))
    {
        TXT_MessageBox("Error", ("Only LEFT BUTTON, RIGHT BUTTON and MID BUTTON are supported!\n"
                                 "Please reconfigure mouse buttons before save!"));

        writeflagmouse = 0;

        return;
    }
    writeflagmouse = 1;
}

void GetControlMouse(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_window_action_t* select_button;

    window = TXT_NewWindow("Mouse Configuration                ");

    TXT_SetTableColumns(window, 2);

    AddMouseControl(window, " Fire              ", &mousebfire);
    AddMouseControl(window, " Change Weapon     ", &mousebchweapon);
    AddMouseControl(window, " Mega Bomb         ", &mousebmega);

    accept_button = TXT_NewWindowAction(KEY_F10, "Accept");
    select_button = TXT_NewWindowAction(KEY_ENTER, "Select");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");

    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(close_button, "pressed", ControlButtonConfig, NULL);

    TXT_SignalConnect(accept_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(accept_button, "pressed", ControlButtonConfig, NULL);
    TXT_SignalConnect(accept_button, "pressed", SaveMouseConfig, NULL);

    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_CENTER, select_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}
////////////////////////////////////////////////Select ControlButtonConfigJoystick////////////////////////////////////////////////
static void AddJoystickControl(TXT_UNCAST_ARG(table), const char* label, int* var)
{
    TXT_CAST_ARG(txt_table_t, table);
    txt_joystick_input_t* joy_input;

    TXT_AddWidget(table, TXT_NewLabel(label));

    joy_input = TXT_NewJoystickInput(var);

    TXT_AddWidget(table, joy_input);
}

void SaveJoyConfig(TXT_UNCAST_ARG(widget), void* user_data)
{
    if ((joybfireout > 3) || (joybchweaponout > 3) || (joybmegaout > 3))
    {
        TXT_MessageBox("Error", ("Only BUTTON 1, BUTTON 2, BUTTON 3 and BUTTON 4 are supported!\n"
                       "Please reconfigure joystick/gamepad buttons before save!"));

        writeflagjoy = 0;

        return;
    }

    writeflagjoy = 1;
}

void GetControlJoystick(TXT_UNCAST_ARG(widget), void* user_data)
{
    txt_window_t* window;
    txt_window_action_t* close_button;
    txt_window_action_t* accept_button;
    txt_window_action_t* select_button;

    if (!joybfireout)
    joybfireout = joybfire;
    if (!joybchweaponout)
    joybchweaponout = joybchweapon;
    if (!joybmegaout)
    joybmegaout = joybmega;

    window = TXT_NewWindow("Joystick/Gamepad Config            ");

    TXT_SetTableColumns(window, 2);

    AddJoystickControl(window, "Fire               ", &joybfire);
    AddJoystickControl(window, "Change Special     ", &joybchweapon);
    AddJoystickControl(window, "Mega               ", &joybmega);

    accept_button = TXT_NewWindowAction(KEY_F10, "Accept");
    select_button = TXT_NewWindowAction(KEY_ENTER, "Select");
    close_button = TXT_NewWindowAction(KEY_ESCAPE, "Abort");

    TXT_SignalConnect(close_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(close_button, "pressed", ControlButtonConfig, NULL);

    TXT_SignalConnect(accept_button, "pressed", ClosePwnBox, window);
    TXT_SignalConnect(accept_button, "pressed", ControlButtonConfig, NULL);
    TXT_SignalConnect(accept_button, "pressed", SaveJoyConfig, NULL);

    TXT_SetWindowAction(window, TXT_HORIZ_LEFT, close_button);
    TXT_SetWindowAction(window, TXT_HORIZ_CENTER, select_button);
    TXT_SetWindowAction(window, TXT_HORIZ_RIGHT, accept_button);
}
