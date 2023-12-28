// Fill out your copyright notice in the Description page of Project Settings.

#include "WorkWithFIles/ReadWriteJson.h"
#include "WorkWithFIles/ReadWriteFile.h"

#include "Serialization/JsonSerializer.h"  // Json
#include "JsonObjectConverter.h"           // JsonUtilities

FAqTestStruct UReadWriteJson::ReadStructFromJsonFile(
    FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
    // Try to read generic json object from file
    TSharedPtr<FJsonObject> JsonObject =
        ReadJson(JsonFilePath, bOutSuccess, OutInfoMessage);
    if (!bOutSuccess)
    {
        return FAqTestStruct();
    }
    FAqTestStruct RetAqTestStruct;

    // try to convert generic json object to the desired structure. Output goes
    // in RetAqTestStruct
    if (!FJsonObjectConverter::JsonObjectToUStruct<FAqTestStruct>(
            JsonObject.ToSharedRef(), &RetAqTestStruct))

    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(
            TEXT("Read Struct json failed - Was not able to convert the json "
                 "object to your desired structure. Is It the right format / "
                 "string? - '%s'"),
            *JsonFilePath);
    }

    bOutSuccess = true;
    OutInfoMessage = FString::Printf(
        TEXT("Read Struct Json Succeeded - '%s'"), *JsonFilePath);
    return RetAqTestStruct;
}

void UReadWriteJson::WriteStructToJsonFile(FString JsonFilePath,
    FAqTestStruct Struct, bool& bOutSuccess, FString& OutInfoMessage)
{
    // Tru to convert struct to generic json object
    TSharedPtr<FJsonObject> JsonObject =
        FJsonObjectConverter::UStructToJsonObject(Struct);
    if (JsonObject == nullptr)
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(
            TEXT("Write Struct Json Failed - Was not able to convert the "
                 "struct to a json object. This shouldn't really happen."));
        return;
    }
    // Try to write json to file
    WriteJson(JsonFilePath, JsonObject, bOutSuccess, OutInfoMessage);
}

TSharedPtr<FJsonObject> UReadWriteJson::ReadJson(
    FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
    // Try to read file
    FString JsonString = UReadWriteFile::ReadStringFromFile(
        JsonFilePath, bOutSuccess, OutInfoMessage);
    if (!bOutSuccess)
    {
        return nullptr;
    }

    TSharedPtr<FJsonObject> RetJsonObject;

    // Try to convert string to json object. Output goes in RetJsonObject
    if (!FJsonSerializer::Deserialize(
            TJsonReaderFactory<>::Create(JsonString), RetJsonObject))
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(
            TEXT("Read json failed - Was not able to deserialize then json "
                 "string. Is it the right format? - '%s'"),
            *JsonString);
        return nullptr;
    }

    bOutSuccess = true;
    OutInfoMessage =
        FString::Printf(TEXT("Read Json Succeeded - '%s'"), *JsonFilePath);
    return RetJsonObject;
}

void UReadWriteJson::WriteJson(FString JsonFilePath,
    TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess,
    FString& OutInfoMessage)
{
    FString JsonString;

    if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(),
            TJsonWriterFactory<>::Create(&JsonString, 0)))
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(
            TEXT("Write json failed - Was not able to serialize json to"
                 "string. Is the jsonObject valid?"));
        return;
    }

    // Tryy to write json stirng to file
    UReadWriteFile::WriteStringToFile(
        JsonFilePath, JsonString, bOutSuccess, OutInfoMessage);
    if (!bOutSuccess)
    {
        return;
    }
    bOutSuccess = true;
    OutInfoMessage = FString::Printf(
        TEXT("Write to Json file Succeeded - '%s'"), *JsonFilePath);
    return;
}
