// Copyright shenkns Currencies System Developed With Unreal Engine. All Rights Reserved 2023.

#pragma once

#include "UObject/Object.h"

#include "CurrenciesSystemSettings.generated.h"

UCLASS(Config=Game, DefaultConfig)
class CURRENCIESSYSTEM_API UCurrenciesSystemSettings : public UObject
{
	GENERATED_BODY()

public:

	// Debug
	UPROPERTY(EditDefaultsOnly, Config, Category = "Debug")
	bool bShowDebugMessages;
};
