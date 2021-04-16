#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  T priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.

 */
template <typename T>
struct Queue {
  ElementPtr<T> Head;
  ElementPtr<T> Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.Head = nullptr;
  q.Tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> pBaru = new Element<T>;
  pBaru->data = value;
  pBaru->priority = priority;
  pBaru->next = nullptr;

  ElementPtr<T> pRev = nullptr;
  ElementPtr<T> pHelp = q.Head;

  if (q.Head == nullptr && q.Tail == nullptr){
    q.Head = pBaru;
    q.Tail = pBaru;
  } else {
    while (pBaru->priority <= pHelp->priority){
      if (pHelp->next == nullptr)
        break;
      pRev = pHelp;
      pHelp = pHelp -> next;
    }

    if (pHelp == q.Head && pBaru->priority > pHelp->priority){
      pBaru->next = pHelp;
      q.Head = pBaru;
    } else if (pHelp == q.Tail && pBaru->priority < pHelp->priority){
      pHelp->next = pBaru;
      q.Tail = pBaru;
    } else {
      pRev->next = pBaru;
      pBaru->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> pDel;

  if(q.Head == nullptr && q.Tail == nullptr){
    pDel = nullptr;
  } else if (q.Head->next == nullptr){
    pDel = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
  } else {
    pDel = q.Head;
    q.Head = q.Head->next;
    pDel->next = nullptr;
  }  
}

}  // namespace priority_queue

}  // namespace strukdat
