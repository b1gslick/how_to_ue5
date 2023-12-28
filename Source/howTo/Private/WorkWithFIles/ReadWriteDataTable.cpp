// Fill out your copyright notice in the Description page of Project Settings.

#include "WorkWithFIles/ReadWriteDataTable.h"
#include "WorkWithFIles/ImportBasicAssets.h"
#include "WorkWithFIles/ReadWriteFile.h"
#include "WorkWithFIles/ReadWriteJson.h"

#include "Factories/ReimportDataTableFactory.h"  // UnrealEd (Editor Only)

UDataTable* UReadWriteDataTable::ImportDataTableFromJsonOrCsv(
    FString SourcePath, FString DestinationPath, UScriptStruct* StructClass,
    bool& bOutSuccess, FString& OutInfoMessage)
{
    // create factory to import a Data Table
    UReimportDataTableFactory* DtFactory =
        NewObject<UReimportDataTableFactory>();
    DtFactory->AutomatedImportSettings.ImportType =
        ECSVImportType::ECSV_DataTable;
    DtFactory->AutomatedImportSettings.ImportRowStruct = StructClass;

    // Create import Task
    UAssetImportTask* ImportTask =
        UImportBasicAssets::CreateImportTask(SourcePath, DestinationPath,
            DtFactory, nullptr, bOutSuccess, OutInfoMessage);
    if (!bOutSuccess)
    {
        return nullptr;
    }
    // import asset
    UObject* ImportedAsset = UImportBasicAssets::ProcessImportTask(
        ImportTask, bOutSuccess, OutInfoMessage);
    if (!bOutSuccess)
    {
        return nullptr;
    }

    // return imported asset
    bOutSuccess = true;
    OutInfoMessage = FString::Printf(
        TEXT("Import Data Table Succeeded - '%s'"), *DestinationPath);
    return Cast<UDataTable>(ImportedAsset);
}

void UReadWriteDataTable::ExportDataTableFromJsonOrCsv(FString FilePath,
    UDataTable* DataTable, bool& bOutSuccess, FString& OutInfoMessage)
{
    // Check if DataTable is valid
    if (DataTable == nullptr)
    {
        bOutSuccess = false;
        OutInfoMessage =
            FString::Printf(TEXT("Export Data Table to CSV Failed - "
                                 "data table is nullptr. FilePath: '%s'"),
                *FilePath);
        return;
    }
    // Convert table to string
    FString TableString;

    if (FilePath.Contains(".csv"))
    {
        TableString = DataTable->GetTableAsCSV();
    }
    else
    {
        TableString = DataTable->GetTableAsJSON();
    }

    // Write string to file
    UReadWriteFile::WriteStringToFile(
        FilePath, TableString, bOutSuccess, OutInfoMessage);
}
