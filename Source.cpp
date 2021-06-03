#include<iostream>
//#include<conio.h>
#include<fstream>
using namespace std;
class posts;
class pages;
class activities;
class users;
class object
{
private:
	char*id;
public:
	object();
	object(char*ID);
	void print_obj();
	char*get_id();
	void print_id();
	virtual void printcomment()
	{
		;
	}
	virtual void printname()
	{
		;
	}
	virtual void print_activity()
	{
		;
	}
	virtual void print_discription()
	{
		;
	}
	virtual char**get_likedby()
	{
		char**a=new char*[1];
		return a;
	}
	virtual ~object();
};
object::object()
{
	id=0;
}
object::object(char*ID)
{
	id = ID;
}
void object::print_obj()
{
	cout << id;
}
char*object::get_id()
{
	return id;
}
void object::print_id()
{
	cout << id;
}
object::~object()
{
	if (id != 0)
	{
		delete[]id;
	}
}



class date
{
private:
	int day;
	int month;
	int year;
public:
	static date Currentdate;
	date(int d , int m , int y );
	void SetCurrentDate(int d, int m, int y);
	void PrintCurrentDate();
	int getday();
	int getmonth() ;
	int getyear() ;
	void printdate();
	~date();
};
date::date(int d = 0, int m = 0, int y = 0)
{
	day = d;
	month = m;
	year = y;
}
void date::SetCurrentDate(int d, int m, int y)
{
	Currentdate.day = d;
	Currentdate.month = m;
	Currentdate.year = y;
}
void date::PrintCurrentDate()
{
	cout << Currentdate.day << "/" << Currentdate.month << "/" << Currentdate.year << endl;
}
int date::getday()
{
	return day;
}
int date::getmonth()
{
	return month;
}
int date::getyear()
{
	return year;
}
void date::printdate()
{
	cout << day << "/" << month << "/" << year << endl;
}
date::~date()
{
	;
}
date date::Currentdate;
class Helper
{
public:
	static int StringLenght(char* str)  //for getting length of the string
	{
		int count = 0;
		for (int i = 0;str[i] != '\0';i++)
		{
			count++;
		}
		return count;

	}
	static char* GetStringFromBuffer(char* str) //for getting the pointer of array of perfect size
	{
		int size = StringLenght(str);
		char*temp = new char[size+1];
		int i;
		for (i = 0; str[i] != '\0'; i++)
		{
			temp[i] = str[i];
		}
		temp[i] = '\0';
		return temp;
	}
};



class pages:public object
{
private:
	char*name;
public:
	pages();
	pages(char*id, char*N) :object(id) 
	{
		name = N;
	};
	void print();
	char* get_id();
	static pages*readpagefromfile(ifstream&fin);
	void printcomment();
	void printname();
	~pages();
};
pages::pages()
{
	;
}
void pages::print()
{
	object::print_obj();
	cout<< "\t";
	for (int i = 0;name[i] != '\0';i++)
	{
		cout << name[i];
	}
	cout << endl << endl;
} 
pages*pages::readpagefromfile(ifstream&fin)
{
	char*buffer = new char[50];
	fin >> buffer;
	char*p_id = Helper::GetStringFromBuffer(buffer);
	fin.getline(buffer, 50);
	pages*ABC = new pages(p_id, buffer);
	return ABC;
}
char* pages::get_id()
{
	char*p_id = object::get_id();
	return p_id;
}
void pages::printcomment()
{
	cout << name;
	
	cout << endl;
}
void pages::printname()
{
	cout << name;
}
pages::~pages()
{
	if (name != 0)
	{
		delete[] name;
	}
}





