// Fill out your copyright notice in the Description page of Project Settings.

#include "WorkWithFIles/ReadWriteFile.h"
#include "HAL/PlatformFileManager.h"  // Core
#include "Misc/FileHelper.h"          // Core

FString UReadWriteFile::ReadStringFromFile(
    FString FilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
    // Check if the file exists
    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(
            TEXT("Read String from File filed - file doesn't exist - '%s'"),
            *FilePath);
        return "";
    }
    FString RetString = "";

    // Try to read the file. Output goes in RetString
    if (!FFileHelper::LoadFileToString(RetString, *FilePath))
    {
        bOutSuccess = false;
        OutInfoMessage =
            FString::Printf(TEXT("Read String from File filed - Was not able "
                                 "to read file. Is This a text file? - '%s'"),
                *FilePath);
        return "";
    }

    bOutSuccess = true;
    OutInfoMessage = FString::Printf(
        TEXT("Read String from File Succeeded - '%s'"), *FilePath);
    return RetString;
}

void UReadWriteFile::WriteStringToFile(FString FilePath, FString String,
    bool& bOutSuccess, FString& OutInfoMessage)
{
    // Try to write the string into the file
    if (!FFileHelper::SaveStringToFile(String, *FilePath))
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(
            TEXT("Write string to file failed - Was not able to write to file. "
                 "Is your file read only? Is the path valid?  - '%s'"),
            *FilePath);
        return;
    }
    bOutSuccess = true;
    OutInfoMessage = FString::Printf(
        TEXT("Write String to File Succeeded - '%s'"), *FilePath);
    return;
}