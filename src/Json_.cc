#include "Json_.h"

namespace json {
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
    Json <NT, CT, AC, OC> Json<NT, CT, AC, OC>::parse(const String &s) {
        typename String::const_iterator iNow = s.begin();
        _JsonCore *pjc = _JCoreFactory::pi()->byParsing(iNow, s.end());
        if (iNow != s.end()) {
            if (pjc) _JsonCore::destruct(pjc);
            return Json();
        }
        return Json(std::move(pjc));
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    typename Json<NT, CT, AC, OC>::String Json<NT, CT, AC, OC>::stringify(const Json &j, const short &indent, const short &depth) {
        return json::Trivial::pjc2str<Json>(j._pCore.get(), indent, depth);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::isNull() const {
        return _pCore->category == json::JC_NULL;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::isBoolean() const {
        return _pCore->category == json::JC_BOOLEAN;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::isNumber() const {
        return _pCore->category == json::JC_NUMBER;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::isString() const {
        return _pCore->category == json::JC_STRING;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::isArray() const {
        return _pCore->category == json::JC_ARRAY;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::isObject() const {
        return _pCore->category == json::JC_OBJECT;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::is_null() const {
        return isNull();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::is_boolean() const {
        return isBoolean();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::is_number() const {
        return isNumber();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::is_string() const {
        return isString();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::is_array() const {
        return isArray();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool Json<NT, CT, AC, OC>::is_object() const {
        return isObject();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline nullptr_t &Json<NT, CT, AC, OC>::asNull() const {
        if (_pCore->category == json::JC_NULL) return *_pCore->value.pNull;
        _pDefaultNull.reset(new nullptr_t);
        return *_pDefaultNull;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool &Json<NT, CT, AC, OC>::asBoolean() const {
        if (_pCore->category == json::JC_BOOLEAN) return *_pCore->value.pBoolean;
        _pDefaultBoolean.reset(new bool);
        return *_pDefaultBoolean;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::Number &Json<NT, CT, AC, OC>::asNumber() const {
        if (_pCore->category == json::JC_NUMBER) return *_pCore->value.pNumber;
        _pDefaultNumber.reset(new Number);
        return *_pDefaultNumber;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::String &Json<NT, CT, AC, OC>::asString() const {
        if (_pCore->category == json::JC_STRING) return *_pCore->value.pString;
        _pDefaultString.reset(new String);
        return *_pDefaultString;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::Array &Json<NT, CT, AC, OC>::asArray() const {
        if (_pCore->category == json::JC_ARRAY) return *_pCore->value.pArray;
        _pDefaultArray.reset(new Array);
        return *_pDefaultArray;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::Object &Json<NT, CT, AC, OC>::asObject() const {
        if (_pCore->category == json::JC_OBJECT) return *_pCore->value.pObject;
        _pDefaultObject.reset(new Object);
        return *_pDefaultObject;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline nullptr_t &Json<NT, CT, AC, OC>::as_null() const {
        return asNull();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline bool &Json<NT, CT, AC, OC>::as_boolean() const {
        return asBoolean();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::Number &Json<NT, CT, AC, OC>::as_number() const {
        return asNumber();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::String &Json<NT, CT, AC, OC>::as_string() const {
        return asString();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::Array &Json<NT, CT, AC, OC>::as_array() const {
        return asArray();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    inline typename Json<NT, CT, AC, OC>::Object &Json<NT, CT, AC, OC>::as_object() const {
        return asObject();
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json() : _pCore(
            _JCNullFactory::pi()->byEntity(),
            _JsonCore::destruct
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
    Json <NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(Json &&j) {
        _move(std::move(j));
        return *this;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json <NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(const Json &j) {
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
        _auto(std::forward<T>(t), (typename std::decay<T>::type *const &) nullptr);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    template<typename T>
    Json <NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(T &&t) {
        _auto(std::forward<T>(t), (typename std::decay<T>::type *const &) nullptr);
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
        _auto(std::move(i), (Number *const &) nullptr);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(const int &i) {
        _auto(i, (Number *const &) nullptr);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json <NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(int &&i) {
        _auto(i, (Number *const &) nullptr);
        return *this;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json <NT, CT, AC, OC> &Json<NT, CT, AC, OC>::operator=(const int &i) {
        _auto(i, (Number *const &) nullptr);
        return *this;
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(std::initializer_list<Json> &&il) {
        _auto(Array(std::move(il)), (Array *const &) nullptr);
    }

    template<
            typename NT,
            typename CT,
            template<typename...> class AC,
            template<typename, typename...> class OC
    >
    Json<NT, CT, AC, OC>::Json(const std::initializer_list<Json> &il) {
        _auto(Array(il), (Array *const &) nullptr);
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
                    _JCNullFactory::pi()->byEntity(),
                    _JsonCore::destruct
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
            _JsonCore *pjc;
            switch (j._pCore->category) {
                case json::JC_BOOLEAN:
                    pjc = _JCBooleanFactory::pi()->byEntity(*j._pCore->value.pBoolean);
                    break;
                case json::JC_NUMBER:
                    pjc = _JCNumberFactory::pi()->byEntity(*j._pCore->value.pNumber);
                    break;
                case json::JC_STRING:
                    pjc = _JCStringFactory::pi()->byEntity(*j._pCore->value.pString);
                    break;
                case json::JC_ARRAY:
                    pjc = _JCArrayFactory::pi()->byEntity(*j._pCore->value.pArray);
                    break;
                case json::JC_OBJECT:
                    pjc = _JCObjectFactory::pi()->byEntity(*j._pCore->value.pObject);
                    break;
                default:
                    pjc = _JCNullFactory::pi()->byEntity();
            }
            _pCore.reset(pjc, _JsonCore::destruct);
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
    void Json<NT, CT, AC, OC>::_auto(T &&t, nullptr_t *const &) {
        _pCore.reset(
                _JCNullFactory::pi()->byEntity(),
                _JsonCore::destruct
        );
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
                _JCBooleanFactory::pi()->byEntity(std::forward<T>(t)),
                _JsonCore::destruct
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
                _JCNumberFactory::pi()->byEntity(std::forward<T>(t)),
                _JsonCore::destruct
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
                _JCStringFactory::pi()->byEntity(std::forward<T>(t)),
                _JsonCore::destruct
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
                _JCStringFactory::pi()->byEntity(String(std::forward<T>(t))),
                _JsonCore::destruct
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
                _JCArrayFactory::pi()->byEntity(std::forward<T>(t)),
                _JsonCore::destruct
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
                _JCObjectFactory::pi()->byEntity(std::forward<T>(t)),
                _JsonCore::destruct
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
    Json<NT, CT, AC, OC>::Json(_JsonCore *&&pjc) : _pCore(std::move(pjc), _JsonCore::destruct) {}
}