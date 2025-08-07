#pragma once

#include "Modules/ModuleManager.h"

class FZhaMUtilsModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
