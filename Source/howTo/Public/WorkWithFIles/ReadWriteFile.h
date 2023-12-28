// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteFile.generated.h"

UCLASS()
class UReadWriteFile : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Open a text file and read its content
     *
     * @param FilePath The path of your file
     * @param bOutSuccess  If The action was a success or not
     * @param OutInfoMessage More information about the actions's result
     *
     * @return The string conten of your file
     *
     **/
    UFUNCTION(BlueprintCallable, Category = "Read write file")
    static FString ReadStringFromFile(
        FString FilePath, bool& bOutSuccess, FString& OutInfoMessage);

    /**
     * Create a text file and read its content
     *
     * @param FilePath The path of your file
     * @param String The string to want to write in the file
     * @param bOutSuccess  If The action was a success or not
     * @param OutInfoMessage More information about the actions's result
     *
     * @return The string conten of your file
     *
     **/

    UFUNCTION(BlueprintCallable, Category = "Read write file")
    static void WriteStringToFile(FString FilePath, FString String,
        bool& bOutSuccess, FString& OutInfoMessage);
};
