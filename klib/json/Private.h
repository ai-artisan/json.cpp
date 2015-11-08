//
// Created by kalo on 2015/11/1.
//

#pragma once

#include "public.h"

namespace klib {
    namespace json {
        class Private {
        ABSTRACT(Private)

        protected:
            template<typename...>
            struct Special;

            enum JsonCategory {
                JC_NULL,
                JC_BOOLEAN,
                JC_NUMBER,
                JC_STRING,
                JC_ARRAY,
                JC_OBJECT
            };

            template<typename>
            union JsonValue;

            template<typename>
            class Trivial;

            template<typename>
            class JsonCore;

            class Factory;

            template<typename>
            class JCoreFactory;

            template<typename>
            class JCNullFactory;

            template<typename>
            class JCBooleanFactory;

            template<typename>
            class JCNumberFactory;

            template<typename>
            class JCStringFactory;

            template<typename>
            class JCArrayFactory;

            template<typename>
            class JCObjectFactory;
        };
        DESTRUCTOR_DEFAULT_IMPL(Private)
    }
}
