﻿#ifndef Base_RunnableAdapter_INCLUDED
#define Base_RunnableAdapter_INCLUDED

#include "Base/Runnable.h"


namespace Base {


template <class C>
class RunnableAdapter: public Runnable
    /// This adapter simplifies using ordinary methods as
    /// targets for threads.
    /// Usage:
    ///    RunnableAdapter<MyClass> ra(myObject, &MyObject::doSomething));
    ///    Thread thr;
    ///    thr.Start(ra);
    ///
    /// For using a freestanding or static member function as a thread
    /// target, please see the ThreadTarget class.
{
public:
    typedef void (C::*Callback)();
    
    RunnableAdapter(C& object, Callback method): _pObject(&object), _method(method)
    {
    }
    
    RunnableAdapter(const RunnableAdapter& ra): _pObject(ra._pObject), _method(ra._method)
    {
    }

    ~RunnableAdapter()
    {
    }

    RunnableAdapter& operator = (const RunnableAdapter& ra)
    {
        _pObject = ra._pObject;
        _method  = ra._method;
        return *this;
    }

    void run()
    {
        (_pObject->*_method)();
    }
    
private:
    RunnableAdapter();

    C*       _pObject;
    Callback _method;
};


} // namespace Base


#endif // Base_RunnableAdapter_INCLUDED
