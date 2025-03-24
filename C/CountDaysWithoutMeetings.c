/* TLE for 10^9 lol
int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    int* arr = calloc(days, sizeof(int));

    // 1 = [
    // 2 = ]
    int i;
    for (i = 0; i < meetingsSize; i++){
        arr[meetings[i][0]-1] = 1;
        arr[meetings[i][1]-1] = 2;
    }

    int ret = 0;
    int openCount = 0;
    for (i = 0; i<days; i++){
        if (arr[i] == 1) openCount++;
        else if (arr[i] == 2) openCount--;
        else if (openCount == 0) ret++;
    }

    return ret;
} */

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int cmpMeeting(const void* a, const void* b) {
    int* meetingA = *(int**)a;
    int* meetingB = *(int**)b;
    return meetingA[0] - meetingB[0];
}

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), cmpMeeting);

    int prevEnd = 0;
    for (int i = 0; i < meetingsSize; i++) {
        int start = MAX(meetings[i][0], prevEnd + 1);
        int length = meetings[i][1] - start + 1;
        if (length < 0) length = 0;
        days -= length;
        prevEnd = MAX(prevEnd, meetings[i][1]);
    }
    
    return days;
}
