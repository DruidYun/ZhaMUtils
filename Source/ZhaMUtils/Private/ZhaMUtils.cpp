#include "ZhaMUtils.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FZhaMUtilsModule"

void FZhaMUtilsModule::StartupModule()
{
	// 初始化逻辑（可为空）
}

void FZhaMUtilsModule::ShutdownModule()
{
	// 清理逻辑（可为空）
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FZhaMUtilsModule, ZhaMUtils)
