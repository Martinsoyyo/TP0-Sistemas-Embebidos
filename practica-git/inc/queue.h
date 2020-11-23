#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

template<class T, uint32_t MAX_ELEMENTS>
class queue {
protected:
    T buffer[MAX_ELEMENTS];
    uint32_t rear;
    uint32_t front;
    uint32_t size;

public:
    queue() : front(1), rear(0), size(0) {};

    bool Add(const T& obj) {
        if (!IsFull()) {
            buffer[front++] = obj;
            front = (front % MAX_ELEMENTS);
            size++;
            return true;
        }
        return false;
    }

    bool Get(T& obj) {
        if (!IsEmpty()) {
            rear = (++rear % MAX_ELEMENTS);
            obj = buffer[rear];
            size--;
            return true;
        }
        return false;
    }

    bool IsEmpty() const { return size == 0; }
    bool IsFull()  const { return size == MAX_ELEMENTS; }
    bool Size()    const { return size; }
};

#endif