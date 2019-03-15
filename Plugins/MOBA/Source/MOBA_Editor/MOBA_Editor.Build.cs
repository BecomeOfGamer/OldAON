// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MOBA_Editor : ModuleRules
{
	public MOBA_Editor(ReadOnlyTargetRules Target) : base(Target)
    {
		PrivatePCHHeaderFile = "Private/MOBA_EditorPrivatePCH.h";
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);

        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UnrealEd",
                "Paper2D",
				// ... add private dependencies that you statically link with here ...	
				"MOBA",
                "AIModule",
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
