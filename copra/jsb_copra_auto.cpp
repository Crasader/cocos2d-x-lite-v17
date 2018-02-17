#include "jsb_copra_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "copra.h"

se::Object* __jsb_copra_SubTest_proto = nullptr;
se::Class* __jsb_copra_SubTest_class = nullptr;

static bool js_cp_SubTest_print(se::State& s)
{
    copra::SubTest* cobj = (copra::SubTest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_SubTest_print : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->print();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_SubTest_print)

SE_DECLARE_FINALIZE_FUNC(js_copra_SubTest_finalize)

static bool js_cp_SubTest_constructor(se::State& s)
{
    copra::SubTest* cobj = new (std::nothrow) copra::SubTest();
    s.thisObject()->setPrivateData(cobj);
    se::NonRefNativePtrCreatedByCtorMap::emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cp_SubTest_constructor, __jsb_copra_SubTest_class, js_copra_SubTest_finalize)




static bool js_copra_SubTest_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (copra::SubTest)", s.nativeThisObject());
    return true;
}
SE_BIND_FINALIZE_FUNC(js_copra_SubTest_finalize)

bool js_register_cp_SubTest(se::Object* obj)
{
    auto cls = se::Class::create("SubTest", obj, nullptr, _SE(js_cp_SubTest_constructor));

    cls->defineFunction("print", _SE(js_cp_SubTest_print));
    cls->defineFinalizeFunction(_SE(js_copra_SubTest_finalize));
    cls->install();
    JSBClassType::registerClass<copra::SubTest>(cls);

    __jsb_copra_SubTest_proto = cls->getProto();
    __jsb_copra_SubTest_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_copra_SubTest1_proto = nullptr;
se::Class* __jsb_copra_SubTest1_class = nullptr;

static bool js_cp_SubTest1_print(se::State& s)
{
    copra::SubTest1* cobj = (copra::SubTest1*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_SubTest1_print : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->print();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_SubTest1_print)

SE_DECLARE_FINALIZE_FUNC(js_copra_SubTest1_finalize)

static bool js_cp_SubTest1_constructor(se::State& s)
{
    copra::SubTest1* cobj = new (std::nothrow) copra::SubTest1();
    s.thisObject()->setPrivateData(cobj);
    se::NonRefNativePtrCreatedByCtorMap::emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cp_SubTest1_constructor, __jsb_copra_SubTest1_class, js_copra_SubTest1_finalize)




static bool js_copra_SubTest1_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (copra::SubTest1)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        copra::SubTest1* cobj = (copra::SubTest1*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_copra_SubTest1_finalize)

bool js_register_cp_SubTest1(se::Object* obj)
{
    auto cls = se::Class::create("SubTest1", obj, nullptr, _SE(js_cp_SubTest1_constructor));

    cls->defineFunction("print", _SE(js_cp_SubTest1_print));
    cls->defineFinalizeFunction(_SE(js_copra_SubTest1_finalize));
    cls->install();
    JSBClassType::registerClass<copra::SubTest1>(cls);

    __jsb_copra_SubTest1_proto = cls->getProto();
    __jsb_copra_SubTest1_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_copra_Test_proto = nullptr;
se::Class* __jsb_copra_Test_class = nullptr;

static bool js_cp_Test_getTest1(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_getTest1 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        copra::SubTest1* result = cobj->getTest1();
        ok &= native_ptr_to_seval<copra::SubTest1>((copra::SubTest1*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cp_Test_getTest1 : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_getTest1)

static bool js_cp_Test_fight(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_fight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->fight();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_fight)

static bool js_cp_Test_setCallback(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_setCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (int)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](int larg0) -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= int32_to_seval(larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cp_Test_setCallback : Error processing arguments");
        cobj->setCallback(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cp_Test_setCallback)

static bool js_cp_Test_print(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_print : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->print();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_print)

static bool js_cp_Test_getCount(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_getCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getCount();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cp_Test_getCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_getCount)

static bool js_cp_Test_getTest(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_getTest : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        copra::SubTest* result = cobj->getTest();
        ok &= native_ptr_to_rooted_seval<copra::SubTest>((copra::SubTest*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cp_Test_getTest : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_getTest)

static bool js_cp_Test_getArrayLength(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_getArrayLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<int> arg0;
        ok &= seval_to_std_vector_int(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cp_Test_getArrayLength : Error processing arguments");
        int result = cobj->getArrayLength(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cp_Test_getArrayLength : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cp_Test_getArrayLength)

static bool js_cp_Test_staticTestFunc(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        copra::Test::staticTestFunc();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_staticTestFunc)

SE_DECLARE_FINALIZE_FUNC(js_copra_Test_finalize)

static bool js_cp_Test_constructor(se::State& s)
{
    copra::Test* cobj = new (std::nothrow) copra::Test();
    s.thisObject()->setPrivateData(cobj);
    se::NonRefNativePtrCreatedByCtorMap::emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cp_Test_constructor, __jsb_copra_Test_class, js_copra_Test_finalize)




static bool js_copra_Test_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (copra::Test)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        copra::Test* cobj = (copra::Test*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_copra_Test_finalize)

bool js_register_cp_Test(se::Object* obj)
{
    auto cls = se::Class::create("Test", obj, nullptr, _SE(js_cp_Test_constructor));

    cls->defineFunction("getTest1", _SE(js_cp_Test_getTest1));
    cls->defineFunction("fight", _SE(js_cp_Test_fight));
    cls->defineFunction("setCallback", _SE(js_cp_Test_setCallback));
    cls->defineFunction("print", _SE(js_cp_Test_print));
    cls->defineFunction("getCount", _SE(js_cp_Test_getCount));
    cls->defineFunction("getTest", _SE(js_cp_Test_getTest));
    cls->defineFunction("getArrayLength", _SE(js_cp_Test_getArrayLength));
    cls->defineStaticFunction("staticTestFunc", _SE(js_cp_Test_staticTestFunc));
    cls->defineFinalizeFunction(_SE(js_copra_Test_finalize));
    cls->install();
    JSBClassType::registerClass<copra::Test>(cls);

    __jsb_copra_Test_proto = cls->getProto();
    __jsb_copra_Test_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_cp(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("cp", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("cp", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_cp_Test(ns);
    js_register_cp_SubTest(ns);
    js_register_cp_SubTest1(ns);
    return true;
}

