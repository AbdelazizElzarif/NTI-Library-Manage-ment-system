#define BOOK_MAX 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_STATUS 100
typedef struct
{
	char BOOK_TITLE[MAX_TITLE];
	char AUTHOR_NAME[MAX_AUTHOR];
	int puplication_year;
	int NUMPER_COPIES;
	float PRICE;
	char STATUS[MAX_STATUS];
	
}Library;

void string_scan(char* str,char size);
char string_same(char*str1,char* str2);
void string_print(char* str);
void string_copy(char*str1,char*str2);
void book_avalibale(char*str1);
void book_notavalibale(char*str1);
char book_add(Library*book);
void print_library(void);
char BORROW_BOOK(void);
char DELET_BOOK(void);
char Buy_BooK(void);
void show_menu(void);
void exit2(void);
int getter_gf(void);
void Library_init(void);
void Library_runaable(void);