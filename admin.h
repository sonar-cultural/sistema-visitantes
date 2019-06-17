// Lists all visitors based on root visitor
void list_visitors(struct visitor *root);

// Prints the visitors amount of the month
void visitors_per_month(struct visitor *root, int month);

// Scans and return the month the user chose
int get_month();

// Prints an age histogram of the visitors
void get_histogram(int amount_visitors, struct visitor *root);