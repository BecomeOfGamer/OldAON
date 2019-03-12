// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;

public class mqtt : ModuleRules
{
	public mqtt(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string mqttbPath = Target.UEThirdPartySourceDirectory + "mqtt/";
		string mqttblibPath = mqttbPath + "lib/";
		
		PublicIncludePaths.Add(mqttbPath + "include");		
		if (Target.Platform == UnrealTargetPlatform.Win64)
        {
			if(Target.Configuration == UnrealTargetConfiguration.Debug)
				PublicLibraryPaths.Add(mqttblibPath + "Win64/Debug");
			else
				PublicLibraryPaths.Add(mqttblibPath + "Win64/Release");
			PublicAdditionalLibraries.Add("paho-mqttpp3.lib");
			PublicAdditionalLibraries.Add("ws2_32.lib");
			PublicAdditionalLibraries.Add("paho-mqtt3a.lib");
		}
		else
        {
            string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString());
            System.Console.WriteLine(Err);
            throw new BuildException(Err);
        }
	}
}
