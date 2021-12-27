#include <iostream>
#include <string>


using namespace std;

class LibMat 
{
public:
	LibMat() { cout << "LibMat::LibMat() default constructor\n"; }

	virtual ~LibMat() { cout << "LibMat::~LibMat() destructor\n"; }
	virtual void print() const { cout << "LibMat::print() -- I am a LibMat object\n"; }

private:

};

class Mangiaze :public LibMat
{
public:
	Mangiaze(const string &title, const string &date) :_title(title), _date(date)
	{
		cout << "Mangiaze::Mangiaze(" << _title;
		cout << ", " << _date << ") constructor\n";
	}
	~Mangiaze() { cout << "Mangiaze::~Mangiaze()destructor\n";}
	virtual void print() const
	{
		cout << "Mangiaze::print() -- I am a Mangiaze object\n";
		cout << "My title is: " << _title << endl;
		cout << "The date is: " << _date << endl;
	}
protected:
	string _title;
	string _date;
};

class Book :public LibMat//基类
{
public:
	Book(const string &title, const string &author) :_title(title), _author(author)
	{
		cout << "Book::Book(" << _title;
		cout << ", " << _author << ") constructor\n";
	}
	~Book() { cout << "Book::~Book()destructor\n"; }
	virtual void print() const//重写父类方法
	{
		cout << "Book::print() -- I am a Book object\n";
		cout << "My title is: " << _title << endl;
		cout << "My author is: " << _author << endl;
	}
	const string &title() const { return _title; }
	const string &author() const { return _author; }

protected:
	string _title;
	string _author;

};

class AudioBook :public Book
{
public:
	AudioBook(const string &title, const string &author,const string &narrator) 
		: Book(title,author),_narrator(narrator) ////
	{
		cout << "AudioBook::AudioBook(" << _title;
		cout << ", " << _author;
		cout << ", " << _narrator;
		cout << ") constructor\n";
	}
	~AudioBook() { cout << "AudioBook::~AudioBook() destructor\n"; };
	virtual void print() const
	{
		cout << "AudioBook::print() -- I am a AudioBook object\n";
		cout << "My title is: " << _title << endl;
		cout << "My author is: " << _author << endl;
		cout << "My narrator is: " << _narrator << endl;
	}

protected:
	string _narrator;
};



void print(const LibMat &mat)
{
	cout << "in gloabl print(): about to print mat.print()\n";
	mat.print();
}

int main()
{
/*
	cout << endl << "Creating a LibMat object to print()\n";
	LibMat libmat;
	print(libmat);

	cout << endl << "Creating a Book object to print()\n";
	Book b("The Castle","Franz Kafka");
	print(b);
	
	cout << endl << "Creating a AudioBook object to print()\n";
	AudioBook ab("Man Without Qualities","Robert Musil","Kenneth Meyer");
	print(ab);
*/
	cout << endl << "Creating a Mangiaze object to print()\n";
	Mangiaze m("nature","2021-12");
	print(m);

	return 0;
}

