// Fill out your copyright notice in the Description page of Project Settings.

#include "WorkWithFIles/ReadWriteDataTableJson.h"
#include "WorkWithFIles/ReadWriteDataTable.h"
#include "WorkWithFIles/ReadWriteJson.h"
#include "WorkWithFIles/ReadWriteFile.h"

#include "Engine/DataTable.h"  // Engine

TMap<FString, FAqTestStruct> UReadWriteDataTableJson::
    ReadStructFromJsonFile_DataTableFormat(
        FString FilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
    // Read file
    FString JsonString = UReadWriteFile::ReadStringFromFile(
        FilePath, bOutSuccess, OutInfoMessage);
    if (!bOutSuccess)
    {
        return TMap<FString, FAqTestStruct>();
    }

    // Create table and tell it which struct it's using
    UDataTable* Table = NewObject<UDataTable>();
    Table->RowStruct = FAqTestStruct::StaticStruct();

    // Populate data table
    Table->CreateTableFromJSONString(JsonString);

    // Retrieve the rows
    TArray<FName> RowNames = Table->GetRowNames();

    // Populate the rows
    TMap<FString, FAqTestStruct> RowsToStruct;

    for (FName RowName : RowNames)
    {
        FAqTestStruct* Row = Table->FindRow<FAqTestStruct>(RowName, nullptr);

        if (Row != nullptr)
        {
            RowsToStruct.Add(RowName.ToString(), *Row);
        }
    }

    // Return the rows
    bOutSuccess = true;
    OutInfoMessage = FString::Printf(
        TEXT("Read data table json succeeded - '%s'"), *FilePath);
    return RowsToStruct;
}

void UReadWriteDataTableJson::WriteStructToJsonFile_DataTableFormat(
    FString FilePath, TMap<FString, FAqTestStruct> RowsToStruct,
    bool& bOutSuccess, FString& OutInfoMessage)
{
    // Convert All rows to string
    TArray<FString> RowNames;
    RowsToStruct.GetKeys(RowNames);

    // Create data table and tell it which struct it's using
    UDataTable* Table = NewObject<UDataTable>();
    Table->RowStruct = FAqTestStruct::StaticStruct();

    // Add all rows to the data table
    for (FString RowName : RowNames)
    {
        Table->AddRow(FName(RowName), RowsToStruct[RowName]);
    }

    // Export to file
    UReadWriteDataTable::ExportDataTableFromJsonOrCsv(
        FilePath, Table, bOutSuccess, OutInfoMessage);
}