typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);
int add(ArrayList *list,void *data);
int remove(ArrayList *list,int index);

int getLength(ArrayList *list);
void* get(ArrayList *list, int index);

void dispose(ArrayList *list);