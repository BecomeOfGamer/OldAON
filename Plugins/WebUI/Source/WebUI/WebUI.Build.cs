// Copyright 2017 Tracer Interactive, LLC. All Rights Reserved.
namespace UnrealBuildTool.Rules
{
	public class WebUI : ModuleRules
	{
		public WebUI(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
				    "CoreUObject",
					"Engine",
                    "Slate",
                    "SlateCore",
					"UMG"
				}
			);

            if (Target.Type != TargetType.Server)
                PublicDependencyModuleNames.AddRange(
				    new string[]
				    {
                        "WebBrowserExtension"
                    }
			    );

		    PrivateDependencyModuleNames.AddRange(new string[]
            {
                "Json",
                "InputCore",
            });

            if (Target.Type != TargetType.Server)
                PrivateDependencyModuleNames.AddRange(new string[]
                {
                    "WebBrowserExtension"
                });
		}
	}
}
