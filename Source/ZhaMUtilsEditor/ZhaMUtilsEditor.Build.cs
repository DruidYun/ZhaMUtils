using UnrealBuildTool;

public class ZhaMUtilsEditor : ModuleRules
{
    public ZhaMUtilsEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "CoreUObject", "Engine", "InputCore", "UnrealEd", "EditorStyle", "Slate", "SlateCore"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "Slate",
            "SlateCore",
            "ToolMenus",
            "LevelEditor",
            "Projects"
        });

        
        
    }
}