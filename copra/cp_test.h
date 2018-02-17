//
//  cp_test.hpp
//  cocos2d_js_bindings
//
//  Created by cHong on 2018/1/4.
//

#ifndef cp_test_hpp
#define cp_test_hpp

#include <vector>
#include <functional>
#include "cocos2d.h"

namespace copra {
    class TestDelegate{
    public:
        virtual void fight()=0;
    };
    
    class SubTest{
    public:
        SubTest();
        void print();
        ~SubTest();
    };
    
    class SubTest1{
    public:
        SubTest1();
        void print();
        ~SubTest1();
    };
    
    class Test{
    public:
        static void staticTestFunc();
        Test();
        ~Test();
        int getCount();
        void print();
        void fight();
        void setDelegate(TestDelegate* delegate);
        void setCallback(std::function<void(int)>& callback);
        SubTest* getTest();
        SubTest1* getTest1();
        int getArrayLength(const std::vector<int>& list);
    private:
        TestDelegate* delegate_;
        SubTest* sub_test_;
        SubTest1* sub_test1_;
        std::function<void(int)> callback_;
        int age_;
    };
}

#endif /* cp_test_hpp */
