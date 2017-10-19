
#pragma once

#if ZORRO_CPP >= 11
#include <type_traits>
#define ZORRO_ENUM_UNDERLYING_TYPE(enumType) typename ::std::underlying_type<enumType>::type
#else
#define ZORRO_ENUM_UNDERLYING_TYPE(enumType) typename enumType::TUnderlyingType
#endif

ZORRO_NAMESPACE_OPEN

template <typename EnumType, typename UnderlyingType = ZORRO_ENUM_UNDERLYING_TYPE(EnumType)>
class CBitfield
{
public:
	typedef CBitfield<EnumType, UnderlyingType> TThis;
	typedef EnumType TEnum;
	typedef UnderlyingType TUnderlyingType;

	CBitfield() : m_value() {}
	~CBitfield() {}

	CBitfield(TEnum value) : m_value( static_cast<TUnderlyingType>( value ) ) {}

	const TThis operator | ( const TThis& other ) const { return TThis( m_value | other.m_value ); }
	const TThis operator & ( const TThis& other ) const { return TThis( m_value & other.m_value ); }
	const TThis operator | ( const TEnum& other ) const { return TThis( m_value | static_cast<TUnderlyingType>( other ) ); }
	const TThis operator & ( const TEnum& other ) const { return TThis( m_value & static_cast<TUnderlyingType>( other ) ); }
	const TThis operator ~ () const                     { return TThis( ~m_value ); }

	const TThis& operator =  ( const TThis& other ) { m_value =  other.m_value; return *this; }
	const TThis& operator |= ( const TThis& other ) { m_value |= other.m_value; return *this; }
	const TThis& operator &= ( const TThis& other ) { m_value &= other.m_value; return *this; }

	const TThis& operator =  ( const TEnum& other ) { m_value =  static_cast<TUnderlyingType>( other ); return *this; }
	const TThis& operator |= ( const TEnum& other ) { m_value |= static_cast<TUnderlyingType>( other ); return *this; }
	const TThis& operator &= ( const TEnum& other ) { m_value &= static_cast<TUnderlyingType>( other ); return *this; }

	operator TUnderlyingType() const { return m_value; }
	operator bool() const { return m_value != 0; }

	const bool operator == ( const TThis& other ) const { return m_value == other.m_value; }
	const bool operator != ( const TThis& other ) const { return m_value != other.m_value; }
	const bool operator <  ( const TThis& other ) const { return m_value <  other.m_value; }
	const bool operator <= ( const TThis& other ) const { return m_value <= other.m_value; }
	const bool operator >  ( const TThis& other ) const { return m_value >  other.m_value; }
	const bool operator >= ( const TThis& other ) const { return m_value >= other.m_value; }

	const bool operator == ( const TEnum& other ) const { return m_value == static_cast<TUnderlyingType>( other ); }
	const bool operator != ( const TEnum& other ) const { return m_value != static_cast<TUnderlyingType>( other ); }
	const bool operator <  ( const TEnum& other ) const { return m_value <  static_cast<TUnderlyingType>( other ); }
	const bool operator <= ( const TEnum& other ) const { return m_value <= static_cast<TUnderlyingType>( other ); }
	const bool operator >  ( const TEnum& other ) const { return m_value >  static_cast<TUnderlyingType>( other ); }
	const bool operator >= ( const TEnum& other ) const { return m_value >= static_cast<TUnderlyingType>( other ); }

private:
	CBitfield(TUnderlyingType value) : m_value( value ) {}

	TUnderlyingType m_value;
};

ZORRO_NAMESPACE_CLOSE

#define ZORRO_BUILD_ENUM_BIT_OPERATORS_WITH_TYPE(enumType, intType) \
	inline intType operator & ( intType left, enumType right )  { return left & static_cast<intType>( right ); } \
	inline intType operator | ( intType left, enumType right )  { return left & static_cast<intType>( right ); } \
	inline intType operator & ( enumType left, intType right )  { return static_cast<intType>( left ) & right; } \
	inline intType operator | ( enumType left, intType right )  { return static_cast<intType>( left ) & right; } \
	inline intType operator & ( enumType left, enumType right ) { return static_cast<intType>( left ) & static_cast<intType>( right ); } \
	inline intType operator | ( enumType left, enumType right ) { return static_cast<intType>( left ) | static_cast<intType>( right ); } \
	inline intType operator ~ ( enumType value )                { return ~static_cast<intType>( value ); } \

#define ZORRO_BUILD_ENUM_COMP_OPERATORS_WITH_TYPE(enumType, intType) \
	inline bool operator <  ( enumType left, intType right ) { return static_cast<intType>( left ) <  right;                         } \
	inline bool operator <  ( intType left, enumType right ) { return left                         <  static_cast<intType>( right ); } \
	inline bool operator <= ( enumType left, intType right ) { return static_cast<intType>( left ) <= right;                         } \
	inline bool operator <= ( intType left, enumType right ) { return left                         <= static_cast<intType>( right ); } \
	inline bool operator >  ( enumType left, intType right ) { return static_cast<intType>( left ) >  right;                         } \
	inline bool operator >  ( intType left, enumType right ) { return left                         >  static_cast<intType>( right ); } \
	inline bool operator >= ( enumType left, intType right ) { return static_cast<intType>( left ) >= right;                         } \
	inline bool operator >= ( intType left, enumType right ) { return left                         >= static_cast<intType>( right ); } \
	inline bool operator == ( enumType left, intType right ) { return static_cast<intType>( left ) == right;                         } \
	inline bool operator == ( intType left, enumType right ) { return left                         == static_cast<intType>( right ); } \
	inline bool operator != ( enumType left, intType right ) { return static_cast<intType>( left ) != right;                         } \
	inline bool operator != ( intType left, enumType right ) { return left                         != static_cast<intType>( right ); } \

#define ZORRO_BUILD_ENUM_BIT_OPERATORS(enumType) \
        ZORRO_BUILD_ENUM_BIT_OPERATORS_WITH_TYPE(enumType, ZORRO_ENUM_UNDERLYING_TYPE(enumType))

#define ZORRO_BUILD_ENUM_COMP_OPERATORS(enumType) \
        ZORRO_BUILD_ENUM_COMP_OPERATORS_WITH_TYPE(enumType, ZORRO_ENUM_UNDERLYING_TYPE(enumType))
