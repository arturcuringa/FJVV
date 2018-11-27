#include "activationRecord.h"


std::shared_ptr<ActivationRecord> currentActivationRegistry;
std::shared_ptr<ActivationRecord> mainActivationRegistry;

void __startActivationRecord() {
    __createNewActivationRecord();
    mainActivationRegistry = currentActivationRegistry;
}

void* __allocate(int typeSize) {
    return new void*[typeSize];
}

void __instantiate(const std::string &name, void* ptr) {
    currentActivationRegistry->memory.insert({name, ptr});
}

void __createNewActivationRecord() {
    std::shared_ptr<ActivationRecord> ar = std::shared_ptr<ActivationRecord>(new ActivationRecord());
    ar->parent = currentActivationRegistry;
    ar->scopeParent = mainActivationRegistry;
    currentActivationRegistry = ar;
}

void __destroyActivationRecord() {
    currentActivationRegistry = currentActivationRegistry->parent;
}

void* __access(const std::string &name) {
    return currentActivationRegistry->memory.find(name)->second;
}
