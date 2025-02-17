.set LOCALID_MOM, 1

ChandraVillage_PlayerHouse_1F_MapScripts::
	.byte 0

ChandraVillage_PlayerHouse_1F_Mother::
	goto_if_set FLAG_SYS_POKEDEX_GET, ChandraVillage_PlayerHouse_1F_Mother_PKMN_Menu
	goto_if_set FLAG_BADGE01_GET, ChandraVillage_PlayerHouse_1F_Mother_Badge_One
	goto_if_set FLAG_RECEIVED_RUNNING_SHOES, ChandraVillage_PlayerHouse_1F_MotherTalkedTo
	lockall
	faceplayer
	msgbox ChandraVillage_PlayerHouse_1F_Text_OhAlmostForgot, MSGBOX_DEFAULT
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	playfanfare MUS_OBTAIN_ITEM
	message ChandraVillage_PlayerHouse_1F_Text_ReceivedRunningShoes
	waitfanfare
	msgbox ChandraVillage_PlayerHouse_1F_Text_EquipShoes, MSGBOX_AUTOCLOSE
	msgbox ChandraVillage_PlayerHouse_1F_Text_TheyLookGreat, MSGBOX_DEFAULT
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_STORYLINE_STATE, 3
	releaseall
	end

ChandraVillage_PlayerHouse_1F_MotherTalkedTo::
	msgbox ChandraVillage_PlayerHouse_1F_Text_MotherTalkedTo, MSGBOX_NPC
	end

ChandraVillage_PlayerHouse_1F_Mother_PKMN_Menu::
	lockall
	faceplayer
	msgbox ChandraVillage_PlayerHouse_Text_1F_Mother_PKMN_Menu, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_PlayerHouse_1F_Mother_Rest
	goto ChandraVillage_Playerhouse_1F_Mother_No

ChandraVillage_PlayerHouse_1F_Mother_Badge_One::
	lockall
	faceplayer
	msgbox ChandraVillage_PlayerHouse_Text_1F_Mother_Badge_One, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_PlayerHouse_1F_Mother_Rest
	goto ChandraVillage_Playerhouse_1F_Mother_No

ChandraVillage_PlayerHouse_1F_Mother_Rest::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox ChandraVillage_PlayerHouse_1F_Text_Mother_Healed, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Playerhouse_1F_Mother_No::
	msgbox ChandraVillage_PlayerHouse_1F_Text_Mother_No, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Playerhouse_1F_Storyline_State_3_Running_Shoes::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox ChandraVillage_PlayerHouse_1F_Text_OhPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	applymovement LOCALID_MOM, WalkDLLD
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox ChandraVillage_PlayerHouse_1F_Text_AlmostForgot, MSGBOX_DEFAULT
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	playfanfare MUS_OBTAIN_ITEM
	message ChandraVillage_PlayerHouse_1F_Text_ReceivedRunningShoes
	waitfanfare
	msgbox ChandraVillage_PlayerHouse_1F_Text_EquipShoes, MSGBOX_AUTOCLOSE
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox ChandraVillage_PlayerHouse_1F_Text_TheyLookGreat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, WalkURRUFL
	waitmovement 0
	setvar VAR_STORYLINE_STATE, 3
	setflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

WalkDLLD:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

WalkURRUFL:
	walk_up
	walk_right
	walk_right
	walk_up
	face_left
	step_end

ChandraVillage_PlayerHouse_1F_Text_MotherTalkedTo:
	.string "{COLOR}{RED}Be sure to say hello to Tyler's Mom\n"
	.string "for me, {PLAYER}.$"

ChandraVillage_PlayerHouse_Text_1F_Mother_PKMN_Menu:
	.string "{COLOR}{RED}Welcome home, {PLAYER}!\p"
	.string "…\n"
	.string "…\p"
	.string "Wow, Professor Hawthorne gave you a\n"
	.string "Pokémon? That's great, darling!\p"
	.string "How about a quick rest?$"

ChandraVillage_PlayerHouse_Text_1F_Mother_Badge_One:
	.string "{COLOR}{RED}Welcome home, {PLAYER}.\n"
	.string "How is your adventure going?\p"
	.string "Would you like to take a quick rest?$"

ChandraVillage_PlayerHouse_1F_Text_Mother_Healed:
	.string "{COLOR}{RED}Take care, honey!\n"
	.string "Mom is proud of you!$"

ChandraVillage_PlayerHouse_1F_Text_Mother_No:
	.string "{COLOR}{RED}Mom is proud of you, honey!$"

ChandraVillage_PlayerHouse_1F_Text_OhAlmostForgot:
	.string "{COLOR}{RED}Oh, {PLAYER}!\n"
	.string "I almost forgot!\p"
	.string "As promised, here are your new shoes.\p"
	.string "They will put a little more spring in\nyour step.$"

ChandraVillage_PlayerHouse_1F_Text_ReceivedRunningShoes:
	.string "{PLAYER} received Running Shoes!$"

ChandraVillage_PlayerHouse_1F_Text_EquipShoes:
	.string "{PLAYER} equipped the shoes…\n"
	.string "A perfect fit!$"

ChandraVillage_PlayerHouse_1F_Text_TheyLookGreat:
	.string "{COLOR}{RED}They look great, {PLAYER}!\p"
	.string "Don't get them too dirty running\n"
	.string "around in the mud.\p"
	.string "Bye, honey!$"

ChandraVillage_PlayerHouse_1F_Text_OhPlayer:
	.string "{COLOR}{RED}Oh, {PLAYER}!$"

ChandraVillage_PlayerHouse_1F_Text_AlmostForgot:
	.string "{COLOR}{RED}I almost forgot…\n"
	.string "As promised, here are your new shoes.\p"
	.string "They will put a little more spring in\n"
	.string "your step.$"
