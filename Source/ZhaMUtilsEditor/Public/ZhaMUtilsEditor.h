#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FZhaMUtilsEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    
private:
    void RegisterMenus();
};
