#pragma once

enum class ArgFlag
{
    UNKNOWN = 0x00,
    HELP = 1,// 1               // 0000 0001
    SHOW = 2,// 1 << 1          // 0000 0010
    SETS = 4,// 1 << 2          // 0000 0100
    REPS = 8,// 1 << 3          // 0000 1000
    GET_TOKEN = 16,// 1 << 4    // 0001 0000

    ALL = HELP | SHOW | SETS | REPS | GET_TOKEN,        // or ANY?
    INVALID_MAX_VALUE = 0x32
};



// Operators for above

template<class T> inline T operator~ (T a) { return (T)~(int)a; }
template<class T> inline T operator| (T a, T b) { return (T)((int)a | (int)b); }
template<class T> inline T operator& (T a, T b) { return (T)((int)a & (int)b); }
template<class T> inline T operator^ (T a, T b) { return (T)((int)a ^ (int)b); }
template<class T> inline T& operator|= (T& a, T b) { return (T&)((int&)a |= (int)b); }
template<class T> inline T& operator&= (T& a, T b) { return (T&)((int&)a &= (int)b); }
template<class T> inline T& operator^= (T& a, T b) { return (T&)((int&)a ^= (int)b); }

template <class ENUM_FLAG>
class Flags {
public:
    Flags() : m_Flags(0) {}
    Flags(ENUM_FLAG flags) : m_Flags(static_cast<unsigned>(flags)) {}

    void set(ENUM_FLAG flag) { m_Flags |= static_cast<unsigned>(flag); }
    void reset(ENUM_FLAG flag) { m_Flags &= ~static_cast<unsigned>(flag); }
    void reset() { m_Flags = 0; }
    bool test(ENUM_FLAG flag) { return m_Flags & static_cast<unsigned>(flag); }

    ENUM_FLAG GetFlags() const { return static_cast<ENUM_FLAG>(m_Flags); }
    unsigned GetRawFlags() const { return m_Flags; }

private:
    unsigned m_Flags;
};

