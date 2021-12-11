#include "..\..\NOV_macros.hpp"
/*
    File: fn_NovHeadOrTailsMenu.sqf
    Author: Novax
   	github : https://github.com/Novax69 <== Find my other scripts for arma here
    Date : 01/05/2020
    Description:
	Lotery Menu
*/

disableSerialization;
private["_playerBetted","_mode","_answer","_multiplier","_comboControl","_optionHead","_optionTails","_ammount","_answerArray","_result"];


_multiplier = NOV_PARAMS(getNumber,"nov_hotMultiplier");
_mode = _this select 0;


if(!dialog) then {
	if(!(createDialog "NOV_HeadOrTails")) exitWith {};
};


if(_mode isEqualTo 1) then {
	_answerArray = _this select 1;
	_result = _answerArray select 0; // 0 ou 1 (Pile ou Face)
	_answer = _answerArray select 1; // Résultat Pile ou Face;
	_ammount = _answerArray select 2; // Montant Gagné ou perdu
	_playerBetted = _answerArray select 3; // Ce que le joueur à parrié
	if(_result isEqualTo _playerBetted) then {
		CONTROL(690100,690110) ctrlSetStructuredText parseText format[localize "STR_NOV_Hot_Win", (_ammount) call life_fnc_numberText, _answer];
	} else {
		CONTROL(690100,690110) ctrlSetStructuredText parseText format[localize "STR_NOV_HoT_Lost", (_ammount) call life_fnc_numberText, _answer];
	};
} else {
	_comboControl = findDisplay 690100 displayCtrl 690108; //Combo
	_optionHead = "Pile";
	_optionTails = "Face";
	_comboControl lbAdd _optionHead;
	_comboControl lbAdd _optionTails;
};





// Message de règles
CONTROL(690100,690111) ctrlSetStructuredText parseText format[localize "STR_NOV_HoT_Rules",(_multiplier) call life_fnc_numberText];