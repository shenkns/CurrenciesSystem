// Copyright shenkns Currencies System Developed With Unreal Engine. All Rights Reserved 2023.

using UnrealBuildTool;

public class CurrenciesSystem : ModuleRules
{
	public CurrenciesSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange(
			new string[] 
			{
				"CurrenciesSystem/Public/"
			}
		);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"LogSystem",
				"DataSystem",
				"SaveLoadSystem",
				"ManagersSystem"
			}
		);
		
		PrivateIncludePathModuleNames.AddRange(
			new string[]
			{
				"LogSystem",
				"DataSystem",
				"SaveLoadSystem",
				"ManagersSystem"
			}
		);
	}
}
