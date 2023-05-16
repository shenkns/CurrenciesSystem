// Copyright shenkns Currencies System Developed With Unreal Engine. All Rights Reserved 2023.

#pragma once

#include "Modules/ModuleManager.h"

CURRENCIESSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(LogCurrenciesSystem, Log, All)

class FCurrenciesSystemModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
private:

#if UE_EDITOR
	void RegisterSystemSettings() const;
	void UnregisterSystemSettings() const;
#endif
};
