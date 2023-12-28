// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HowToFindingAnything.generated.h"

UCLASS()
class HOWTO_API UHowToFindingAnything : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /*
     * Play in the active viewport
     */
    UFUNCTION(BlueprintCallable, Category = "How To Find Anything")
    static void PlayInEditor();

    /*
     * Open the level blueprint of the current level
     */
    UFUNCTION(BlueprintCallable, Category = "How To Find Anything")
    static void OpenLevelBlueprint();
};
