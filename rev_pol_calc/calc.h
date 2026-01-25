#define NUMBER '0'
enum {MAXVAL = 100};

extern int sp;
extern double val[MAXVAL];
extern int pos;
extern char input[];


void push(double f);
double pop(void);
double print_stack(void);
void duplicate_element(void);
void duplicate_element(void);
void swap_elements(void);
void clear_stack(void);
int getop(char *s);