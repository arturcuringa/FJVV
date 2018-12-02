#include "activationRecord.h"
#include <stdexcept>
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
    auto it = currentActivationRecord->memory.find(name);
    if (it != currentActivationRecord->memory.end()) return it->second;
    else return __accessOnRecord(currentActivationRecord->scopeParent, name);
}

void* __accessOnRecord(const std::shared_ptr<ActivationRecord> &ar, const std::string &name) {
    
    if(ar == mainActivationRecord && ar->memory.find(name) == ar->memory.end() ) return nullptr;
    auto it = ar->memory.find(name);
    if (it != ar->memory.end()) return it->second;
    else return __accessOnRecord(ar->scopeParent, name);
}