class posts:public object
{
private:
	char*post_id;
	char*discription;
	//object*sharedby;
	//object**likedby;
	char*sharedby;
	char**likedby;
	date shareddate;
public:
	posts();
	posts(char* ID, int d, int m, int y, char* post, char* share, char** like) :object(ID),shareddate(d,m,y) {
		post_id = ID;
		discription = post;
		sharedby = share;
		likedby = like;
	};
	static posts*readuserfromfile(ifstream&fin);
	char*get_id();
	char*get_uid();
	void print_discription();
	void printcomment();
	char**get_likedby();
	~posts();
};
posts::posts()
{
	;
}
posts*posts::readuserfromfile(ifstream&fin1)
{
	char buffer[100];
	fin1 >> buffer;
	char*post_id =Helper::GetStringFromBuffer(buffer);
	int d, m, y;
	fin1 >> d;
	fin1 >> m;
	fin1 >> y;
	fin1.getline(buffer, 100);
	fin1.getline(buffer, 100);
	char*discrip = Helper::GetStringFromBuffer(buffer);
	fin1.getline(buffer, 100);
	char*sharedby = Helper::GetStringFromBuffer(buffer);
	/*object share(buffer);
	object*shared = &share;*/
	//shared->print_obj();
	//cout << endl;
	char**liked = new char*[4];
	//object**liked = new object*[4];
	int counter = 0;
	for (int i = 0;i<5;i++)
	{
		fin1 >> buffer;
		counter++;
		if (*buffer == '-')
		{
			break;
		}
		//object*frnd;
		char*frnd;
		if (counter == 0)
		{
			frnd = 0;
		}
		else
		{
			//object frend(buffer);
			frnd = Helper::GetStringFromBuffer(buffer);
		}
		liked[i] = frnd;
		//liked[i]->print_obj();
		liked[counter] = '\0';
	}
	posts*ABC = new posts(post_id, d, m, y, discrip, sharedby, liked);
	return ABC;
}
char*posts::get_id()
{
	return sharedby;
}
char*posts::get_uid()
{
	char*p_id = object::get_id();
	return p_id;
}
void posts::print_discription()
{
	cout << discription << endl;
}
void posts::printcomment()
{
	;
}
char** posts::get_likedby()
{
	return likedby;
}
posts::~posts()
{
	if(post_id != 0)
	{
		delete[] post_id;
	}
	if (discription != 0)
	{
		delete[] discription;
	}
	if (sharedby != 0)
	{
		delete[] sharedby;
	}
	if (likedby != 0)
	{
		for (int i = 0;likedby[i] != '\0';i++)
		{
			delete likedby[i];
		}
		delete[] likedby;
	}
}


class activities:public object
{
private:
	char*post_id;
	int day, month, year;
	char*discription;
	char*activity;
	/*object*sharedby;
	object**likedby;*/
	char*sharedby;
	char**likedby;
	date shareddate;
public:
	
