#include "script_component.hpp"

#include "CfgPatches.hpp"
#include "CfgEditorCategories.hpp"
#include "CfgVehicles.hpp"
#include "CfgSounds.hpp"

#include "CfgWeapons.hpp"
#include "CfgFunctions.hpp"

#define CARDREADER_INIT_SCRIPT(buttonMemory) "_id = _this select 0 addAction [ localize "CSTRING(CardReader_Insert)", { if ([_this select 0, _this select 1, _this select 0 getVariable ['SCP_RequiredClearanceLevel', 0], "#buttonMemory"] call SCP_fnc_clearanceLevelCheck == true) then { _string = _this select 0 getVariable ['SCP_PressExpression', false]; _code = compile _string; call _code; }; }, nil, 3, true, true, '', 'true', 1, false, '', "#buttonMemory" ];";
#define CARDREADER_INIT_BUTTON_TRIGGER(buttonMemory) "_id = _this select 0 addAction [ localize "CSTRING(CardReader_Insert)", { if ([_this select 0, _this select 1, _this select 0 getVariable ['SCP_RequiredClearanceLevel', 0], "#buttonMemory"] call SCP_fnc_clearanceLevelCheck == true) then { [[_this select 0], 'None'] call SCP_fnc_buttonTrigger; }; }, nil, 3, true, true, '', 'true', 1, false, '', "#buttonMemory" ];";
#define CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(buttonMemory, clearanceLevel) "_id = _this select 0 addAction [ localize "CSTRING(CardReader_Insert)", { if ([_this select 0, _this select 1, parseNumber "#clearanceLevel", "#buttonMemory"] call SCP_fnc_clearanceLevelCheck == true) then { [[_this select 0], 'None'] call SCP_fnc_buttonTrigger; }; }, nil, 3, true, true, '', 'true', 1, false, '', "#buttonMemory" ];";

class Extended_InitPost_EventHandlers {
    class SCP_CB_Things_Door1_CardReader {
        class SCP_CB_Things_Door1_CardReader_Front_init { init = CARDREADER_INIT_BUTTON_TRIGGER(button_f) };
        class SCP_CB_Things_Door1_CardReader_Back_init { init = CARDREADER_INIT_BUTTON_TRIGGER(button_b) };
    };

    class SCP_CB_Things_Door1_CardReader_Level1 {
        class SCP_CB_Things_Door1_CardReader_Front_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_f, 1) };
        class SCP_CB_Things_Door1_CardReader_Back_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_b, 1) };
    };

    class SCP_CB_Things_Door1_CardReader_Level2 {
        class SCP_CB_Things_Door1_CardReader_Front_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_f, 2) };
        class SCP_CB_Things_Door1_CardReader_Back_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_b, 2) };
    };

    class SCP_CB_Things_Door1_CardReader_Level3 {
        class SCP_CB_Things_Door1_CardReader_Front_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_f, 3) };
        class SCP_CB_Things_Door1_CardReader_Back_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_b, 3) };
    };

    class SCP_CB_Things_Door1_CardReader_Level4 {
        class SCP_CB_Things_Door1_CardReader_Front_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_f, 4) };
        class SCP_CB_Things_Door1_CardReader_Back_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_b, 4) };
    };

    class SCP_CB_Things_Door1_CardReader_Level5 {
        class SCP_CB_Things_Door1_CardReader_Front_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_f, 5) };
        class SCP_CB_Things_Door1_CardReader_Back_init { init = CARDREADER_INIT_BUTTON_TRIGGER_SIMPLE(button_b, 5) };
    };

    class SCP_CB_Things_Keypad_CardReader {
        class SCP_CB_Things_Keypad_CardReader_init { init = CARDREADER_INIT_SCRIPT(button_f) };
    };
};