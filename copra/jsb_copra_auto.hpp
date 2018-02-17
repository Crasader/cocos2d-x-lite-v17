#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_copra_SubTest_proto;
extern se::Class* __jsb_copra_SubTest_class;

bool js_register_copra_SubTest(se::Object* obj);
bool register_all_cp(se::Object* obj);
SE_DECLARE_FUNC(js_cp_SubTest_print);
SE_DECLARE_FUNC(js_cp_SubTest_SubTest);

extern se::Object* __jsb_copra_SubTest1_proto;
extern se::Class* __jsb_copra_SubTest1_class;

bool js_register_copra_SubTest1(se::Object* obj);
bool register_all_cp(se::Object* obj);
SE_DECLARE_FUNC(js_cp_SubTest1_print);
SE_DECLARE_FUNC(js_cp_SubTest1_SubTest1);

extern se::Object* __jsb_copra_Test_proto;
extern se::Class* __jsb_copra_Test_class;

bool js_register_copra_Test(se::Object* obj);
bool register_all_cp(se::Object* obj);
SE_DECLARE_FUNC(js_cp_Test_getTest1);
SE_DECLARE_FUNC(js_cp_Test_fight);
SE_DECLARE_FUNC(js_cp_Test_setCallback);
SE_DECLARE_FUNC(js_cp_Test_print);
SE_DECLARE_FUNC(js_cp_Test_getCount);
SE_DECLARE_FUNC(js_cp_Test_getTest);
SE_DECLARE_FUNC(js_cp_Test_getArrayLength);
SE_DECLARE_FUNC(js_cp_Test_staticTestFunc);
SE_DECLARE_FUNC(js_cp_Test_Test);

