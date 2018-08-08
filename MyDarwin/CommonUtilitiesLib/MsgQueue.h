/*====================================================================
 * 
 * @file		MsgQueue.h
 * @author		Deng Yi <kofera_deng@gmail.com>
 * @date		Mon Nov 10 22:23:34 2014
 * 
 * Copyright (c) 2014 Deng Yi (kofera_deng@gmail.com)
 * 
 * @brief		A Generic Message Queue
 * 
 * 
 *===================================================================*/

#ifndef MSG_QUEUE_H
#define MSG_QUEUE_H

class QueueItem
{
public:
    QueueItem(int data) { data_ = data; };
    ~QueueItem() {};

private:
    int data_;
};

/*----------------------------------------------------------------------
  |   NPT_GenericQueue
  +---------------------------------------------------------------------*/
class GenericQueue
{
    public:
        // class methods
        static GenericQueue* CreateInstance(int max_items = 0);

        // methods
        virtual ~GenericQueue() {}
        virtual int enqueue(QueueItem* item, int timeout = -1) = 0; 
        virtual int dequeue(QueueItem*& item, int timeout = -1) = 0;
        virtual int peek(QueueItem*& item, int timeout = -1) = 0;
        virtual bool isFull() = 0;
        virtual bool isEmpty() = 0;
        //    virtual int queueStatus(QueueItem*& item, int timeout = -1) = 0;
        virtual int queueStatus() = 0;
    protected:
        // methods
        GenericQueue() {}
};

/*----------------------------------------------------------------------
  |   NPT_Queue
  +---------------------------------------------------------------------*/
template <class T>
class MsgQueue
{
    public:
        // methods
        MsgQueue(unsigned int max_items = 0) :
            m_delegate(GenericQueue::CreateInstance(max_items)) {}
        virtual ~MsgQueue<T>() { delete m_delegate; }

        virtual int enqueue(T* item, int timeout = 0)
        {
            return m_delegate->enqueue(reinterpret_cast<QueueItem*>(item), timeout);
        }

        virtual int dequeue(T*& item, int timeout = 0)
        {
            return m_delegate->dequeue(reinterpret_cast<QueueItem*&>(item), timeout);
        }

        virtual int peek(T*& item, int timeout = 0)
        {
            return m_delegate->peek(reinterpret_cast<QueueItem*&>(item), timeout);
        }

        virtual int queueStatus()
        {
            return m_delegate->queueStatus();
        }

        virtual bool isFull()
        {
            return m_delegate->isFull();
        }

        virtual bool isEmpty()
        {
            return m_delegate->isEmpty();
        }
#if 0
        virtual int queueStatus(T*& item, int timeout = 0)
        {
            return m_delegate->queueStatus(reinterpret_cast<QueueItem*&>(item), timeout);
        }
#endif


    protected:
        // members
        GenericQueue* m_delegate;
};

#endif // MSG_QUEUE_H
