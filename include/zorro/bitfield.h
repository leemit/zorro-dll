
#pragma once

template <typename EnumType, typename UnderlyingType>
class CBitfield
{
public:
	typedef CBitfield<EnumType, UnderlyingType> TThis;
	typedef EnumType TEnum;
	typedef UnderlyingType TInt;

	CBitfield() : m_value() {}
	~CBitfield() {}

	CBitfield(TEnum value) : m_value( static_cast<TInt>( value ) ) {}

	const TThis operator | ( const TThis& other ) const { return TThis( m_value | other.m_value ); }
	const TThis operator & ( const TThis& other ) const { return TThis( m_value & other.m_value ); }
	const TThis operator | ( const TEnum& other ) const { return TThis( m_value | static_cast<TInt>( other ) ); }
	const TThis operator & ( const TEnum& other ) const { return TThis( m_value & static_cast<TInt>( other ) ); }
	const TThis operator ~ () const                     { return TThis( ~m_value ); }

	const TThis& operator =  ( const TThis& other ) { m_value =  other.m_value; return *this; }
	const TThis& operator |= ( const TThis& other ) { m_value |= other.m_value; return *this; }
	const TThis& operator &= ( const TThis& other ) { m_value &= other.m_value; return *this; }

	const TThis& operator =  ( const TEnum& other ) { m_value =  static_cast<TInt>( other ); return *this; }
	const TThis& operator |= ( const TEnum& other ) { m_value |= static_cast<TInt>( other ); return *this; }
	const TThis& operator &= ( const TEnum& other ) { m_value &= static_cast<TInt>( other ); return *this; }

	operator TInt() const { return m_value; }
	operator bool() const { return m_value != 0; }

	const bool operator == ( const TThis& other ) const { return m_value == other.m_value; }
	const bool operator != ( const TThis& other ) const { return m_value != other.m_value; }
	const bool operator <  ( const TThis& other ) const { return m_value <  other.m_value; }
	const bool operator <= ( const TThis& other ) const { return m_value <= other.m_value; }
	const bool operator >  ( const TThis& other ) const { return m_value >  other.m_value; }
	const bool operator >= ( const TThis& other ) const { return m_value >= other.m_value; }

	const bool operator == ( const TEnum& other ) const { return m_value == static_cast<TInt>( other ); }
	const bool operator != ( const TEnum& other ) const { return m_value != static_cast<TInt>( other ); }
	const bool operator <  ( const TEnum& other ) const { return m_value <  static_cast<TInt>( other ); }
	const bool operator <= ( const TEnum& other ) const { return m_value <= static_cast<TInt>( other ); }
	const bool operator >  ( const TEnum& other ) const { return m_value >  static_cast<TInt>( other ); }
	const bool operator >= ( const TEnum& other ) const { return m_value >= static_cast<TInt>( other ); }

private:
	CBitfield(TInt value) : m_value( value ) {}

	TInt m_value;
};

#define ZORRO_BUILD_ENUM_BIT_OPERATORS_WITH_TYPE(enumType, intType) \
	inline intType operator & ( intType left, enumType right )  { return left & static_cast<intType>( right ); } \
	inline intType operator | ( intType left, enumType right )  { return left & static_cast<intType>( right ); } \
	inline intType operator & ( enumType left, intType right )  { return static_cast<intType>( left ) & right; } \
	inline intType operator | ( enumType left, intType right )  { return static_cast<intType>( left ) & right; } \
	inline intType operator & ( enumType left, enumType right ) { return static_cast<intType>( left ) & static_cast<intType>( right ); } \
	inline intType operator | ( enumType left, enumType right ) { return static_cast<intType>( left ) | static_cast<intType>( right ); } \
	inline intType operator ~ ( enumType value )                { return ~static_cast<intType>( value ); } \

#define ZORRO_BUILD_ENUM_BIT_OPERATORS(enumType) \
        ZORRO_BUILD_ENUM_BIT_OPERATORS_WITH_TYPE(enumType, int)
