// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ULTIMATEUE4_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

    /** Reference to the UMG in the editor */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
    TSubclassOf<class UUserWidget>HUDOverlayAsset;

    /** Variable to hold the widget after creating it */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
    UUserWidget* HUDOverlay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
    TSubclassOf<UUserWidget> WEnemyHealthBar;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widget")
    UUserWidget* EnemyHealthBar;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
    TSubclassOf<UUserWidget> WPauseMenu;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widget")
    UUserWidget* PauseMenu;

    bool bPauseMenuVisible;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD")
    void DisplayPauseMenu();
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD")
    void RemovePauseMenu();

    void TogglePauseMenu();

    bool bEnemyHealthBarVisible;
    void DisplayEnemyHealthBar();
    void RemoveEnemyHealthBar();

    FVector EnemyLocation;

    void GameModeOnly();

protected:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;
};