	activities();
	activities(char* ID, int d, int m, int y, char* post, char* act, char* share, char** like) :object(ID),shareddate(d,m,y)
	{
		discription = post;
		activity = act;
		sharedby = share;
		likedby = like;
	};
	static activities*readuserfromfile(ifstream&fin1);
	char*get_id();
	char*get_uid();
	void print_activity();
	void print_discription();
	char**get_likedby();
	void printcomment();
	~activities();
	//object** likedby1(users**LHS, pages**ABC);
};
activities::activities()
{
	;
}
activities*activities::readuserfromfile(ifstream&fin1)
{
	char buffer[100];
	fin1 >> buffer;
	char*post_id = Helper::GetStringFromBuffer(buffer);
	//cout << post_id << endl;
	int d, m, y;
	fin1 >> d;
	fin1 >> m;
	fin1 >> y;
	//cout << d << " " << m << " " << y << endl;
	fin1.getline(buffer, 100);
	char*discrip = Helper::GetStringFromBuffer(buffer);
	fin1.getline(buffer, 100);
	discrip = Helper::GetStringFromBuffer(buffer);
	int activity_type;
	fin1 >> activity_type;
	fin1.getline(buffer, 50);
	char*act = Helper::GetStringFromBuffer(buffer);//Helper::GetStringFromBuffer(buffer2);
	//cout << act << endl;
	fin1.getline(buffer, 100);
	char*share = Helper::GetStringFromBuffer(buffer);//Helper::GetStringFromBuffer(buffer3);
	//cout << share << endl;
	//object share(buffer);
	//object*shared=&share;
	//shared->print_obj();
	//cout << endl;
	char**likedby = new char*[4];
	//object**liked = new object*[4];
	int counter = 0;
	for (int i = 0;i<5;i++)
	{
		fin1 >> buffer;
		counter++;
		if (*buffer == '-')
		{
			break;
		}
		char*frnd;
		if (counter = 0)
		{
			frnd = 0;
		}
		else
		{
			//object frend(buffer);
			frnd = Helper::GetStringFromBuffer(buffer);
		}
		likedby[i] = frnd;
		//cout << likedby[i];
		//liked[i]->print_obj();
	}
	likedby[counter] = '\0';
	//cout << endl << endl;
	activities*ABC = new activities(post_id, d, m, y, discrip, act, share, likedby);
	return ABC;
}
char* activities::get_id()
{
	return sharedby;
}
char*activities::get_uid()
{
	char*p_id = object::get_id();
	return p_id;
}
void activities::print_activity()
{
	cout << activity << " " << endl;
}
void activities::print_discription()
{
	cout << discription <<  endl;
}
char**activities::get_likedby()
{
	return likedby;
}
void activities::printcomment()
{
	;
}
//object**activities::likedby1(users**LHS, pages**ABC)
//{
//	object**g = new object*[4];
//	int c=0, k = 0;
//	
//		char**a = likedby;
//		if (a[0][0] == 'p')
//		{
//			for (int j = 0;a[j] != '\0';j++)
//			{
//				char*b = ABC[j]->get_id();;
//				if (a[k][1] == b[1])
//				{
//					g[k] = ABC[j];
//					k++;
//					c++;
//				}
//			} 
//		}
//		else if (a[0][0] == 'u')
//		{
//			for (int j = 0;a[j] != '\0';j++)
//			{
//				char*b = LHS[j]->get_Uid();;
//				if (a[k][1] == b[1])
//				{
//					g[k] = LHS[j];
//					k++;
//					c++;
//				}
//			}
//			
//		}
//	g[c] = '\0';
//	return g;
//}
activities::~activities()
{
	if (post_id != 0)
	{
		delete[] post_id;
	}
	if (discription != 0)
	{
		delete[] discription;
	}
	if (activity != 0)
	{
		delete[] activity;
	}
	if (sharedby != 0)
	{
		delete[] sharedby;
	}
	if (likedby != 0)
	{
		for (int i = 0;likedby[i] != '\0';i++)
		{
			delete likedby[i];
		}
		delete[] likedby;
	}
}


class comments :public object
{
private:
	char*post_id;
	char*user;
	char*text;
public:
	comments();
	comments(char*id, char*p_id, char*u_id, char*discrip) :object(id)
	{
		post_id = p_id;
		user = u_id;
		text = discrip;
	}
	static comments*readdatafromfile(ifstream&fin);
	void print()
	{
		cout << post_id << "\t" << user << "\t" << text << endl;
	}
	char*get_Uid();
	void printcomment();
	~comments();
};
comments::comments()
{
	;
}
comments*comments::readdatafromfile(ifstream&fin)
{
	char buffer[100];
	fin >> buffer;
	char*id = Helper::GetStringFromBuffer(buffer);
	fin >> buffer;
	char*post_id = Helper::GetStringFromBuffer(buffer);
	fin >> buffer;
	char*user_id = Helper::GetStringFromBuffer(buffer);
	fin.getline(buffer, 100);
	char*text = Helper::GetStringFromBuffer(buffer);
	comments*ABC= new comments(id, post_id, user_id, text);
	return ABC;

}
char*comments::get_Uid()
{
	return user;
}
void comments::printcomment()
{
	cout << text << endl;
}
comments::~comments()
{
	if (post_id != 0)
	{
		delete[] post_id;
	}
	if (user != 0)
	{
		delete[] user;
	}
	if (text != 0)
	{
		delete[]text;
	}
}

class users :public object
{
private:
	char*firstname;
	char*lastname;
	char**list_of_friends;
	char**list_of_liked_pages;
	static int size;
	pages**s_page;
	users**s_friend;
	object*sharedby;

