#ifndef __ACTIVATION__
#define __ACTIVATION__


#include <memory>
#include <unordered_map>

struct ActivationRecord {
    std::shared_ptr<ActivationRecord> parent;
    std::shared_ptr<ActivationRecord> scopeParent;
    
    std::unordered_map<std::string, void*> memory;
    int _return;
};


void __instantiate(const std::string &name, void* ptr);
void* __allocate(int typeSize);
void __createNewActivationRecord();
void* __access(const std::string &name);

#endif
