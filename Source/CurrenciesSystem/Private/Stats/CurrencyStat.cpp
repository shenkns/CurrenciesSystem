// Copyright shenkns Currencies System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Stats/CurrencyStat.h"

#include "Log.h"
#include "Managers/StatsManager.h"
#include "Data/CurrencyData.h"
#include "Log/Details/LocalLogCategory.h"
#include "Module/CurrenciesSystemModule.h"

DEFINE_LOG_CATEGORY_LOCAL(LogCurrenciesSystem);

int UCurrencyStat::GetCurrency(UCurrencyData* Currency) const
{
	if(!Currency) return 0;

	const int* Amount = Currencies.Find(Currency);
	return Amount ? *Amount : 0;
}

bool UCurrencyStat::HasCurrency(UCurrencyData* Currency, int Amount) const
{
	return GetCurrency(Currency) >= Amount;
}

bool UCurrencyStat::SetCurrency(UCurrencyData* Currency, int Amount)
{
	if(!Currency) return false;

	if(Amount < 0) return false;

	int Delta;
	
	if(int* OldAmount = Currencies.Find(Currency))
	{
		Delta = FMath::Max(0, Amount) - *OldAmount;
		*OldAmount = FMath::Max(0, Amount);
		GetManager()->SaveStats();
	}
	else
	{
		Currencies.Add(Currency, FMath::Max(0, Amount));
		Delta = FMath::Max(0, Amount);
		GetManager()->SaveStats();
	}

	LOG(Display, "{} Changed To {}, Now {}", *Currency->GetName(), Delta, FMath::Max(0, Amount));
	
	OnCurrencyChange.Broadcast(Currency, FMath::Max(0, Amount), Delta);

	return true;
}

bool UCurrencyStat::ChangeCurrency(UCurrencyData* Currency, int Delta)
{
	return SetCurrency(Currency, GetCurrency(Currency) + Delta);
}

bool UCurrencyStat::ChangeCurrencies(const TMap<UCurrencyData*, int>& Values)
{
	bool ChangedAll = true;

	for(const TTuple<UCurrencyData*, int>& Pair : Values)
	{
		if(!Pair.Key || Pair.Value < 0)
		{
			ChangedAll = false;
			continue;
		}
		
		ChangeCurrency(Pair.Key, Pair.Value);
	}

	return ChangedAll;
}
