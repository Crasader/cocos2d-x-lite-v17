//
//  cp_test.cpp
//  cocos2d_js_bindings
//
//  Created by cHong on 2018/1/4.
//

#include "cocos2d.h"
#include "cp_test.h"

using namespace std;

namespace copra {
    Test::Test():age_(10){
        sub_test_ = new SubTest();
        sub_test1_ = new SubTest1();
    }
    
    Test::~Test(){
        if(sub_test_)
            delete sub_test_;
    }
    
    void Test::staticTestFunc(){
        CCLOG("static function");
    }
    
    int Test::getCount(){
        return 3;
    }
    
    void Test::print(){
        CCLOG("hello world");
        if(sub_test_)
            sub_test_->print();
    }
    
    void Test::fight(){
        if(delegate_)
            delegate_->fight();
//        callback_(3);
        CCLOG("Test::fighting...");
    }
    
    void Test::setCallback(std::function<void(int)>& callback){
        callback_ = callback;
    }
    
    void Test::setDelegate(TestDelegate* delegate){
        delegate_ = delegate;
    }
    
    int Test::getArrayLength(const vector<int>& list){
        return static_cast<int>(list.size()) ;
    }
    
    SubTest* Test::getTest(){
        return sub_test_;
    }
    
    SubTest1* Test::getTest1(){
        return sub_test1_;
    }
    
    SubTest::SubTest(){
        CCLOG("ctor sub_test");
    }
    
    void SubTest::print(){
        CCLOG("sub_test hello world");
    }
    
    SubTest::~SubTest(){
        CCLOG("sub_test finalizing...");
    }
    
    SubTest1::SubTest1(){
        CCLOG("ctor sub_test1");
    }
    
    void SubTest1::print(){
        CCLOG("sub_test1 hello world");
    }
    
    SubTest1::~SubTest1(){
        CCLOG("sub_test1 finalizing...");
    }
}
