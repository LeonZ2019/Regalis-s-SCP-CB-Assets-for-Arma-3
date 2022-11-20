#include "script_component.hpp"
/*
 * Author: Sanuki357
 * Handles opening a door and emit a appopriate sound effect.
 *
 *
 * Arguments:
 * 0: object - Object to be controled its animateSource phase and origin of sounds <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [this, 'Door1 Open', 'open_door'] execVM "QPATHTOF(functions\fnc_doorOperate.sqf)"
 *
 * Public: No
 */

params ["_targets", "_delayType"];

if (_delayType == "LockRoom") then {
    if (this getVariable ['SCP_RequiredClearanceLevel', 0]) then {};
};

{
    //systemChat format ["type of the thing is: %1", typeOf _x];
    private _targetKind = getArray (configFile >> "CfgVehicles" >> typeOf _x >> QEGVAR(operatable,type)) select 0 select 0;

    if (_targetKind == "Door") then {
        private _animationSource = getArray (configFile >> "CfgVehicles" >> typeOf _x >> QEGVAR(operatable,type)) select 0 select 2;
        if (_x animationSourcePhase _animationSource == 1) then {
            [_x, 'Close', 0] call SCP_fnc_doorOperate;
        };

        if (_x animationSourcePhase _animationSource == 0) then {
            [_x, 'Open', 0] call SCP_fnc_doorOperate;
        };
    };
} foreach _targets;