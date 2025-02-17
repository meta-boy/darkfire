.set LOCALID_BLACKBELT, 1
.set LOCALID_RANGER, 2
.set LOCALID_PSYCHIC, 3
.set LOCALID_ACE_TRAINER, 4
.set LOCALID_GENTLEMAN, 5
.set LOCALID_SAILOR, 6

NorthstarArena_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NorthstarArena_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NorthstarArena_OnWarp
	.byte 0

NorthstarArena_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 2, NorthstarArena_EventStart
	map_script_2 VAR_STORYLINE_STATE, 4, NorthstarArena_RoundTwo
	map_script_2 VAR_STORYLINE_STATE, 6, NorthstarArena_RoundThree
	.2byte 0

NorthstarArena_OnWarp:
	map_script_2 VAR_STORYLINE_STATE, 2, NorthstarArena_InitRoomObjects
	map_script_2 VAR_STORYLINE_STATE, 4, NorthstarArena_InitRoomObjects
	map_script_2 VAR_STORYLINE_STATE, 6, NorthstarArena_InitRoomObjects
	.2byte 0

NorthstarArena_InitRoomObjects::
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showfollower
	end

NorthstarArena_EventStart::
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_PSYCHIC, NorthstarArena_RangerBattle
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_RANGER, NorthstarArena_PsychicBattle
	end

NorthstarArena_RoundTwo::
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_BLACK_BELT, NorthstarArena_OldManBattle
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_OLD_MAN, NorthstarArena_BlackBeltBattle
	end

NorthstarArena_RoundThree::
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_SAILOR, NorthstarArena_AceTrainerBattle
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_ACE_TRAINER, NorthstarArena_SailorBattle
	end

NorthstarArena_PsychicBattle::
	msgbox NorthstarArena_Text_TheArenaHasBeenSet, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_PSYCHIC, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PSYCHIC, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_IDidntGetAllTheWay, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 3
	goto NorthstarArena_NextRound
	end

NorthstarArena_RangerBattle::
	msgbox NorthstarArena_Text_TheArenaHasBeenSet, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_RANGER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_SoYoureTheNewTrainer, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 3
	goto NorthstarArena_NextRound
	end

NorthstarArena_BlackBeltBattle::
	msgbox NorthstarArena_Text_TheArenaIsReady, MSGBOX_AUTOCLOSE
	applymovement LOCALID_BLACKBELT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_BLACKBELT, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_WellMetTrainer, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 5
	goto NorthstarArena_NextRound
	end

NorthstarArena_OldManBattle::
	msgbox NorthstarArena_Text_TheArenaIsReady, MSGBOX_AUTOCLOSE
	applymovement LOCALID_GENTLEMAN, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_GENTLEMAN, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_TheChildrenOfToday, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 5
	goto NorthstarArena_NextRound
	end

NorthstarArena_SailorBattle::
	msgbox NorthstarArena_Text_BraceYourselves, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAILOR, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SAILOR, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_IfYouDontKnow, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 7
	goto NorthstarArena_NextRound
	end

NorthstarArena_AceTrainerBattle::
	msgbox NorthstarArena_Text_BraceYourselves, MSGBOX_AUTOCLOSE
	applymovement LOCALID_ACE_TRAINER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_ACE_TRAINER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_YoYoureTheOne, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 7
	goto NorthstarArena_NextRound
	end

NorthstarArena_NextRound::
	setfollowerwarppos DIR_EAST
	warpsilent MAP_NORTHSTAR_CITY_TOURNAMENT_4F, 10, 7
	waitstate
	end

NorthstarArena_Text_TheArenaHasBeenSet:
	.string "{COLOR}{RED}Announcer: The arena has been set!\n"
	.string "Trainers! Are you ready?!$"

NorthstarArena_Text_TheArenaIsReady:
	.string "{COLOR}{RED}Announcer: The arena is ready!\n"
	.string "Trainers, are you?!$"

NorthstarArena_Text_BraceYourselves:
	.string "{COLOR}{RED}Announcer: Brace yourselves, everyone!\n"
	.string "The final round is here!\p"
	.string "Trainers, ready yourselves!\n"
	.string "Good luck to both of you!$"

NorthstarArena_Text_SoYoureTheNewTrainer:
	.string "{COLOR}{RED}So…\pYou're the new Trainer around,\n"
	.string "aren't you?\p"
	.string "Time to find out if you can stand up\n"
	.string "to a Ranger of northern Tenjo!$"

NorthstarArena_Text_IDidntGetAllTheWay:
	.string "{COLOR}{BLUE}I didn't get all the way here by\n"
	.string "being a pushover…\l"
	.string "And this time's no different!\p"
	.string "Here I come!$"

NorthstarArena_Text_WellMetTrainer:
	.string "Well met, Trainer.\p"
	.string "What do you seek\n"
	.string "here? Fame? Money? Or victory?\p"
	.string "I am here for victory.\n"
	.string "Absolute victory.\p"
	.string "Come, now.\n"
	.string "Let's do it.$"

NorthstarArena_Text_TheChildrenOfToday:
	.string "The children of today haven't endured\n"
	.string "the harsh training of the old days.\p"
	.string "You'll be sorry you were born in this\n"
	.string "generation! Hahaha!$"

NorthstarArena_Text_IfYouDontKnow:
	.string "{COLOR}{BLUE}If you don't know which port you're\n"
	.string "sailing to, no wind is favorable.\p"
	.string "I hope you know what you're doing,\n"
	.string "otherwise you are going overboard!$"

NorthstarArena_Text_YoYoureTheOne:
	.string "{COLOR}{BLUE}Yo.\p"
	.string "You're the one who won the\n"
	.string "Laveria Tournament, right?\p"
	.string "Huh…\n"
	.string "Guess you think you're somebody now.\l"
	.string "We'll see!$"
