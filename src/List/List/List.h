#pragma once

template <typename T>
class List
{
private:
	template <typename T>
	struct Node
	{
		T m_data;
		Node<T>* m_next;
		Node<T>* m_prev;
	};

	/**
	* The list's front node.
	*
	* @var List<T>::Node<T>
	*/
	Node<T>* m_front_node;

	/**
	* The list's back node.
	*
	* @var List<T>::Node<T>
	*/
	Node<T>* m_back_node;

	/**
	* The list's size;
	*
	* @var int
	*/
	int m_size;

public:
	class iterator
	{
		Node<T>* node;
	public:
		iterator() {}

		iterator(Node<T> *node)
		{
			this->node = node;
		}

		/**
		* Gets the iterator's node.
		*
		* @return List<T>::Node<T>
		*/
		Node<T>* getNode()
		{
			return this->node;
		}

		/**
		* Gets the iterator's node value.
		*
		* @return T
		*/
		T& operator*()
		{
			if (this->node != nullptr)
			{
				return this->node->m_data;
			}

			T *obj = {};
			return *obj;
		}

		/**
		* Pre-increments the iterator.
		*
		* @return List<T>::iterator
		*/
		iterator& operator++()
		{
			if (this->node != nullptr)
			{
				this->node = this->node->m_next;
			}
			return *this;
		}

		/**
		* Post-increments the iterator.
		*
		* @param int
		* @return List<T>::iterator
		*/
		iterator operator++(int)
		{
			iterator tmp(*this);
			operator++();
			return tmp;
		}

		/**
		* Checks two iterators for equity.
		*
		* @param const List<T>::iterator it
		* @return bool
		*/
		bool operator==(const iterator& it)
		{
			if (this->node == nullptr || it.node == nullptr)
			{
				return false;
			}

			return this->node == it.node;
		}

		/**
		* Checks two iterators for inequity.
		*
		* @param const List<T>::iterator it
		* @return bool
		*/
		bool operator!=(const iterator& it)
		{
			if (this->node == nullptr || it.node == nullptr)
			{
				return false;
			}

			return this->node != it.node->m_next;
		}
	};

	List<T>()
	{

	}

	~List<T>()
	{
	}


	/**
	* Adds element to the front of the list.
	*
	* @param const &T value
	* @return void
	*/
	void push_front(const T& value)
	{
		Node<T> *newNode = new Node<T>();
		newNode->m_data = value;
		newNode->m_prev = nullptr;
		newNode->m_next = this->m_front_node;

		if (this->m_front_node != nullptr)
		{
			this->m_front_node->m_prev = newNode;
		}
		this->m_front_node = newNode;


		if (this->m_back_node == nullptr)
		{
			this->m_back_node = m_front_node;
		}

		this->m_size++;
	}

	/**
	* Removes the first element from the list.
	*
	* @return void
	*/
	void pop_front()
	{
		if (this->m_front_node != nullptr)
		{
			Node<T> *tmp = this->m_front_node->m_next;
			delete this->m_front_node;
			this->m_front_node = tmp;
			if (this->m_front_node != nullptr)
			{
				this->m_front_node->m_prev = nullptr;
			}
			this->m_size--;
		}
	}

	/**
	* Adds element to the back of the list.
	*
	* @param const &T value
	* @return void
	*/
	void push_back(const T& value)
	{
		Node<T> *newNode = new Node<T>();
		newNode->m_data = value;
		newNode->m_prev = this->m_back_node;
		newNode->m_next = nullptr;

		if (this->m_back_node != nullptr)
		{
			this->m_back_node->m_next = newNode;
		}
		this->m_back_node = newNode;

		if (this->m_front_node == nullptr)
		{
			this->m_front_node = m_back_node;
		}

		this->m_size++;
	}

	/**
	* Removes the last element from the list.
	*
	* @return void
	*/
	void pop_back()
	{
		if (this->m_back_node != nullptr)
		{
			Node<T> *tmp = this->m_back_node->m_prev;
			delete this->m_back_node;
			this->m_back_node = tmp;
			if (this->m_back_node != nullptr)
			{
				this->m_back_node->m_next = nullptr;
			}

			this->m_size--;
		}
	}

	/**
	* Gets the first element from the list.
	*
	* @return T
	*/
	T& front()
	{
		if (this->m_front_node != nullptr)
		{
			return this->m_front_node->m_data;
		}

		T *obj = {};
		return *obj;
	}

	/**
	* Gets the last element from the list.
	*
	* @return T
	*/
	T& back()
	{
		if (this->m_back_node != nullptr)
		{
			return this->m_back_node->m_data;
		}

		T *obj = {};
		return *obj;
	}

	/**
	* Gets the front list iterator.
	*
	* @return List<T>::iterator
	*/
	iterator begin()
	{
		return iterator(this->m_front_node);
	}

	/**
	* Gets the back list iterator.
	*
	* @return List<T>::iterator
	*/
	iterator end()
	{
		return iterator(this->m_back_node);
	}

	/**
	* Inserts an element at the iterator's position.
	*
	* @param List<T>::iterator it
	* @param T& value
	* @return void
	*/
	void insert(iterator it, const T& value)
	{

	}

	/**
	* Removes an element at the iterator's position.
	*
	* @param List<T>::iterator it
	* @return void
	*/
	void erase(iterator it)
	{
		Node<T> *tmpPrev = it.getNode()->m_prev;
		Node<T> *tmpNext = it.getNode()->m_next;
		delete it.getNode();
		
		tmpPrev->m_next = tmpNext;
		tmpNext->m_prev = tmpPrev;
	}

	/**
	* Gets the list elements count.
	*
	* @return int
	*/
	int size()
	{
		return this->m_size;
	}

	/**
	* Deletes all list elements.
	*
	* @return void
	*/
	void clear()
	{
		if (this->m_front_node != nullptr)
		{
			for (int i = this->m_size; i > 0; i--)
			{
				this->pop_back();
			}
		}
	}

	/**
	* Checks if the list is empty.
	*
	* @return bool
	*/
	bool empty()
	{
		return this->m_size == 0;
	}
};