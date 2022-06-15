#include <iostream>
#include <vector>
using namespace std;

namespace my_Namespace {
	
	class DayofYearSet {
	public:
		static int num;
		int size;

		class DayofYear {
		public:
			int day;
			decltype(day)month;
			DayofYear() {
				
			} 
			DayofYear(int d, int m) {  // Definition of destructor setter getter functions
				setDate(d, m);
				num++;

			}

			void setDate(int d, int m) {
				day = d;
				month = m;
			}
		};

		DayofYear* data;    // DayofYearSet class keeps its elements using a DayofYear * data member

		static int count() {
			return num;
		}

		DayofYearSet(vector<DayofYear> obj) {
			size = obj.size();
			data = new DayofYear[size];
			for (int i = 0; i < size; i++)
				data[i] = obj[i];
		}
		DayofYearSet() {

		}
		DayofYear* getData() {
			return data;
		}

		friend ostream& operator<<(ostream& os, const DayofYearSet& obj);			// declarations of functions
		friend DayofYearSet operator+(const DayofYearSet& obj, const DayofYearSet& obj2);
		friend DayofYearSet operator-(const DayofYearSet& obj, const DayofYearSet& obj2);
		friend DayofYearSet operator!(const DayofYearSet& obj);
		friend DayofYearSet operator^(const DayofYearSet& obj, const DayofYearSet& obj2);
		friend bool operator==(const DayofYearSet& obj, const DayofYearSet& obj2);
		friend bool operator!=(const DayofYearSet& obj, const DayofYearSet& obj2);
		friend void add(DayofYearSet& k, DayofYearSet::DayofYear obj);
		friend void remove(DayofYearSet& k, DayofYearSet::DayofYear obj);
		friend int size(const DayofYearSet k);
		
		DayofYear& operator[](int a) {

			return this->data[a];
		 }
	};

	int DayofYearSet::num=0;

	void add(DayofYearSet& k, DayofYearSet::DayofYear obj) {

		vector< DayofYearSet::DayofYear> deneme;  // I used vectors for convenience in in-function operations.

		for (int i = 0; i < k.size; i++)  // I add all the first object then add the object to be added
			deneme.push_back(k.data[i]);

		deneme.push_back(obj);

		delete k.data;
		k.data = new DayofYearSet::DayofYear[deneme.size()];  // I made an operation on the dynamic array using the information I got from the vector.
		k.size = deneme.size();
		for (int i = 0; i < deneme.size(); i++)
			k.data[i] = deneme[i];
	}

	void remove(DayofYearSet& k, DayofYearSet::DayofYear obj) {

		vector< DayofYearSet::DayofYear> deneme;
		int num=0;

		for (int i = 0; i < k.size; i++) {

			if ((k.data[i].day == obj.day) && (k.data[i].month == obj.month)) {
				num = i;
				break;
			}
			deneme.push_back(k.data[i]);
		}
		for (int i = num + 1; i < k.size; i++) {
			deneme.push_back(k.data[i]);
		}
		delete k.data;
		k.data = new DayofYearSet::DayofYear[deneme.size()];
		k.size = deneme.size()-1;
		for (int i = 0; i < k.size; i++)
			k.data[i] = deneme[i];
	}

	int size( const DayofYearSet k) {

		return k.size;
	}

	ostream& operator<<(ostream& os, const DayofYearSet& obj) {

		os << "First day information in data:" << obj.data[0].day << "\nFirst month information in data : " << obj.data[0].month;
		return os;
	}

	bool operator==(const DayofYearSet& obj, const DayofYearSet& obj2) {

		int counter = 0;

		if (obj.size != obj2.size)
			return false;
		else {
			for (int i = 0; i < obj.size; i++) {
				for (int j = 0; j < obj2.size; j++) {
					if ((obj.data[i].day == obj2.data[j].day) && (obj.data[i].month == obj2.data[j].month))
						counter++;
				}
			}
			if (counter == obj.size)
				return true;
			else
				return false;
		}
	}

	bool operator!=(const DayofYearSet& obj, const DayofYearSet& obj2) {

		int counter = 0;

		if (obj.size != obj2.size)
			return true;
		else {
			for (int i = 0; i < obj.size; i++) {
				for (int j = 0; j < obj2.size; j++) {
					if ((obj.data[i].day == obj2.data[j].day) && (obj.data[i].month == obj2.data[j].month))
						counter++;
				}
			}
			if (counter == obj.size)
				return false;
			else
				return true;
		}
	}

	DayofYearSet operator+(const DayofYearSet& obj,  const DayofYearSet& obj2) {

		int flag = 0;
		DayofYearSet k;
		vector< DayofYearSet::DayofYear> deneme;

		for (int i = 0; i < obj.size; i++)
			deneme.push_back(obj.data[i]);

		for (int i = 0; i < obj2.size; i++) {
			flag = 0;
			for (int j = 0; j < deneme.size(); j++) {

				if ((obj2.data[i].day == deneme[j].day) && (obj2.data[i].month == deneme[j].month)) {
					flag++;
				}	

			}
			if(flag==0)
				deneme.push_back(obj2.data[i]);
		}

		k.data = new DayofYearSet::DayofYear[deneme.size()+1];
		k.size = deneme.size();
		for (int i = 0; i < deneme.size(); i++)
			k.data[i] = deneme[i];
		
		return k;
	}

	DayofYearSet operator-(const DayofYearSet& obj, const DayofYearSet& obj2) {

		int size;
		DayofYearSet k;
		vector< DayofYearSet::DayofYear> deneme;

		if (obj.size < obj2.size)
			size = obj2.size;
		else
			size = obj.size;

		for (int i = 0; i < size; i++) {

			if ((obj.data[i].day != obj2.data[i].day) || (obj.data[i].month != obj2.data[i].month)) {

				deneme.push_back(obj.data[i]);
			}
		}
		k.data = new DayofYearSet::DayofYear[deneme.size()+1];

		for (int i = 0; i < deneme.size(); i++) {
			k.data[i] = deneme[i];

		}
		k.size = deneme.size();

		return k;
	}

	DayofYearSet operator!(const DayofYearSet& obj) {

		int flag = 0;
		DayofYearSet k;
		vector< DayofYearSet::DayofYear> deneme;

		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 30; j++) {
				flag = 0;
				for (int k = 0; k < obj.size; k++) {
					if (obj.data[k].month == i && obj.data[k].day == j) {
						flag++;
					}
				}
				if (flag == 0) {
					DayofYearSet::DayofYear obj(j, i);
					deneme.push_back(obj);
				}
			}
		}

		k.data = new DayofYearSet::DayofYear[deneme.size()];
		k.size = deneme.size();

		for (int i = 0; i < deneme.size(); i++)
			k.data[i] = deneme[i];
		return k;
	}

	DayofYearSet operator^(const DayofYearSet& obj, const DayofYearSet& obj2) {

		DayofYearSet k;
		vector< DayofYearSet::DayofYear> deneme;

		for (int i = 0; i < obj.size; i++) {
			for (int j = 0; j < obj2.size; j++) {

				if (obj.data[i].month == obj2.data[j].month && obj.data[i].day == obj2.data[j].day) {

					deneme.push_back(obj.data[i]);
				}
			}
		}
		k.data = new DayofYearSet::DayofYear[deneme.size()];
		k.size = deneme.size();

		for (int i = 0; i < deneme.size(); i++)
			k.data[i] = deneme[i];
		return k;
	}
}

using namespace my_Namespace;