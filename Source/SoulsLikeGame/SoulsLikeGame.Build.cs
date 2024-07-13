// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SoulsLikeGame : ModuleRules
{
	public SoulsLikeGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
