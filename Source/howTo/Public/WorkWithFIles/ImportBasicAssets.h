// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImportBasicAssets.generated.h"

class UAssetImportTaks;
class UFactory;

UCLASS()
class UImportBasicAssets : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    /**
     * Editor Only - Will not work in packaged build.
     *
     * Create an import task that you can then process to import any kind of
     *assets
     *
     * @param SourcePath         The path of the source file:
     *                           "c:/temp/myTexture.png"
     * @param DestinationPath    The path of the imported asset:
     *                           "/Game/Folder/MyTexture
     * @param Extrafactory       Optional. Some asset types require a special
     *                           factory to import hem
     * @param ExtraOptions       Optional. Some asset types have some extra
     *                           settings you can set
     * @param bOutSuccess        If the action was a succes or not
     * @param OutInMessage       More information about the action's result
     *
     * @return The import taks
     **/
    UFUNCTION(BlueprintCallable, Category = "Import Basic Asstes")
    static UAssetImportTask* CreateImportTask(FString SourcePath,
        FString DestinationPath, UFactory* ExtraFactory, UObject* ExtraOptions,
        bool& bOutSuccess, FString& OutInfoMessage);

    /**
     * Editor Only - Will not work in packaged build.
     *
     * Process the import task to import the assets
     *
     * @param ImportTask         The task you want to process
     * @param bOutSuccess        If the action was a succes or not
     * @param OutInMessage       More information about the action's result
     *
     * @return The imported asset
     **/
    UFUNCTION(BlueprintCallable, Category = "Import Basic Asstes")
    static UObject* ProcessImportTask(UAssetImportTask* ImportTask,
        bool& bOutSuccess, FString& OutInfoMessage);

    /**
     *   Editor Only - Will not work in packaged build.
     *
     * Create adn process a basic import task.
     * Will work for the basic asset types like textures and sounds
     * can also be used for meshed, but you might not have all the contro you
     *want
     *
     * @param SourcePath         The path of the source file:
     *                           "c:/temp/myTexture.png"
     * @param DestinationPath    The path of the imported asset:
     *                           "/Game/Folder/MyTexture
     * @param bOutSuccess        If the action was a succes or not
     * @param OutInMessage       More information about the action's result
     *
     *  @return The imported asset
     **/
    UFUNCTION(BlueprintCallable, Category = "Import Basic Asstes")
    static UObject* ImportAsset(FString SourcePath, FString DestinationPath,
        bool& bOutSuccess, FString& OutInfoMessage);
};
