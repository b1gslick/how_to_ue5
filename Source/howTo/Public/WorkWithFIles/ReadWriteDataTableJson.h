// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteDataTableJson.generated.h"

struct FAqTestStruct;

UCLASS()
class UReadWriteDataTableJson : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     *  Editor Only - Will not workk in packaged build.
     *
     * Read series of struct based on a json file formated like a data table
     *
     * @param FilePath           The path of the source file:
     * "C:/Temp/MyJson.json"
     * @param bOutSuccess        If The action was a succes or not
     * @param OutInfoMessage     More information about the action's result
     *
     * @return The sctructs
     */

    UFUNCTION(BlueprintCallable, Category = "Read write Data Table json")
    static TMap<FString, FAqTestStruct> ReadStructFromJsonFile_DataTableFormat(
        FString FilePath, bool& bOutSuccess, FString& OutInfoMessage);

    /**
     *  Editor Only - Will not workk in packaged build.
     *
     * Write series of struct based to a json file formated like a data table
     *
     * @param FilePath           The path of the source file:
     * "C:/Temp/MyJson.json"
     * @param RowsToStruct       The structs to write in the json
     * @param bOutSuccess        If The action was a succes or not
     * @param OutInfoMessage     More information about the action's result
     *
     */

    UFUNCTION(BlueprintCallable, Category = "Read write Data Table json")
    static void WriteStructToJsonFile_DataTableFormat(FString FilePath,
        TMap<FString, FAqTestStruct> RowsToStruct, bool& bOutSuccess,
        FString& OutInfoMessage);
};
