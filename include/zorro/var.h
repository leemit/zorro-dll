
#pragma once

ZORRO_NAMESPACE_OPEN

template <typename VariableDef>
class CVariable : public VariableDef
{
	typedef CVariable<VariableDef> TThis;

	inline CVariable() {}
	inline CVariable(const TThis&) {}
	inline TThis& operator=(const TThis&) {}

public:
	typedef typename VariableDef::TType TType;

	inline operator TType&() const { return VariableDef::get(); }
	inline TType* operator&() const { return &VariableDef::get(); }
	inline TThis& operator=(const TType& value) { VariableDef::set(value); return *this; }
	static TThis& getInstance() { static TThis instance; return instance; }
};

template <typename VariableDef>
class CExpression : public VariableDef
{
	typedef CExpression<VariableDef> TThis;

	inline CExpression() {}
	inline CExpression(const TThis&) {}
	inline TThis& operator=(const TThis&) {}

public:
	typedef typename VariableDef::TType TType;

	inline operator TType() const { return VariableDef::get(); }
	static TThis& getInstance() { static TThis instance; return instance; }
};

template <typename VariableDef>
class CVarPointer : public VariableDef
{
	typedef CVarPointer<VariableDef> TThis;

	inline CVarPointer() {}
	inline CVarPointer(const TThis&) {}
	inline TThis& operator=(const TThis&) {}

public:
	typedef typename VariableDef::TType TType;

	inline TType operator ->() const { return VariableDef::get(); }
	inline operator TType() const { return VariableDef::get(); }
	static TThis& getInstance() { static TThis instance; return instance; }
};

template<typename T>
struct SVariableBaseDef
{
	typedef T TType;
};

ZORRO_NAMESPACE_CLOSE

#define ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
struct S##name##Variable : SVariableBaseDef<type> { \
	inline type& get() const { return (link); } \
	inline void set(const type& value) { (link) = value; } \
};
#define ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
struct S##name##Expression : SVariableBaseDef<type> { \
	inline TType get() const { return (link); } \
};

#ifdef ZORRO_IMPL
#define ZORRO_BUILD_VARIABLE(type, name, link) \
	ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
	CVariable<S##name##Variable>& name = CVariable<S##name##Variable>::getInstance();
#define ZORRO_BUILD_EXPRESSION(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	CExpression<S##name##Expression>& name = CExpression<S##name##Expression>::getInstance();
#define ZORRO_BUILD_VARPOINTER(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	CVarPointer<S##name##Expression>& name = CVarPointer<S##name##Expression>::getInstance();
#else
#define ZORRO_BUILD_VARIABLE(type, name, link) \
	ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
	extern CVariable<S##name##Variable>& name;
#define ZORRO_BUILD_EXPRESSION(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	extern CExpression<S##name##Expression>& name;
#define ZORRO_BUILD_VARPOINTER(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	extern CVarPointer<S##name##Expression>& name;
#endif
