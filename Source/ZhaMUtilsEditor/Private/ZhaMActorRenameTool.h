// ZhaMActorRenameTool.h
#pragma once

#include "CoreMinimal.h"

class ZHAMUTILSEDITOR_API FZhaMActorRenameTool
{
public:
	/** 批量将所有选中Actor的名字中的#替换为_ */
	static void RenameSelectedActors(const FString& from,const FString& to);

	static void OpenActorRenameDialog();
};
