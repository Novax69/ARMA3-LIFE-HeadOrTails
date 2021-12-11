#include "..\..\NOV_macros.hpp"
/*
    File: fn_NovHeadOrTailsDoBet.sqf
    Author: Novax
   	github : https://github.com/Novax69 <== Find my other scripts for arma here
    Date : 16/11/2021
    Description:
	HoT Play
*/


private["_maxBet","_maxBetEnabled","_mise","_bet","_result","_resultText","_winningAmmount","_multiplier","_random","_breakCondition"];
_arrayToGive = [];

_mise = parseNumber(ctrlText 690109);
_bet = lbCurSel 690108;

_maxBetEnabled = NOV_PARAMS(getNumber,"nov_hotUseMaxBet");

if(_maxBetEnabled isEqualTo 1) then {
	_maxBet = NOV_PARAMS(getNumber,"nov_hotMaxBet");
	if(_mise > _maxBet) then { _breakCondition = true } else { _breakCondition = false };
};

if(_breakCondition) exitWith {hint format [localize "STR_NOV_HoT_MaxBetReached",(_maxBet) call retour_formatage_chiffre_sfp]};

if(_mise <= 0) exitWith {};
if(_mise > CASH) exitWith {hint localize "STR_NOV_HoT_NotEnoughCash"};


_random = round(random 4);

if(_random isEqualTo 1) then {
	if(_bet isEqualTo 0) then {
		_resultText = "Pile";
	} else {
		_resultText = "Face";
	};
	_result = _bet;
} else {
	_result = -2;
	if(_bet isEqualTo 0) then {
		_resultText = "Face";
	} else {
		_resultText = "Pile";
	};
};

_arrayToGive set[0,_result];
_arrayToGive set[1,_resultText];

if(_bet == _result) then {
	_multiplier = NOV_PARAMS(getNumber,"nov_hotMultiplier");
	_winningAmmount = round(_mise * _multiplier);
	CASH = CASH + _winningAmmount;
	_arrayToGive set[2,_winningAmmount];
} else {
	_winningAmmount = _mise;
	CASH = CASH - _winningAmmount;
	_arrayToGive set[2,_winningAmmount];		
};

_arrayToGive set[3,_bet];

[1,_arrayToGive] call nov_fnc_NovHeadOrTailsMenu;
