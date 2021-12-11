/*
    File: headTails.hpp
    Author: Novax
   	github : https://github.com/Novax69 <== Find my other scripts for arma here
    Date : 16/11/2021
    Description: 
	HeadOrTails GUI Menu
*/

class NOV_HeadOrTails {
    idd = 690100;
    name= "NOV_HeadOrTails";
    movingEnable = 0;
    enableSimulation = 1;
	
	class controlsBackground {
		class RscText_1001: Life_RscText	{
			idc = 690101;
			x = 0.345312 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.309375 * safezoneW;
			h = 0.253 * safezoneH;
			colorBackground[] = {0, 0, 0, 0.7};
		};
		class RscText_1000: Life_RscText {
			idc = 690102;
			text = "Pile ou Face ?"; //--- ToDo: Localize;
			x = 0.345312 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.309375 * safezoneW;
			h = 0.033 * safezoneH;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class RscText_1002: Life_RscText	{
			idc = 690103;
			text = "Choix face"; //--- ToDo: Localize;
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class RscText_1003: Life_RscText {
			idc = 690104;
			text = "Mise"; //--- ToDo: Localize;
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class RscText_1004: Life_RscText {
			idc = 690105;
			text = "Résultat"; //--- ToDo: Localize;
			x = 0.561875 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class RscText_1005: Life_RscText {
			idc = 690106;
			text = "Règles"; //--- ToDo: Localize;
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
	};

	class controls {
		class RscButton_1600: Life_RscButtonMenu
		{
			idc = 690107;
			text = "Fermer"; //--- ToDo: Localize;
			x = 0.345312 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.033 * safezoneH;
            onButtonClick = "closeDialog 0;";
		};
		class RscCombo_2100: Life_RscCombo
		{
			idc = 690108;
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.022 * safezoneH;
		};

		class RscEdit_1400: Life_RscEdit
		{
			idc = 690109;
			text="1";
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class ResultText: Life_RscStructuredText
		{
			idc = 690110;
			x = 0.561875 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class RulesText: Life_RscStructuredText
		{
			idc = 690111;
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.28875 * safezoneW;
			h = 0.044 * safezoneH;
		};
		class RscButton_1601: Life_RscButtonMenu
		{
			idc = 690112;
		    onButtonClick = "execVM 'NovScript\HeadOrTails\fn_NovHeadOrTailsDoBet.sqf'";
			text = "Jouer"; //--- ToDo: Localize;
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.555 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.055 * safezoneH;
		};
	};
};