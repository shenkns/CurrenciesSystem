// Copyright shenkns Currencies System Developed With Unreal Engine. All Rights Reserved 2023.

#pragma once

#include "Stats/Stat.h"

#include "CurrencyStat.generated.h"

class UCurrencyData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurrencyChangeEvent, UCurrencyData*, Currency, int, Amount, int, Delta);

UCLASS()
class CURRENCIESSYSTEM_API UCurrencyStat : public UStat
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Profile|Stats|Currency")
	FCurrencyChangeEvent OnCurrencyChange;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats|Currency")
	TMap<UCurrencyData*, int> Currencies;

public:

	UFUNCTION(BlueprintPure, Category = "Stats|Currency", meta = (CompactNodeTitle = "GetCurrency"))
	int GetCurrency(UCurrencyData* Currency) const;

	UFUNCTION(BlueprintPure, Category = "Stats|Currency", meta = (CompactNodeTitle = "HasCurrency"))
	bool HasCurrency(UCurrencyData* Currency, int Amount) const;

	UFUNCTION(BlueprintCallable, Category = "Stats|Currency", meta = (CompactNodeTitle = "SetCurrency"))
	bool SetCurrency(UCurrencyData* Currency, int Amount);
	
	UFUNCTION(BlueprintCallable, Category = "Stats|Currency", meta = (CompactNodeTitle = "ChangeCurrency"))
	bool ChangeCurrency(UCurrencyData* Currency, int Delta);

	UFUNCTION(BlueprintCallable, Category = "Stats|Currency", meta = (CompactNodeTitle = "ChangeCurrencies"))
	bool ChangeCurrencies(const TMap<UCurrencyData*, int>& Values);
};
