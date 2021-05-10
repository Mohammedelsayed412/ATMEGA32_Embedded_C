#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef signed int int32_t;
typedef struct client
{
	char mail[30];
	char phone[11];
	int32_t id;
	char name[10];

}client_n;

int32_t main(void);
void get_data(char* file_name);
void display(void);
void add_element(client_n new_client);
void edit_element(void);
void delete_element(void);
void search_name(void);
void search_phone(void);
void save(void);

#endif // HEADER_H_INCLUDED
