/**
 * @file Uncopyable.h
 * @brief 对象不可拷贝。
 * @author nvngliu@gmail.com
 * @version 1.0
 * @date 2014-01-09
 */

#ifndef __UNCOPYABLE_H__
#define __UNCOPYABLE_H__

/**
 * @brief 对象不可拷贝。
 */
class Uncopyable {
protected :
        Uncopyable(void) {}
        ~Uncopyable(void) {}

private :
        Uncopyable(Uncopyable&);
        const Uncopyable& operator=(const Uncopyable&);
};

#endif // __UNCOPYABLE_H__
