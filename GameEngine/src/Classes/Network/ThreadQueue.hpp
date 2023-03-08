/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ThreadQueue
*/

#ifndef THREADQUEUE_HPP_
    #define THREADQUEUE_HPP_

    #include "Network/Utils.hpp"

template<typename T>
class SafeThreadQueue {

    public:
        const T &getFront()
        {
            std::scoped_lock lock(_mutexQueue);
            return _queue.front();
        }

        const T &getBack()
        {
            std::scoped_lock lock(_mutexQueue);
            return _queue.back();
        }

        T pop_front()
        {
            std::scoped_lock lock(_mutexQueue);
            T t = std::move(_queue.front());
            if (!_queue.empty())
                _queue.pop_front();
            return t;
        }

        T pop_back()
        {
            std::scoped_lock lock(_mutexQueue);
            T t = std::move(_queue.back());
            _queue.pop_back();

            return t;
        }

        void push_back(const T& item)
        {
            std::scoped_lock lock(_mutexQueue);
            _queue.emplace_back(std::move(item));

            std::unique_lock<std::mutex> locked(_mutexBlock);
            _block.notify_one();
        }

        void push_front(const T& item)
        {
            std::scoped_lock lock(_mutexQueue);
            _queue.emplace_front(std::move(item));

            std::unique_lock<std::mutex> locked(_mutexBlock);
            _block.notify_one();
        }

        bool isEmpty()
        {
            std::scoped_lock lock(_mutexQueue);
            return _queue.empty();
        }

        size_t count()
        {
            std::scoped_lock lock(_mutexQueue);
            return _queue.size();
        }

        void clear()
        {
            std::scoped_lock lock(_mutexQueue);
            _queue.clear();
        }

        void wait()
        {
            while (isEmpty()) {
                std::unique_lock<std::mutex> locked(_mutexBlock);
                _block.wait(locked);
            }
        }

    protected:
		std::deque<T> _queue;
		std::condition_variable _block;
		std::mutex _mutexQueue;
		std::mutex _mutexBlock;
};

// A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.
// When a scoped_lock object is created, it attempts to take ownership of the mutexes it is given. When control leaves the scope in which the scoped_lock object was created, the scoped_lock is destructed and the mutexes are released.

#endif /* !THREADQUEUE_HPP_ */