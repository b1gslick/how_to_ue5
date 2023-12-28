// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "ReadWriteJson.generated.h"

class FJsonObject;

USTRUCT(BlueprintType, Category = "Read write json")
struct FAqTestStruct : public FTableRowBase
{
    GENERATED_BODY()

    // These variables are visible in both Blueprint and is in Json
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read write Json")
    FString MyString = "Liama";
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read write Json")
    bool MyBool = true;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read write Json")
    float MyFloat = 123.456f;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read write Json")
    int MyInt = 123;
    // These variables are not visible in blueprint, but are still visible in
    // json
public:
    UPROPERTY()
    FVector MyVector = {1.f, 2.f, 3.f};
    UPROPERTY()
    FRotator MyRotator = {90.0f, 180.0f, 270.0f};
    UPROPERTY()
    FTransform MyTransform;

public:
    FString MyOtherStirng = "This variables will not be in the json because "
                            "it's not flagged as an UPROPERTY()";
};

UCLASS()
class UReadWriteJson : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Open a json file, read its content and dump it into a structure
     *
     * @param JsonFilePath      The path of your json file: "C:/tmp/myJson.json"
     * @param bOutSuccess       If the action was a succes or not
     * @param OutInfoMessage    More information about the action's result
     *
     * @return The structure content of your json file
     **/
    UFUNCTION(BlueprintCallable, Category = "Read Write Json")
    static FAqTestStruct ReadStructFromJsonFile(
        FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage);

    /**
     * Convert your structure to a string, create a json file and dump the
     * string in it
     *
     * @param JsonFilePath      The path of your json file: "C:/tmp/myJson.json"
     * @param Struct            The Struct to want to write in the file
     * @param bOutSuccess       If the action was a succes or not
     * @param OutInfoMessage    More information about the action's result
     *
     **/
    UFUNCTION(BlueprintCallable, Category = "Read Write Json")
    static void WriteStructToJsonFile(FString JsonFilePath,
        FAqTestStruct Struct, bool& bOutSuccess, FString& OutInfoMessage);

public:
    /**
     * Open a json file, read its content and convert it to a JsonObject
     *
     * @param JsonFilePath      The path of your json file:
     *"C:/tmp/myJson.json"
     * @param bOutSuccess       If the action was a succes or not
     * @param OutInfoMessage    More information about the action's result
     *
     * @return The JsonObject content of your json file
     **/
    static TSharedPtr<FJsonObject> ReadJson(
        FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage);
    /**
     * Convert your JsonObject to a string, create a json file and dump the
     * string in it
     *
     * @param JsonFilePath      The path of your json file: "C:/tmp/myJson.json"
     * @param JsonObject        The Json Object to want to write in the file
     * @param bOutSuccess       If the action was a succes or not
     * @param OutInfoMessage    More information about the action's result
     *
     **/
    static void WriteJson(FString JsonFilePath,
        TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess,
        FString& OutInfoMessage);
};
