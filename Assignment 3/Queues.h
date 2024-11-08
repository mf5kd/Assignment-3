#include <algorithm>
#include <iostream>

namespace CQ {
	template<typename Item_Type>
	class Queue {
	private:
		static const size_t DEFAULT_CAPACITY = 10;
		size_t capacity = DEFAULT_CAPACITY;
		size_t num_items = 0;
		size_t front_index = 0;
		size_t rear_index = 0;
		Item_Type* the_data = new Item_Type[DEFAULT_CAPACITY];
	public:
		void reallocate() {
			size_t new_capacity = 2 * capacity;
			Item_Type* new_data = new Item_Type[new_capacity];
			size_t j = front_index;
			for (size_t i = 0; i < num_items; i++) {
				new_data[i] = the_data[j];
				j = (j + 1) % capacity;
			}
			front_index = 0;
			rear_index = num_items - 1;
			capacity = new_capacity;
			std::swap(the_data, new_data);
			delete[] new_data;
		}
		void push(const Item_Type& item) {
			if (num_items == capacity) {
				reallocate();
			}
			the_data[rear_index] = item;
			rear_index = (rear_index + 1) % capacity;
			num_items++;
		}
		void pop() {
			front_index = (front_index + 1) % capacity;
			num_items--;
		}
		void print() const {
			if (num_items == 0) {
				std::cout << "Queue is empty." << std::endl;
				return;
			}

			size_t j = front_index;
			for (size_t i = 0; i < num_items; ++i) {
				std::cout << the_data[j] << " ";
				j = (j + 1) % capacity;
			}
		}
		Item_Type front() {
			return the_data[front_index];
		}
		Item_Type end() {
			return the_data[capacity - 1];
		}
		void move_to_rear() {
			if (num_items > 0) {  // Only move if there are items in the queue
				Item_Type front_item = front(); // Get the front item
				pop();                           // Remove it from the front
				push(front_item);                // Push it to the rear
			}
			else {
				std::cerr << "Queue is empty: Cannot move front item to rear." << std::endl;
			}
		}
		~Queue() {
			delete[] the_data;
		}
	};
}