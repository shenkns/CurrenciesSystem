// Copyright shenkns Currencies System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Module/CurrenciesSystemModule.h"

#if UE_EDITOR
#include "ISettingsModule.h"
#include "Module/CurrenciesSystemSettings.h"
#endif

IMPLEMENT_MODULE(FCurrenciesSystemModule, CurrenciesSystem)

CURRENCIESSYSTEM_API DEFINE_LOG_CATEGORY(LogCurrenciesSystem)

void FCurrenciesSystemModule::StartupModule()
{
#if UE_EDITOR
	RegisterSystemSettings();
#endif
}

void FCurrenciesSystemModule::ShutdownModule()
{
#if UE_EDITOR
	UnregisterSystemSettings();
#endif
}

#if UE_EDITOR
void FCurrenciesSystemModule::RegisterSystemSettings() const
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings(
			"Project",
			"Plugins",
			"Currencies System",
			FText::FromString(TEXT("Currencies System")),
			FText::FromString(TEXT("Configuration settings for Currencies System")),
			GetMutableDefault<UCurrenciesSystemSettings>()
		);
	}
}

void FCurrenciesSystemModule::UnregisterSystemSettings() const
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Currencies System");
	}
}
#endif