	//object*sharedby;
	//object**likedby;

public:
	users();
	users(char*identity, char*fname, char*lname, char**friends, char**pages) :object(identity)
	{
		firstname = fname;
		lastname = lname;
		list_of_friends = friends;
		list_of_liked_pages = pages;
	}
	~users();
	void print();
	static users*readuserfromfile(ifstream&fin);
	pages**set_pages(pages**RHS)
	{
		s_page = new pages*[5];
		int k = 0;
		int flag = 0;
		for (int i = 0;i < 12;i++)
		{
			char*id = RHS[i]->get_id();
			for (int j = 0;j < 2;j++)
			{
				if (id[j] == list_of_liked_pages[k][j])
				{
					flag = 1;
				}
				else
					flag = 0;
			}
			if (flag == 1)
			{
				s_page[k] = RHS[i];
				k++;
			}
		}
		s_page[k] = '\0';
		return s_page;
	}
	users**set_friend(users**RHS)
	{
		s_friend = new users*[5];
		int k = 0;
		int flag = 0;
		for (int i = 0;i < 20;i++)
		{
			char*id = RHS[i]->get_Uid();
			for (int j = 0;j < 2;j++)
			{
				if (id[j] == list_of_friends[k][j])
				{
					flag = 1;
				}
				else
					flag = 0;

			}
			if (flag == 1)
			{
				s_friend[k] = RHS[i];
				k++;
			}
		}
		s_friend[k] = '\0';
		return s_friend;
	}
	void printname();
	void print_id();
	char*get_Uid();
	static object** sharedby1(activities**&RHS, users**LHS, pages**ABC);
	static object** sharedby2(posts**RHS, users**LHS, pages**ABC);
	//char** likedby1(activities**RHS, users**LHS, pages**ABC);
	//char** likedby2(posts**RHS, users*LHS);
	static object**print_comments(comments**RHS,users**LHS, pages**ABC);
	void printcomment();
	object* sharedby_1(activities**RHS, users*LHS);
	object* sharedby_2(posts**RHS, users*LHS);
};
users::users()
{
	;
}
void users::printname()
{
	cout << firstname << " " << lastname;
}
void users::print_id()
{
	object::print_obj();
}
users*users::readuserfromfile(ifstream&fin)
{
	char buffer[50];
	fin >> buffer;
	char*id = Helper::GetStringFromBuffer(buffer);
	fin >> buffer;
	char*fname = Helper::GetStringFromBuffer(buffer);
	fin >> buffer;
	char*lname = Helper::GetStringFromBuffer(buffer);
	char**list_friend = new char*[10];
	for (int i = 0;i < 10;i++)
	{
		list_friend[i] = new char;
	}
	for (int i = 0;i<10;i++)
	{
		fin >> buffer;
		if (*buffer == '-')
		{
			break;
		}

		char*frnd = Helper::GetStringFromBuffer(buffer);
		list_friend[i] = frnd;
	}
	char**list_pages = new char*[10];
	for (int i = 0;i < 10;i++)
	{
		list_pages[i] = new char;
	}
	for (int i = 0;i<10;i++)
	{
		fin >> buffer;
		if (*buffer == '-')
		{
			break;
		}

		char*page = Helper::GetStringFromBuffer(buffer);
		list_pages[i] = page;
	}
	users*ABC = new users(id, fname, lname, list_friend, list_pages);
	return ABC;
}
void users::print()
{
	object::print_obj();
	cout << "-" << firstname << " " << lastname << endl;
}
char*users::get_Uid()
{
	char*p_id = object::get_id();
	return p_id;
}
object**users::sharedby1(activities**&RHS, users**LHS, pages**ABC)			//all sharing of activities by user
{
	int c1 = 0, c2 = 0, c = 0;
	object**d = new object*[7];
	for (int i = 0;i < 7;i++)
	{
		d[i] = new object;
	}
	for (int i = 0;i < 7;i++)
	{
		char*id_t = RHS[i]->get_id();
		//cout << id_t<<endl;
		if (id_t[0] == 'u')
		{
			for (int j = 0;j < 20;j++)
			{
				char*a = LHS[j]->get_Uid();
				c1++;
				if (a[1] == id_t[1])
				{
					d[c] = LHS[j];
					c++;
					break;
				}
			}
		}
		else if (id_t[0] == 'p')
		{
			for (int j = 0;j < 12;j++)
			{
				char*b = ABC[j]->get_id();
				c1++;
				if (b[1] == id_t[1])
				{
					d[c] = ABC[j];
					c++;
					break;
				}
			}
		}
	}
	return d;
}
object**users::sharedby2(posts**RHS, users**LHS, pages**ABC)					//all sharing of post  by user
{
	int c1 = 0, c2 = 0, c = 0;
	object**d = new object*[3];
	for (int i = 0;i < 3;i++)
	{
		char*id_t = RHS[i]->get_id();
		//cout << id_t<<endl;
		if (id_t[0] == 'u')
		{
			for (int j = 0;j < 20;j++)
			{
				char*a = LHS[j]->get_Uid();
				c1++;
				if (a[1] == id_t[1])
				{
					d[c] = LHS[j];
					c++;
					break;
				}
			}
		}
		else if (id_t[0] == 'p')
		{
			for (int j = 0;j < 12;j++)
			{
				char*b = ABC[j]->get_id();
				c1++;
				if (b[1] == id_t[1])
				{
					d[c] = ABC[j];
					c++;
					break;
				}
			}
		}
	}
	return d;
}		
object* users::sharedby_1(activities**RHS, users*LHS)				//shared activities and post by user
{
	int flag = 0;
	sharedby = new object;
	char*id = LHS->get_Uid();
	for (int i = 0;i < 7;i++)
	{
		char*id_t = RHS[i]->get_id();
		for (int j = 0;j < 2;j++)
		{
			if (id[j] == id_t[j])
			{
				flag = 1;
			}
			else
				flag = 0;
		}
		if (flag == 1)
		{
			sharedby = RHS[i];
			return sharedby;
			break;
		}
	}
	return 0;
}
object* users::sharedby_2(posts**RHS, users*LHS)						//shared post by user
{
	int flag = 0;
	sharedby = new object;
	char*id = LHS->get_Uid();
	for (int i = 0;i < 3;i++)
	{
		char*id_t = RHS[i]->get_id();
		for (int j = 0;j < 2;j++)
		{
			if (id[j] == id_t[j])
			{
				flag = 1;
			}
			else
				flag = 0;
		}
		if (flag == 1)
		{
			sharedby = RHS[i];
			return sharedby;
			break;
		}
	}
	return 0;
}
//char**users::likedby2(posts**RHS, users*LHS)
//{
//	int flag = 0;
//	sharedby = new object;
//	char*id = LHS->get_Uid();
//	for (int i = 0;i < 3;i++)
//	{
//		char*id_t = RHS[i]->get_id();
//		for (int j = 0;j < 2;j++)
//		{
//			if (id[j] == id_t[j])
//			{
//				flag = 1;
//			}
//			else
//				flag = 0;
//		}
//		if (flag == 1)
//		{
//			sharedby = RHS[i];
//			break;
//		}
//	}
//	char**a = sharedby->get_likedby();
//	return a;
//}
//char**users::likedby1(activities**RHS, users**LHS,pages**ABC)
//{
//	object**a = new object*[5];
//	int c=0, k = 0;
//	char*id = f->get_Uid();
//	char**b = RHS->get_2d_id();
//	for (int i = 0;b[i]!='\0';i++)
//	{
//		if (b[i][0] == 'p')
//		{
//			for (int j = 0;j < 11;j++)
//			{
//				char*c = ABC[j]->get_id();;
//				if (b[k][1] == c[1])
//				{
//					a[k] = ABC[j];
//					k++;
//					c++;
//					break;
//				}
//			}
//		}
//		else if (b[i][0] == 'u')
//		{
//			for (int j = 0;j<20;j++)
//			{
//				char*c = LHS[j]->get_Uid();;
//				if (b[k][1] == c[1])
//				{
//					a[k] = LHS[j];
//					k++;
//					c++;
//					break;
//				}
//			}
//		}
//	}
//	a[k] = '\0';
//	return a;
//}
users::~users()
{
	if (firstname != 0)
	{
		delete[]firstname;
	}
	if (lastname != 0)
	{
		delete[]lastname;
	}
	if (list_of_friends != 0)
	{
		/*for (int i = 0;list_of_friends[i] != '\0';i++)
		{
			delete list_of_friends[i];
		}*/
		delete [] list_of_friends;
	}
	if (list_of_liked_pages != 0)
	{
		/*for (int i = 0;list_of_liked_pages[i] != '\0';i++)
		{
			delete list_of_liked_pages[i];
		}*/
		delete[]list_of_liked_pages;
	}
	if (s_page != 0)
	{
		for (int i = 0;s_page[i] != '\0';i++)
		{
			delete s_page[i];
		}
		delete[] s_page;
	}
	if (s_friend != 0)
	{
		/*for (int i = 0;s_friend[i] != '\0';i++)
		{
			delete s_friend[i];
		}*/
		delete[] s_friend;
	}
	if (sharedby != 0)
	{
		delete[] sharedby;
	}
}

