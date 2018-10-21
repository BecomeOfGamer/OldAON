// Copyright 1998-2015 damody, Inc. All Rights Reserved.

using UnrealBuildTool;

public class lz4 : ModuleRules
{
    public lz4(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        string lz4Path = Target.UEThirdPartySourceDirectory + "lz4";
        
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            //string LibPath = lz4Path + "/lib/Win64/VS2017";
            string LibPath = lz4Path + "/lib";
			PublicLibraryPaths.Add(LibPath);
			PublicAdditionalLibraries.Add("liblz4_static.lib");
        }
        else
        {
            string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString());
            System.Console.WriteLine(Err);
            throw new BuildException(Err);
        }
        PublicIncludePaths.Add(lz4Path + "/inc");
    }
}
