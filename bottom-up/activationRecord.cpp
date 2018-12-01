#include "activationRecord.h"


std::shared_ptr<ActivationRecord>  currentActivationRecord; 
std::shared_ptr<ActivationRecord>  mainActivationRecord; 

void __startActivationRecord() {
    __createNewActivationRecord();
    mainActivationRecord = currentActivationRecord;
}

void* __allocate(int typeSize) {
    return new void*[typeSize];
}

void __instantiate(const std::string &name, void* ptr) {
    currentActivationRecord->memory.insert({name, ptr});
}

void __createNewActivationRecord() {
    std::shared_ptr<ActivationRecord> ar = std::shared_ptr<ActivationRecord>(new ActivationRecord());
    ar->parent = currentActivationRecord;
    ar->scopeParent = mainActivationRecord;
    currentActivationRecord = ar;
    currentActivationRecord->_return = 0 ;
}

void __destroyActivationRecord() {
    currentActivationRecord = currentActivationRecord->parent;
}

void* __access(const std::string &name) {
    return currentActivationRecord->memory.find(name)->second;
}