object**users::print_comments(comments**RHS, users**LHS, pages**ABC)			//for getting ids who posted comments
{
	int c = 0;
	object**a = new object*[12];
	for (int i = 0;i < 12;i++)
	{
		char*id = RHS[i]->get_Uid();
		if (id[0] == 'u')
		{
			for (int j = 0;j < 20;j++)
			{
				char*id_u = LHS[j]->get_Uid();
				if (id[1] == id_u[1])
				{
					a[c] = LHS[j];
					c++;
					break;
				}
			}
		}
		else if (id[0] == 'p')
		{
			for (int j = 0;j < 12;j++)
			{
				char*id_p = ABC[j]->get_id();
				if (id[1] == id_p[1])
				{
					a[c] = ABC[j];
					c++;
					break;
				}
			}
		}
	}
	return a;
}

void users::printcomment()
{
	cout << firstname << " " << lastname;
}


class facebook
{
private:
	users** user;
	pages** page;
	char**arr1;
	char**arr2;
	posts**postptr;
	activities**actptr;
	comments**comment;
public:
	facebook();
	facebook(users**U, pages**P);
	void loaddata();
	void run_data();
	~facebook();
};
facebook::facebook()
{
	;
}
facebook::facebook(users**U, pages**P)
{
	user = U;
	page = P;
}
void facebook::loaddata()								//reading data from files
{
	ifstream fin;
	fin.open("users.txt");
	int size;
	fin >> size;
	user = new users*[size];
	for (int i = 0;i < size;i++)
	{
		user[i] = users::readuserfromfile(fin);
	}
	////////////////////////////////////////////
	ifstream gin;
	gin.open("pages.txt");
	int s_pages;
	gin >> s_pages;
	page = new pages*[size];
	for (int i = 0;i < s_pages;i++)
	{
		page[i] = pages::readpagefromfile(gin);
	}
	/////////////////////////////////////////////////////////
	ifstream fin1;
	fin1.open("posts.txt");
	int size_1;
	fin1 >> size_1;
	int c1 = 0, c2 = 0;
	postptr = new posts*[size_1];
	actptr = new activities*[size_1];
	int type;
	for (int i = 0;i < size_1;i++)
	{
		fin1 >> type;
		if (type == 1)
		{
			postptr[c1] = posts::readuserfromfile(fin1);
			c1++;
		}
		if (type == 2)
		{
			actptr[c2] = activities::readuserfromfile(fin1);
			c2++;
		}
	}
	///////////////////////////////////////////////////////
	ifstream fin2;
	fin2.open("comments.txt");
	int size_2;
	fin2 >> size_2;
	comment = new comments*[size_2];
	for (int i = 0;i < size_2;i++)
	{
		comment[i]=comments::readdatafromfile(fin2);
	}
}						
void facebook::run_data()								//printing
{
			cout << "Command :    Set current user ";
			user[6]->print_id();
			cout << endl;
			user[6]->printname();
			cout << " successfully set as a curent user" << endl;
			cout << "Command :           Set Current Date    ";
			date dates(15, 11, 2017);
			dates.printdate();
			cout << endl;
			cout << "Command :            View Friend List" << endl;
			cout << "----------------------------------------" << endl;
			user[6]->printname();
			cout << "-Friend List" << endl;
			users**friend_list = user[5]->set_friend(user);

			for (int j = 0;friend_list[j] != '\0';j++)
			{
				friend_list[j]->print();
			}
			cout << "------------------------------------------" << endl;

			cout << "Command :			View Liked pages " << endl;
			cout << "----------------------------------------" << endl;
			user[6]->printname();
			cout << "-Liked Pages " << endl;
			pages**pages_list = user[5]->set_pages(page);
			for (int j = 0;pages_list[j] != '\0';j++)
			{
				pages_list[j]->print();
			}
			cout << "Command :			View Liked pages " << endl;
			cout << "----------------------------------------" << endl;
			object*a = user[6]->sharedby_1(actptr, user[6]);
			object*b = user[6]->sharedby_2(postptr, user[6]);
			if (a != 0)
			{
				user[6]->printname();
				cout << " is excited about ";
				a->print_activity();
				cout << endl;
				user[6]->printname();
				cout << " shared ";
				a->print_discription();
			
				//char**c = user[i]->likedby1(actptr, user[i]);
			/*	for (int i = 0;c[i] != '\0';i++)
				{
					cout << c[i] << endl;
				}*/
			}
			if (b != 0)
			{
				user[6]->printname();
				cout << " shared ";
				b->print_discription();
				cout << endl;
				//char**d = user[i]->likedby2(postptr, user[i]);
			
				/*for (int i = 0;d[i] != '\0';i++)
				{
					cout << d[i] << endl;
				}*/
			}
			cout << "------------------------------------------" << endl;
		
		/*if(a==2)
		{
			object**b = users::print_comments(comment, user, page);
			for (int i = 0;i < 12;i++)
			{
				b[i]->printname();
				cout << " commented";
				comment[i]->printcomment();
			}
		}*/
		/*object**activitiesptr = users::sharedby1(actptr, user, page);
		for (int i = 0;i < 7;i++)
		{
			activitiesptr[i]->printname();
			cout << " is excited about ";
			actptr[i]->print_activity();
			activitiesptr[i]->printname();
			cout << " shared ";
			actptr[i]->print_discription();
		}
		object**postsptr = users::sharedby2(postptr, user, page);
		for (int i = 0;i < 3;i++)
		{
			postsptr[i]->printname();
			cout << " shared ";
			postptr[i]->print_discription();
		}*/
	
}	
facebook::~facebook()								//destructor
{
	if (user != 0)
	{
		for (int i = 0;user[i] != '\0';i++)
		{
			delete user[i];
		}
		delete[]user;
	}
	if (page != 0)
	{

		for (int i = 0;page[i] != '\0';i++)
		{
			delete page[i];
		}
		delete[]page;
	}
	if (arr1 != 0)
	{

		for (int i = 0;arr1[i] != '\0';i++)
		{
			delete arr1[i];
		}
		delete[] arr1;
	}
	if (arr2 != 0)
	{

		for (int i = 0;arr2[i] != '\0';i++)
		{
			delete arr2[i];
		}
		delete[]arr2;
	}
	if (postptr != 0)
	{

		for (int i = 0;postptr[i] != '\0';i++)
		{
			delete postptr[i];
		}
		delete[] postptr;
	}
	if (actptr != 0)
	{

		for (int i = 0;actptr[i] != '\0';i++)
		{
			delete actptr[i];
		}
		delete[] actptr;
	}
	if (comment != 0)
	{

		for (int i = 0;comment[i] != '\0';i++)
		{
			delete comment[i];
		}
		delete[] comment;
	}
}
int main()
{
	facebook fb;
	fb.loaddata();
	fb.run_data();
	//_getch();
}