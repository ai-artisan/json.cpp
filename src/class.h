#pragma once

#include "common.h"

#define JSON_CONSTRUCTOR_DEFAULT_IMPL(C)\
    C::C(){}
#define JSON_DESTRUCTOR_DEFAULT_IMPL(C)\
    C::~C(){}
#define JSON_CD_DEFAULT_IMPL(C)\
    C::C(){}\
    C::~C(){}

#define JSON_CONSTRUCTOR_DEFAULT_IMPL_SCOPE(C, SCOPE)\
    SCOPE::C::C(){}
#define JSON_DESTRUCTOR_DEFAULT_IMPL_SCOPE(C, SCOPE)\
    SCOPE::C::~C(){}
#define JSON_CD_DEFAULT_IMPL_SCOPE(C, SCOPE)\
    SCOPE::C::C(){}\
    SCOPE::C::~C(){}

#define JSON_CONSTRUCTOR_DEFAULT_IMPL_TEMPLATE(C, TMPDEF, TMPSPE)\
    template TMPDEF\
    C TMPSPE::C(){}
#define JSON_DESTRUCTOR_DEFAULT_IMPL_TEMPLATE(C, TMPDEF, TMPSPE)\
    template TMPDEF\
    C TMPSPE::~C(){}
#define JSON_CD_DEFAULT_IMPL_TEMPLATE(C, TMPDEF, TMPSPE)\
    template TMPDEF\
    C TMPSPE::C(){}\
    template TMPDEF\
    C TMPSPE::~C(){}

#define JSON_CONSTRUCTOR_DEFAULT_IMPL_SCOPE_TEMPLATE(C, SCOPE, TMPDEF, TMPSPE)\
    template TMPDEF\
    SCOPE::C TMPSPE::C(){}
#define JSON_DESTRUCTOR_DEFAULT_IMPL_SCOPE_TEMPLATE(C, SCOPE, TMPDEF, TMPSPE)\
    template TMPDEF\
    SCOPE::C TMPSPE::~C(){}
#define JSON_CD_DEFAULT_IMPL_SCOPE_TEMPLATE(C, SCOPE, TMPDEF, TMPSPE)\
    template TMPDEF\
    SCOPE::C TMPSPE::C(){}\
    template TMPDEF\
    SCOPE::C TMPSPE::~C(){}

#define JSON_STATIC(C) \
    private:\
        virtual ~C()=0;

#define JSON_ABSTRACT(C) \
    public:\
        virtual ~C()=0;\
    private:

#define JSON_HUB(C)\
    protected:\
        virtual ~C() = 0;\
    private:

#define JSON_SINGLETON(C)\
    private:\
        static std::shared_ptr<C> _pi;\
    public:\
        static C *pi();\
    protected:\
        C();\
        virtual ~C();\
    protected:\
        static void destruct(C *const &);\
    private:
#define JSON_SINGLETON_IMPL(C)\
    std::shared_ptr<C> C::_pi;\
    C *C::pi(){\
        if(!C::_pi) C::_pi.reset(new C,C::destruct);\
        return C::_pi.get();\
    }\
    void C::destruct(C *const &pc){\
        delete pc;\
    }
#define JSON_SINGLETON_IMPL_SCOPE(C, SCOPE)\
    std::shared_ptr<SCOPE::C> SCOPE::C::_pi;\
    SCOPE::C *SCOPE::C::pi(){\
        if(!C::_pi) C::_pi.reset(new C,C::destruct);\
        return C::_pi.get();\
    }\
    void SCOPE::C::destruct(C *const &pc){\
        delete pc;\
    }
#define JSON_SINGLETON_IMPL_TEMPLATE(C, TMPDEF, TMPSPE)\
    template TMPDEF\
    std::shared_ptr<C TMPSPE> C TMPSPE::_pi;\
    template TMPDEF\
    C TMPSPE *C TMPSPE::pi(){\
        if(!C::_pi) C::_pi.reset(new C,C::destruct);\
        return C::_pi.get();\
    }\
    template TMPDEF\
    void C TMPSPE::destruct(C *const &pc){\
        delete pc;\
    }
#define JSON_SINGLETON_IMPL_SCOPE_TEMPLATE(C, SCOPE, TMPDEF, TMPSPE)\
    template TMPDEF\
    std::shared_ptr<SCOPE::C TMPSPE> SCOPE::C TMPSPE::_pi;\
    template TMPDEF\
    SCOPE::C TMPSPE *SCOPE::C TMPSPE::pi(){\
        if(!C::_pi) C::_pi.reset(new C,C::destruct);\
        return C::_pi.get();\
    }\
    template TMPDEF\
    void SCOPE::C TMPSPE::destruct(C *const &pc){\
        delete pc;\
    }

