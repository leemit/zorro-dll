
#pragma once

template<typename EnumDef, typename UnderlyingType = typename EnumDef::TUnderlyingType>
class CEnum : public EnumDef
{
public:
	typedef UnderlyingType TUnderlyingType;
	typedef CEnum<EnumDef, UnderlyingType> TThis;

	CEnum() {}
	CEnum(TUnderlyingType value) : m_value(value) {}

	explicit operator TUnderlyingType() const { return m_value; }

	friend bool operator == (const TThis& left, const TThis& right) { return left.m_value == right.m_value; }
	friend bool operator != (const TThis& left, const TThis& right) { return left.m_value != right.m_value; }
	friend bool operator <  (const TThis& left, const TThis& right) { return left.m_value <  right.m_value; }
	friend bool operator <= (const TThis& left, const TThis& right) { return left.m_value <= right.m_value; }
	friend bool operator >  (const TThis& left, const TThis& right) { return left.m_value >  right.m_value; }
	friend bool operator >= (const TThis& left, const TThis& right) { return left.m_value >= right.m_value; }

private:
	TUnderlyingType m_value;
};

template<typename UnderlyingType>
struct SEnumBaseDef
{
	typedef UnderlyingType TUnderlyingType;
};

#if ZORRO_CPP >= 11
#define ZORRO_OPEN_ENUM(name) \
typedef enum class name {
#define ZORRO_OPEN_ENUM_TYPE(name, type) \
typedef enum class name : type {
#define ZORRO_CLOSE_ENUM(name) \
} name;
#else
#define ZORRO_OPEN_ENUM(name) \
struct S##name##Def : public SEnumBaseDef<int> { \
	enum EnumType {
#define ZORRO_OPEN_ENUM_TYPE(name, type) \
struct S##name##Def : public SEnumBaseDef<type> { \
	enum EnumType {
#define ZORRO_CLOSE_ENUM(name) \
	}; \
}; \
typedef CEnum<S##name##Def> name;
#endif
