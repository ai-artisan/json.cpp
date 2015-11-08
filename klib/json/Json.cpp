//
// Created by kalo on 2015/11/1.
//

#include "Json.h"

namespace klib {
    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    std::shared_ptr<bool> Json<NT, CT, AC, OC>::_pDefaultBoolean;

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    std::shared_ptr<typename Json<NT, CT, AC, OC>::Number> Json<NT, CT, AC, OC>::_pDefaultNumber;

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    std::shared_ptr<typename Json<NT, CT, AC, OC>::String> Json<NT, CT, AC, OC>::_pDefaultString;

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    std::shared_ptr<typename Json<NT, CT, AC, OC>::Array> Json<NT, CT, AC, OC>::_pDefaultArray;

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    std::shared_ptr<typename Json<NT, CT, AC, OC>::Object> Json<NT, CT, AC, OC>::_pDefaultObject;

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC> Json<NT, CT, AC, OC>::parse(const String &s) {
        typename String::const_iterator iNow = s.begin();
        JsonCore *pjc = JCoreFactory::pi()->byParsing(iNow, s.end());
        if (!pjc) return Json();
        if (iNow != s.end()) {
            JsonCore::destruct(pjc);
            return Json();
        }
        return Json(pjc);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    bool Json<NT, CT, AC, OC>::isNull() const {
        return _pCore->refCategory() == JC_NULL;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    bool Json<NT, CT, AC, OC>::isBoolean() const {
        return _pCore->refCategory() == JC_BOOLEAN;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    bool Json<NT, CT, AC, OC>::isNumber() const {
        return _pCore->refCategory() == JC_NUMBER;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    bool Json<NT, CT, AC, OC>::isString() const {
        return _pCore->refCategory() == JC_STRING;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    bool Json<NT, CT, AC, OC>::isArray() const {
        return _pCore->refCategory() == JC_ARRAY;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    bool Json<NT, CT, AC, OC>::isObject() const {
        return _pCore->refCategory() == JC_OBJECT;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    bool &Json<NT, CT, AC, OC>::boolean() const {
        if (_pCore->category == JC_BOOLEAN) return *_pCore->value.pBoolean;
        _pDefaultBoolean.reset(new bool);
        return *_pDefaultBoolean;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    typename Json<NT, CT, AC, OC>::Number &Json<NT, CT, AC, OC>::number() const {
        if (_pCore->category == JC_NUMBER) return *_pCore->value.pNumber;
        _pDefaultNumber.reset(new Number);
        return *_pDefaultNumber;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    typename Json<NT, CT, AC, OC>::String &Json<NT, CT, AC, OC>::string() const {
        if (_pCore->category == JC_STRING) return *_pCore->value.pString;
        _pDefaultString.reset(new String);
        return *_pDefaultString;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    typename Json<NT, CT, AC, OC>::Array &Json<NT, CT, AC, OC>::array() const {
        if (_pCore->category == JC_ARRAY) return *_pCore->value.pArray;
        _pDefaultArray.reset(new Array);
        return *_pDefaultArray;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    typename Json<NT, CT, AC, OC>::Object &Json<NT, CT, AC, OC>::object() const {
        if (_pCore->category == JC_OBJECT) return *_pCore->value.pObject;
        _pDefaultObject.reset(new Object);
        return *_pDefaultObject;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json() : _pCore(
            JCNullFactory::pi()->byEntity(),
            JsonCore::destruct
    ) {
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(Json &&j) {
        _move(std::move(j));
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(const Json &j) {
        _copy(j);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(Json &&j) {
        _move(std::move(j));
        return *this;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(const Json &j) {
        _copy(j);
        return *this;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    Json<NT, CT, AC, OC>::Json(T &&t) {
        _auto(std::forward<T>(t), (typename std::decay<T>::type *const &) NULL);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    Json<NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(T &&t) {
        _auto(std::forward<T>(t), (typename std::decay<T>::type *const &) NULL);
        return *this;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    void Json<NT, CT, AC, OC>::swap(Json &j) {
        _pCore.swap(j._pCore);
    };

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::~Json() {
        _pCore.reset();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(int &&i) {
        _auto(std::move(i), (Number *const &) NULL);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(const int &i) {
        _auto(i, (Number *const &) NULL);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(int &&i) {
        _auto(i, (Number *const &) NULL);
        return *this;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(const int &i) {
        _auto(i, (Number *const &) NULL);
        return *this;
    }


    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    void Json<NT, CT, AC, OC>::_move(Json &&j) {
        if (_pCore != j._pCore) {
            _pCore.reset(
                    JCNullFactory::pi()->byEntity(),
                    JsonCore::destruct
            );
            _pCore.swap(j._pCore);
//            std::cout << "move" << std::endl;
        } else {
//            std::cout << "self move" << std::endl;
        }
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    void Json<NT, CT, AC, OC>::_copy(const Json &j) {
        if (_pCore != j._pCore) {
            JsonCore *pjc;
            switch (j._pCore->category) {
                case JC_BOOLEAN:
                    pjc = JCBooleanFactory::pi()->byEntity(*j._pCore->value.pBoolean);
                    break;
                case JC_NUMBER:
                    pjc = JCNumberFactory::pi()->byEntity(*j._pCore->value.pNumber);
                    break;
                case JC_STRING:
                    pjc = JCStringFactory::pi()->byEntity(*j._pCore->value.pString);
                    break;
                case JC_ARRAY:
                    pjc = JCArrayFactory::pi()->byEntity(*j._pCore->value.pArray);
                    break;
                case JC_OBJECT:
                    pjc = JCObjectFactory::pi()->byEntity(*j._pCore->value.pObject);
                    break;
                default:
                    pjc = JCNullFactory::pi()->byEntity();
            }
            _pCore.reset(pjc, JsonCore::destruct);
//            std::cout << "copy" << std::endl;
        } else {
//            std::cout << "self copy" << std::endl;
        }
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    void Json<NT, CT, AC, OC>::_auto(T &&t, bool *const &) {
        _pCore.reset(
                JCBooleanFactory::pi()->byEntity(std::forward<T>(t)),
                JsonCore::destruct
        );
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    void Json<NT, CT, AC, OC>::_auto(T &&t, Number *const &) {
        _pCore.reset(
                JCNumberFactory::pi()->byEntity(std::forward<T>(t)),
                JsonCore::destruct
        );
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    void Json<NT, CT, AC, OC>::_auto(T &&t, String *const &) {
        _pCore.reset(
                JCStringFactory::pi()->byEntity(std::forward<T>(t)),
                JsonCore::destruct
        );
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    void Json<NT, CT, AC, OC>::_auto(T &&t, const Char **const &) {
        _pCore.reset(
                JCStringFactory::pi()->byEntity(String(std::forward<T>(t))),
                JsonCore::destruct
        );
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    void Json<NT, CT, AC, OC>::_auto(T &&t, Array *const &) {
        _pCore.reset(
                JCArrayFactory::pi()->byEntity(std::forward<T>(t)),
                JsonCore::destruct
        );
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    void Json<NT, CT, AC, OC>::_auto(T &&t, Object *const &) {
        _pCore.reset(
                JCObjectFactory::pi()->byEntity(std::forward<T>(t)),
                JsonCore::destruct
        );
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    void Json<NT, CT, AC, OC>::_auto(Json &&j, Json *const &) {
        _move(std::move(j));
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    void Json<NT, CT, AC, OC>::_auto(const Json &j, Json *const &) {
        _copy(j);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(JsonCore *pjc) : _pCore(pjc, JsonCore::destruct) { }
}