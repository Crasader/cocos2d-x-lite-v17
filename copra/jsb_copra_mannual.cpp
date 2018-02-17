//
//  jsb_copra_mannual.cpp
//  cocos2d_js_bindings
//
//  Created by cHong on 2018/2/1.
//

#include "jsb_copra_mannual.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "cp_util.hpp"
#include "cp_test.h"

extern se::Class* __jsb_copra_Test_class;
extern se::Object* __jsb_copra_Test_proto;

class JSTestDelegate: public copra::TestDelegate{
    public:
        JSTestDelegate(se::Object* obj):jsDelegate(obj){
            assert(obj);
        }
        
        void fight(){
            se::ValueArray args;
            ExecuteFunctionWithOwner("fight", args);
        }
    private:
        void ExecuteFunctionWithOwner(const char* function_name, se::ValueArray& args){
            se::Value value;
            if(jsDelegate->getProperty(function_name, &value)){
                se::Object* jsFunc = value.toObject();
                if(jsFunc && jsFunc->isFunction()){
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
                    
                    jsFunc->call(args, jsDelegate);
                    return;
                }
            }
            
            SE_REPORT_ERROR("Delegate does not have a function named %s", function_name);
        }
        
        se::Object* jsDelegate;
    };

bool js_register_cp_doubleNumber(se::Object* obj){
    obj->defineFunction("doubleNumber", _SE(js_cp_doubleNumber));
    return true;
}

bool js_cp_doubleNumber(se::State& s){
    const auto args = s.args();
    int argc = (int)args.size();
    if(argc == 1){
        se::Value arg0 = args[0];
        int n = arg0.toInt32();
        n = copra::doubleNumber(n);
        s.rval().setInt32(n);
        return true;
    }
    
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cp_doubleNumber);

bool js_cp_Test_setDelegate(se::State& s){
    const auto& args = s.args();
    int argc = (int)args.size();
    if(argc == 1){
        se::Object* jsTest = s.thisObject();
        copra::Test* test = (copra::Test*)s.nativeThisObject();
        
        se::Object* jsDelegate = args[0].toObject();
        jsTest->attachObject(jsDelegate);
        JSTestDelegate* jsTestDelegate = new JSTestDelegate(jsDelegate);
        test->setDelegate(jsTestDelegate);
        return true;
    }
    
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cp_Test_setDelegate);

bool register_all_cp_mannually(se::Object* obj){
    se::Value nsVal;
    if(!obj->getProperty("cp", &nsVal)){
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("cp", nsVal);
    }
    
    se::Object* ns = nsVal.toObject();
    js_register_cp_doubleNumber(ns);
    
    __jsb_copra_Test_proto->defineFunction("setDelegate", _SE(js_cp_Test_setDelegate));
    return true;
}
