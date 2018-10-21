// Copyright 1998-2015 damody, Inc. All Rights Reserved.

using UnrealBuildTool;

public class flann : ModuleRules
{
    public flann(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        string flannPath = Target.UEThirdPartySourceDirectory + "flann";
        
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            //string LibPath = flannPath + "/lib/Win64/VS2017";
            string LibPath = flannPath + "/lib/Win64";
            if(Target.Configuration == UnrealTargetConfiguration.Debug)
				PublicLibraryPaths.Add(LibPath + "/Debug");
			else
				PublicLibraryPaths.Add(LibPath + "/Release");
			
			PublicAdditionalLibraries.Add("flann_cpp_s.lib");
            PublicAdditionalLibraries.Add("flann_s.lib");
        }
        else
        {
            string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString());
            System.Console.WriteLine(Err);
            throw new BuildException(Err);
        }
        PublicIncludePaths.Add(flannPath + "/inc");
    }
}
