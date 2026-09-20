#include <iostream>
#include <functional>

namespace stl
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr& operator=(auto_ptr& ap)
		{
			if (_ptr != ap._ptr)
			{
				delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~auto_ptr()
		{
			delete _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr) noexcept
			:_ptr(ptr)
		{}

		unique_ptr(const unique_ptr& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr& up) = delete;

		unique_ptr(unique_ptr&& up)
			:_ptr(up._ptr)
		{
			up._ptr = nullptr;
		}

		unique_ptr<T>& operator=(unique_ptr&& up)
		{
			if (_ptr != up._ptr)
			{
				delete _ptr;

				_ptr = up._ptr;
				up._ptr = nullptr;
			}
			
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~unique_ptr()
		{
			delete _ptr;
		}

	private:
		T* _ptr;
	};


	struct Date
	{
		int _year;
		int _month;
		int _day;
		Date(int year = 1, int month = 1, int day = 1)
			:_year(year)
			, _month(month)
			, _day(day)
		{}
		~Date()
		{
			std::cout << "~Date()" << std::endl;
		}
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{
			std::cout << "shared_ptr(const T* ptr)" << std::endl;
		}

		template<class D>
		shared_ptr(T* ptr,D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			,_del(del)
		{
			std::cout << "shared_ptr(T* ptr = nullptr,D del)" << std::endl;
		}

		shared_ptr(const shared_ptr& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			,_del(sp._del)
		{
			++(*_pcount);
			std::cout << "shared_ptr(const shared_ptr & sp)" << std::endl;
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				std::cout << "shared_ptr<T>& operator=(const shared_ptr<T>& sp)" << std::endl;

				if (--(*_pcount) == 0)
				{
					_del(_ptr);
					delete _pcount;
				}

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
				_del = sp._del;
			}

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		
		~shared_ptr()
		{
			std::cout << "~shared_ptr()" << std::endl;
			if (--(*_pcount) == 0)
			{
				_del(_ptr);
				delete _pcount;

				_ptr = nullptr;
				_pcount = nullptr;
			}
		}

	private:
		T* _ptr;
		int* _pcount;
		std::function<void(T*)> _del = [](T* ptr) { delete ptr; };
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr(T* ptr)
			:_ptr(ptr)
		{};


	private:
		T* _ptr;
	};

	void test1()
	{
		shared_ptr<Date> sp1(new Date);

		shared_ptr<Date> sp(new Date[10], [](Date* ptr) {delete[] ptr; });
		std::shared_ptr<Date[]> spp(new Date[10], [](Date* ptr) {delete[] ptr; });



		shared_ptr<Date> sp2(sp1);
		shared_ptr<Date> sp3(sp2);

	}
}




int main()
{
	stl::test1();

	return 0;
}