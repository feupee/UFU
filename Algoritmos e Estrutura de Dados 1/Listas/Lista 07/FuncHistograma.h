#define MAX_TEXT_SIZE 2000
#define NUM_CHARS 256

typedef struct {
    int count[NUM_CHARS];
} Histogram;

void initializeHistogram(Histogram *hist);

void updateHistogram(Histogram *hist, const char *text);

void printHistogram(const Histogram *hist);