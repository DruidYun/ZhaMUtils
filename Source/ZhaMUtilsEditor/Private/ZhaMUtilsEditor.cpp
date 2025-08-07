#include "ZhaMUtilsEditor.h"
#include "ZhaMActorRenameTool.h"

#include "LevelEditor.h"
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FZhaMUtilsEditorModule"

void FZhaMUtilsEditorModule::StartupModule()
{
	// 注册菜单
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FZhaMUtilsEditorModule::RegisterMenus));
}

void FZhaMUtilsEditorModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
}

void FZhaMUtilsEditorModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	// 扩展 LevelEditor 主菜单栏
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
	FToolMenuSection& Section = Menu->AddSection("ZhaMUtilsEditor", LOCTEXT("ZhaMUtils", "ZhaMUtils"));

	Section.AddMenuEntry(
		"RenameSelectedActors",
		LOCTEXT("RenameSelectedActors", "批量重命名Actor（# → _）"),
		LOCTEXT("RenameSelectedActorsTooltip", "将选中Actor名字中的#替换为_"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&FZhaMActorRenameTool::OpenActorRenameDialog))
	);
}
#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FZhaMUtilsEditorModule, ZhaMUtilsEditor)
