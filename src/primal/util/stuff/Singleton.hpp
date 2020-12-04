#pragma once

//Singleton pattern by Scott Meyers.
template <typename T> class Singleton {

protected:

    Singleton               () {}
    ~Singleton              () {}

    Singleton               (const Singleton&) = delete;
    Singleton& operator=    (const Singleton&) = delete;

    Singleton               (Singleton&&) = delete;
    Singleton& operator=    (Singleton&&) = delete;

public:

    /**
     *
     * @point - Create stack-based instance.
     *
     **/

    static T& GetInstance () {

        static T instance {};

        return instance;
    }

};