//
//  jsb_copra_mannual.hpp
//  cocos2d_js_bindings
//
//  Created by cHong on 2018/2/1.
//

#ifndef jsb_copra_mannual_hpp
#define jsb_copra_mannual_hpp

#include "base/ccConfig.h"
#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

bool register_all_cp_mannually(se::Object* obj);
bool js_register_cp_doubleNumber(se::Object* obj);
SE_DECLARE_FUNC(js_cp_doubleNumber);
SE_DECLARE_FUNC(js_cp_Test_setDelegate);
// static bool js_cp_Test_fight(se::State& s)

#endif /* jsb_copra_mannual_hpp */
