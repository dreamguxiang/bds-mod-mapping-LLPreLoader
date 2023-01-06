/* Borrowed from an implementation by @MCMrARM: https://gist.githubusercontent.com/MCMrARM/180c743f7882f40ad1b993bdc78dca28/raw/3236a6637b0070789d0cb4543200675633bc6b81/Memory.h */
#pragma once

#include <atomic>
#include <utility>

template<typename T>
struct SharedCounter {
    /* volatile ? */ T* value;
    std::atomic<int> shared, weak;

    SharedCounter(T* value) : value(value) {}

    void addSharedRef() { ++shared; }

    void addWeakRef() { --shared; }

    bool releaseSharedRef() {
        if (--shared == 0) {
            if (value != nullptr) {
                T* oldValue = value;
                value = nullptr;
                delete oldValue;
            }
            return (weak == 0);
        }
        return false;
    }

    bool releaseWeakRef() {
        return (--weak == 0 && value);
    }
};

template<typename T>
class WeakPtr {
public:
    SharedCounter<T>* counter = nullptr;

    WeakPtr(T* val = nullptr) {
        if (val) {
            counter = new SharedCounter<T>(val);
            counter->addWeakRef();
        }
    }

    WeakPtr(WeakPtr&& ptr) {
        counter = std::move(ptr.counter);
        ptr.counter = nullptr;
    }

    WeakPtr& operator=(WeakPtr const& ptr) {
        reset();
        this->counter = ptr.counter;
        if (counter)
            counter->addWeakRef();
        return *this;
    }

    WeakPtr& operator=(WeakPtr&& ptr) {
        counter = std::move(ptr.counter);
        ptr.counter = nullptr;
        return *this;
    }

    void reset() {
        if (counter && counter->releaseWeakRef())
            delete counter;
        counter = nullptr;
    }

    ~WeakPtr() {
        reset();
    };

    template <typename... Args>
    static WeakPtr<T> make(Args&&... args) {
        return WeakPtr<T>(new T(std::forward(args...)));
    }

    T& operator*() {
        return *counter->value;
    }

    T* operator->() {
        return counter->value;
    }

    T* get() {
        if (!counter)
            return nullptr;
        return counter->value;
    }

    T const* get() const {
        if (!counter)
            return nullptr;
        return counter->value;
    }
};

template<typename T>
class SharedPtr {
public:
    SharedCounter<T>* counter = nullptr;

    SharedPtr(T* val = nullptr) {
        if (val) {
            counter = new SharedCounter<T>(val);
            counter->addSharedRef();
        }
    }

    SharedPtr(SharedPtr const& a) : counter(a.counter) {
        if (counter)
            counter->addSharedRef();
    }

    void reset() {
        if (counter && counter->releaseSharedRef())
            delete counter;
        counter = nullptr;
    }

    SharedPtr& operator=(SharedPtr const& ptr) {
        reset();
        this->counter = ptr.counter;
        if (counter)
            counter->addSharedRef();
        return *this;
    }

    ~SharedPtr() {
        reset();
    }

    template <typename... Args>
    static SharedPtr<T> make(Args&&... args) {
        return SharedPtr<T>(new T(std::forward(args...)));
    }

    T& operator*() {
        return *counter->value;
    }

    T* operator->() {
        return counter->value;
    }

    T* get() {
        if (!counter)
            return nullptr;
        return counter->value;
    }
};
