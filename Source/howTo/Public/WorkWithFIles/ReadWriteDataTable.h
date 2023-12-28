// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteDataTable.generated.h"

class UDataTable;

UCLASS()
class UReadWriteDataTable : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    /**
     *   Editor Only - Will not work in packaged build.
     *
     * Import a data table from a json or csv file
     *
     * @param SourcePath         The path of the source file:
     *                           "c:/temp/myTexture.csv"
     * @param DestinationPath    The path of the imported asset:
     *                           "/Game/Folder/MyDataTable"
     * @param StructClass        The structure to use for this data table
     * @param bOutSuccess        If the action was a succes or not
     * @param OutInMessage       More information about the action's result
     *
     *  @return The imported data table
     **/
    UFUNCTION(BlueprintCallable, Category = "Import Basic Table")
    static UDataTable* ImportDataTableFromJsonOrCsv(FString SourcePath,
        FString DestinationPath, UScriptStruct* StructClass, bool& bOutSuccess,
        FString& OutInfoMessage);

    /**
     *   Editor Only - Will not work in packaged build.
     *
     * Export a data table from a json or csv file
     *
     * @param FilePath           The path of the output file:
     *                           "c:/temp/myTexture.csv"
     * @param DataTable          The data table to export
     * @param bOutSuccess        If the action was a succes or not
     * @param OutInMessage       More information about the action's result
     *
     *  @return The imported data table
     **/
    UFUNCTION(BlueprintCallable, Category = "Import Basic Asstes")
    static void ExportDataTableFromJsonOrCsv(FString FilePath,
        UDataTable* DataTable, bool& bOutSuccess, FString& OutInfoMessage);
};