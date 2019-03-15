// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MOBA : ModuleRules
{
	public MOBA(ReadOnlyTargetRules Target) : base(Target)
    {
		PrivatePCHHeaderFile = "Private/MOBAPrivatePCH.h";
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "flann",
                "mqtt",
                "lz4",
				// ... add      other public dependencies that you statically link with here ...
			}
			);
        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Paper2D",
                "AIModule",
                "InputCore",
                "UMG",
                "HeadMountedDisplay",
                "Json",
                "WebUI",
				// ... add private dependencies that you statically link with here ...	
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
