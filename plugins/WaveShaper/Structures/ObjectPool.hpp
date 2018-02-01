#include "Stack.hpp"

#ifndef SPOONIE_OBJECT_POOL_H_INCLUDED
#define SPOONIE_OBJECT_POOL_H_INCLUDED

namespace spoonie
{
template <class T>
class ObjectPool
{
  public:
    template <typename... Args>
    ObjectPool(int numberOfObjects, Args &&... args);

    T *getObject();
    void freeObject(T *object);

    int numberObjectsLeft();

  private:
    spoonie::Stack<T *> objects;
};

template <class T>
template <typename... Args>
ObjectPool<T>::ObjectPool(int numberOfObjects, Args &&... args) : objects(numberOfObjects)
{
    for (int i = 0; i < objects.getSize(); ++i)
    {
        this->objects.push(new T(args...));
    }
}

template <class T>
T *ObjectPool<T>::getObject()
{
    return this->objects.pop();
}

template <class T>
void ObjectPool<T>::freeObject(T *object)
{
    this->objects.push(object);
}

template <class T>
int ObjectPool<T>::numberObjectsLeft()
{
    return this->objects.getCount();
}
}

#endif