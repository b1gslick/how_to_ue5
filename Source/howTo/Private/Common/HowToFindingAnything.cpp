// Fill out your copyright notice in the Description page of Project Settings.

#include "Common/HowToFindingAnything.h"
#include "Editor/UnrealEdEngine.h"
#include "UnrealEdGlobals.h"
#include "LevelEditor.h"

void UHowToFindingAnything::PlayInEditor()
{
    /* FLevelEditorModule& LevelEditorModule =
        FModuleManager::GetModuleChecked<FLevelEditorModule>(
            TEXT("LevelEditor"));
    FRequestPlaySessionParams SessionParams;
    SessionParams.DestinationSlateViewport =
        LevelEditorModule.GetFirstActiveViewport();
    GUnrealEd->RequestPlaySession(SessionParams);*/
}

void UHowToFindingAnything::OpenLevelBlueprint() {}
