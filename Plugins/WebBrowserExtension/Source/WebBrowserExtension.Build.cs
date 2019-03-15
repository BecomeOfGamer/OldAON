// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class WebBrowserExtension : ModuleRules
{
	public WebBrowserExtension(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivatePCHHeaderFile = "Private/EWebPrivatePCH.h";
        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"ApplicationCore",
				"RHI",
				"InputCore",
				"Slate",
				"SlateCore",
				"Serialization",
            }
        );

        if (Target.Platform == UnrealTargetPlatform.Android)
		{
			// We need these on Android for external texture support
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"WebBrowserTexture",
					"Engine",
				}
			);

			// We need this one on Android for URL decoding
			PrivateDependencyModuleNames.Add("HTTP");
		}
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "CEF3",
                "CEF3Utils",
				// ... add      other public dependencies that you statically link with here ...
			}
            );

        if (Target.Platform == UnrealTargetPlatform.Win64
		||  Target.Platform == UnrealTargetPlatform.Win32
		||  Target.Platform == UnrealTargetPlatform.Mac
		||  Target.Platform == UnrealTargetPlatform.Linux)
		{
			PrivateDependencyModuleNames.Add("CEF3Utils");
			AddEngineThirdPartyPrivateStaticDependencies(Target,
				"CEF3"
				);

			if (Target.Type != TargetType.Server)
			{
				if (Target.Platform == UnrealTargetPlatform.Mac)
				{
					// Add contents of UnrealCefSubProcess.app directory as runtime dependencies
					foreach (string FilePath in Directory.EnumerateFiles(Target.RelativeEnginePath + "/Binaries/Mac/UnrealCEFSubProcess.app", "*", SearchOption.AllDirectories))
					{
						RuntimeDependencies.Add(FilePath);
					}
				}
				else if (Target.Platform == UnrealTargetPlatform.Linux)
				{
					RuntimeDependencies.Add("$(EngineDir)/Binaries/" + Target.Platform.ToString() + "/UnrealCEFSubProcess");
				}
				else
				{
					RuntimeDependencies.Add("$(EngineDir)/Binaries/" + Target.Platform.ToString() + "/UnrealCEFSubProcess.exe");
				}
			}
		}

        if (Target.Platform == UnrealTargetPlatform.PS4 &&
			Target.bCompileAgainstEngine)
		{
			PrivateDependencyModuleNames.Add("Engine");
		}

		bEnableShadowVariableWarnings = false;
	}
}
